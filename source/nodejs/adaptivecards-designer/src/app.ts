import * as Clipboard from "clipboard";
import * as Adaptive from "adaptivecards";
import * as Controls from "adaptivecards-controls";
import * as Constants from "./constants";
import * as Designer from "./card-designer";
import * as Utils from "./utils";
import { HostContainer } from "./containers/host-container";
import { OutlookContainer } from "./containers/outlook-container";
import { CortanaContainer } from "./containers/cortana-container";
import { SkypeContainer } from "./containers/skype-container";
import { TeamsContainer } from "./containers/teams-container";
import { TimelineContainer } from "./containers/timeline-container";
import { WebChatContainer } from "./containers/webchat-container";
import { ToastContainer } from "./containers/toast-container";
import { BotFrameworkContainer } from "./containers/bf-image-container";
import { adaptiveCardSchema } from "./adaptive-card-schema";
import Treeview from "./components/treeview";
import FullScreenHandler from "./components/fullscreenhandler";

declare var monacoEditor: any;
declare function loadMonacoEditor(schema, callback);

var isMonacoEditorLoaded: boolean = false;

function monacoEditorLoaded() {
    document.getElementById("loadingEditor").remove();

    monacoEditor.onDidChangeModelContent(
        function (e) {
            scheduleCardRefresh();
        });
    document.querySelector(".monaco-editor").insertAdjacentHTML("afterbegin", "<div class='jsonEditorHost-title'>JSON</div>");
    isMonacoEditorLoaded = true;

    updateJsonFromCard();
}

var jsonUpdateTimer: NodeJS.Timer;
var cardUpdateTimer: NodeJS.Timer;
var updateLayoutTimer: NodeJS.Timer;

var preventCardUpdate: boolean = false;

function updateJsonFromCard() {
    try {
        preventCardUpdate = true;

        if (!preventJsonUpdate && isMonacoEditorLoaded) {
            monacoEditor.setValue(JSON.stringify(app.card.toJSON(), null, 4));
            app.buildTreeViewSheet(app.designer.selectedPeer);
        }
    }
    finally {
        preventCardUpdate = false;
    }
}

function scheduleJsonUpdate() {
    clearTimeout(jsonUpdateTimer);

    if (!preventJsonUpdate) {
        jsonUpdateTimer = setTimeout(updateJsonFromCard, 100);
    }
}

var preventJsonUpdate: boolean = false;

function updateCardFromJson() {
    try {
        preventJsonUpdate = true;

        if (!preventCardUpdate && isMonacoEditorLoaded) {
            app.card.parse(JSON.parse(monacoEditor.getValue()));
            app.designer.render();
            app.buildTreeViewSheet(app.designer.selectedPeer);
        }
    }
    finally {
        preventJsonUpdate = false;
    }
}

function scheduleCardRefresh() {
    clearTimeout(cardUpdateTimer);

    if (!preventCardUpdate) {
        cardUpdateTimer = setTimeout(updateCardFromJson, 200);
    }
}

function updateDesignerLayout() {
    app.designer.updateLayout(false);
}

function scheduleLayoutUpdate() {
    clearTimeout(updateLayoutTimer);

    updateLayoutTimer = setTimeout(updateDesignerLayout, 50);
}

// Monaco loads asynchronously via a call to require() from index.html
// App initialization needs to happen after.
declare function loadMonacoEditor(schema: any, callback: () => void);

class PaletteItem extends Designer.DraggableElement {
    protected internalRender(): HTMLElement {
        let element = document.createElement("li");
        element.className = `aside-item aside-item__icon aside-item__icon--${Utils.sanitizeString(this.typeRegistration.typeName)}`;
        element.innerText = this.typeRegistration.typeName;

        return element;
    }

    readonly typeRegistration: Adaptive.ITypeRegistration<Adaptive.CardElement>;

    constructor(typeRegistration: Adaptive.ITypeRegistration<Adaptive.CardElement>) {
        super();

        this.typeRegistration = typeRegistration;
    }

    cloneElement(): HTMLElement {
        return this.internalRender();
    }

    createPeer(): Designer.CardElementPeer {
        var peer = Designer.CardDesigner.cardElementPeerRegistry.createPeerInstance(null, this.typeRegistration.createInstance());
        peer.initializeCardElement();

        return peer;
    }
}

class DesignerApp {
    private _designer: Designer.CardDesigner;
    private _designerHostElement: HTMLElement;
    private _paletteHostElement: HTMLElement;
    private _draggedPaletteItem: PaletteItem;
    private _draggedElement: HTMLElement;
    private _currentMousePosition: Designer.IPoint;
    private _card: Adaptive.AdaptiveCard;
    private _hostContainerPicker: Controls.DropDown;
    private _selectedHostContainer: HostContainer;
    private _treeViewComponent: Treeview;

    public buildTreeViewSheet(peer: Designer.DesignerPeer) {
        if (this.treeViewSheetHostElement) {
            let treeview = this.treeViewSheetHostElement.getElementsByClassName("treeview-items")[0];
            treeview.innerHTML = "";

            const items = [...this._card.getItems(), ...this._card.getActions()];
            this._treeViewComponent.updateDesigner(this._designer);
            const listItems = this._treeViewComponent.generateTreeViewElements(items, peer);
            treeview.appendChild(listItems);
        }
    }

    private buildPropertySheet(peer: Designer.DesignerPeer) {
        let properties = document.getElementsByClassName("js-properties-items")[0];
        if (this.propertySheetHostElement) {
            properties.innerHTML = "";

            let card: Adaptive.AdaptiveCard;

            if (peer) {
                card = peer.buildPropertySheetCard();
            }
            else {

                card = new Adaptive.AdaptiveCard();
                card.parse(
                    {
                        type: "AdaptiveCard",
                        version: "1.0",
                        body: [
                            {
                                type: "TextBlock",
                                wrap: true,
                                size: "medium",
                                text: "**Nothing is selected**"
                            },
                            {
                                type: "TextBlock",
                                wrap: true,
                                text: "Select an element in the card to modify its properties."
                            }
                        ]
                    }
                );
            }

            properties.appendChild(card.render());
            let cardNodes = card.renderedElement.children;
            (cardNodes[0] as HTMLElement).style.backgroundColor = "transparent";

            for (let element = 0; element < cardNodes.length; element++) {
                (cardNodes[element] as HTMLElement).className += " wrapper";
             }
        }
    }

    private buildPalette() {
        if (this.paletteHostElement) {
            this.paletteHostElement.innerHTML = "";

            let sortedRegisteredTypes = {};

            const categoriesMap = {
                cardElements: {
                    title: "Card Elements",
                    items: ["TextBlock", "Image"]
                },
                container: {
                    title: "Container",
                    items: ["Container", "ColumnSet", "Column", "FactSet", "Fact", "ImageSet"]
                },
                actions: {
                    title: "Actions",
                    items: ["Action.OpenUrl", "Action.Submit", "Action.ShowCard"]
                },
                inputs: {
                    title: "Inputs",
                    items: ["Input.Text", "Input.Number", "Input.Date", "Input.Time", "Input.Toggle", "Input.ChoiceSet", "Input.Choice"]
                }
            }

            let categoriesMapKeys = Object.keys(categoriesMap);
            for (let i = 0; i < categoriesMapKeys.length; i++) {
                const category = categoriesMapKeys[i];
                const categoryItems = categoriesMap[category].items;
                for (let j = 0; j < categoryItems.length; j++) {
                    let item = categoryItems[j];
                    let itemType = Adaptive.AdaptiveCard.elementTypeRegistry.getItems().find(elementType => {
                        return elementType.typeName === item;
                    });
                    if (typeof itemType !== "undefined") {
                        sortedRegisteredTypes[category] = sortedRegisteredTypes[category] || {};
                        sortedRegisteredTypes[category].title = sortedRegisteredTypes[category].title || categoriesMap[category].title;
                        sortedRegisteredTypes[category].items = Array.isArray(sortedRegisteredTypes[category].items) ? [...sortedRegisteredTypes[category].items, itemType] : [itemType];
                    }
                }
            }

            Object.keys(sortedRegisteredTypes).forEach(objectKey => {
                let node = document.createElement('li');
                node.innerText = sortedRegisteredTypes[objectKey].title;
                node.className = "aside-title";
                this.paletteHostElement.appendChild(node);

                for (var i = 0; i < sortedRegisteredTypes[objectKey].items.length; i++) {
                    var paletteItem = new PaletteItem(sortedRegisteredTypes[objectKey].items[i]);
                    paletteItem.render();
                    paletteItem.onStartDrag = (sender: PaletteItem) => {
                        this._draggedPaletteItem = sender;

                        this._draggedElement = sender.cloneElement();
                        this._draggedElement.style.position = "absolute";
                        this._draggedElement.style.left = this._currentMousePosition.x + "px";
                        this._draggedElement.style.top = this._currentMousePosition.y + "px";

                        document.body.appendChild(this._draggedElement);
                    }

                    this.paletteHostElement.appendChild(paletteItem.renderedElement);
                }
            });
        }
    }

    private endDrag() {
        if (this._draggedPaletteItem) {
            this._draggedPaletteItem.endDrag();
            this._draggedElement.remove();

            this._draggedPaletteItem = null;
            this._draggedElement = null;
        }
    }

    private addContainers() {
        this.hostContainers.push(new WebChatContainer("Bot Framework WebChat", "css/webchat-container.css"));
        this.hostContainers.push(new CortanaContainer("Cortana Skills", "css/cortana-container.css"));
        // this.hostContainers.push(new TimelineContainer("Windows Timeline", "css/timeline-container.css")); This element overflows it's container and can't fit the content
        this.hostContainers.push(new SkypeContainer("Skype (Preview)", "css/skype-container.css"));
        this.hostContainers.push(new OutlookContainer("Outlook Actionable Messages", "css/outlook-container.css"));
        this.hostContainers.push(new TeamsContainer("Microsoft Teams (Preview)", "css/teams-container.css"));
        this.hostContainers.push(new ToastContainer("Windows Notifications (Preview)", "css/toast-container.css"));
        this.hostContainers.push(new BotFrameworkContainer("Bot Framework Other Channels (Image render)", "css/bf-image-container.css"));
    }

    private recreateDesigner() {
        var styleSheetLinkElement = <HTMLLinkElement>document.getElementById("adaptiveCardStylesheet");

        if (styleSheetLinkElement == null) {
            styleSheetLinkElement = document.createElement("link");
            styleSheetLinkElement.id = "adaptiveCardStylesheet";

            document.getElementsByTagName("head")[0].appendChild(styleSheetLinkElement);
        }

        styleSheetLinkElement.rel = "stylesheet";
        styleSheetLinkElement.type = "text/css";
        styleSheetLinkElement.href = this._selectedHostContainer.styleSheet;

        this._selectedHostContainer.initialize();

        this._designerHostElement.innerHTML = "";
        this._selectedHostContainer.renderTo(this._designerHostElement);

        this._designer = new Designer.CardDesigner(this._selectedHostContainer.cardHost);
        this._designer.onSelectedPeerChanged = (peer: Designer.CardElementPeer) => {
            this.buildPropertySheet(peer);
            this.buildTreeViewSheet(peer);
        };
        this._designer.onLayoutUpdated = (isFullRefresh: boolean) => {
            if (isFullRefresh) {
                scheduleJsonUpdate();
            }
        };

        this.buildPalette();
        this.buildPropertySheet(null);
        this.buildTreeViewSheet(null);

        if (this._card) {
            this._card.hostConfig = this._selectedHostContainer.getHostConfig();
        }

        this._designer.card = this._card;
    }

    private selectedHostContainerChanged() {
        this.recreateDesigner();
    }

    readonly hostContainers: Array<HostContainer> = [];

    propertySheetHostElement: HTMLElement;
    treeViewSheetHostElement: HTMLElement;
    commandListHostElement: HTMLElement;

    constructor(designerHostElement: HTMLElement) {
        this._designerHostElement = designerHostElement;

        this.addContainers();

        this._selectedHostContainer = this.hostContainers[0];

        this.recreateDesigner();
        this._treeViewComponent = new Treeview();
    }

    createContainerPicker(): Controls.DropDown {
        this._hostContainerPicker = new Controls.DropDown();

        for (var i = 0; i < this.hostContainers.length; i++) {
            let item = new Controls.DropDownItem(i.toString(), this.hostContainers[i].name);

            this._hostContainerPicker.items.add(item);
        }

        this._hostContainerPicker.selectedIndex = 0;
        this._hostContainerPicker.onValueChanged = (sender: Controls.InputControl) => {
            this._selectedHostContainer = this.hostContainers[Number.parseInt(this._hostContainerPicker.value.key)];

            this.selectedHostContainerChanged();
        }

        return this._hostContainerPicker;
    }

    handlePointerMove(e: PointerEvent) {
        this._currentMousePosition = { x: e.x, y: e.y };

        let isPointerOverDesigner = this.designer.isPointerOver(this._currentMousePosition.x, this._currentMousePosition.y);
        let peerDropped = false;

        if (this._draggedPaletteItem && isPointerOverDesigner) {
            let peer = this._draggedPaletteItem.createPeer();

            let clientCoordinates = this.designer.pageToClientCoordinates(this._currentMousePosition.x, this._currentMousePosition.y);

            if (this.designer.tryDrop(clientCoordinates, peer)) {
                this.endDrag();

                this.designer.startDrag(peer);

                peerDropped = true;
            }
        }

        if (!peerDropped && this._draggedElement) {
            this._draggedElement.style.left = this._currentMousePosition.x - 10 + "px";
            this._draggedElement.style.top = this._currentMousePosition.y - 10 + "px";
        }
    }

    handlePointerUp(e: PointerEvent) {
        this.endDrag();
        this.designer.endDrag();
    }

    private handleClosePanel(panelType: string): void {
        const typeOfPanel = document.querySelector(`.js-${panelType}-menu`);
        let description = document.querySelector(`.js-${panelType}-description`);
        let aside = document.querySelector(".js-aside-panel");

        if (aside.childNodes.length === 0) {
            document.querySelector(`.js-${panelType}-bullet`).addEventListener("click", () => {
                description.innerHTML = "";
                const elementNode = typeOfPanel.cloneNode(true);
                elementNode.addEventListener("click", () => {
                    description.innerHTML = "Hide";
                    this.openPanel(panelType);
                });
                aside.classList.add("is-active");
                aside.appendChild(elementNode);

                (document.querySelector(`.js-${panelType}`) as HTMLElement).style.display = "none";
                (document.querySelector(`.js-${panelType}-splitter`) as HTMLElement).style.display = "none";
            });
        }
    }

    private openPanel(panelType: string): void {
        if (document.querySelector(".js-aside-panel").hasChildNodes()) {
            let foldedPanel = document.querySelector(`.js-aside-panel.is-active > .js-${panelType}-menu`);
            let aside = document.querySelector(".js-aside-panel");

            (document.querySelector(`.js-${panelType}`) as HTMLElement).style.display = "block";
            (document.querySelector(`.js-${panelType}-splitter`) as HTMLElement).style.display = "block";
            foldedPanel.remove();

            if (aside.childNodes.length === 0) {
                (aside as HTMLElement).classList.toggle("is-active");
            }
        }
    }

    public cloneNodesTrees(): void {
        this.handleClosePanel("treeview");
        this.handleClosePanel("properties");
    }

    private toggleAside():void {
        document.querySelector(".js-aside-bullet").addEventListener("click", () => {
            const aside = document.querySelector(".js-aside");
            aside.classList.toggle("is-toggled");

            const items = document.querySelector(".js-aside-items");
            items.classList.toggle("is-hidden");

            const icon = document.querySelector(".js-aside-icon");
            icon.classList.toggle("icon--expand");

            const description = document.querySelector(".js-aside-description");
            description.classList.toggle("is-hidden");
        })
    }

    public togglePanels(): void {
        this.toggleAside();
    }

    get paletteHostElement(): HTMLElement {
        return this._paletteHostElement;
    }

    set paletteHostElement(value: HTMLElement) {
        if (this._paletteHostElement != value) {
            this._paletteHostElement = value;
        }
    }

    get card(): Adaptive.AdaptiveCard {
        return this._card;
    }

    set card(value: Adaptive.AdaptiveCard) {
        if (this._card != value) {
            if (this._card) {
                this._card.designMode = false;
            }

            this._card = value;

            if (this._card) {
                this._card.designMode = true;
                this._card.hostConfig = this._selectedHostContainer.getHostConfig();
            }

            this.recreateDesigner();
        }
    }

    get designer(): Designer.CardDesigner {
        return this._designer;
    }
}

class Splitter {
    private _splitterElement: HTMLElement;
    private _sizedELement: HTMLElement;
    private _isPointerDown: boolean;
    private _lastClickedOffset: Designer.IPoint;

    private pointerDown(e: PointerEvent) {
        e.preventDefault();

        this._splitterElement.setPointerCapture(e.pointerId);

        this._lastClickedOffset = { x: e.x, y: e.y };

        this._isPointerDown = true;
    }

    private pointerMove(e: PointerEvent) {
        if (this._isPointerDown) {
            e.preventDefault();

            if (this.isVertical) {
                this._sizedELement.style.width = (this._sizedELement.getBoundingClientRect().width - (e.x - this._lastClickedOffset.x)) + "px";
            }
            else {
                this._sizedELement.style.height = (this._sizedELement.getBoundingClientRect().height - (e.y - this._lastClickedOffset.y)) + "px";
            }

            if (this.onRezized) {
                this.onRezized(this);
            }

            this._lastClickedOffset = { x: e.x, y: e.y };
        }
    }

    private pointerUp(e: PointerEvent) {
        e.preventDefault();

        this._splitterElement.releasePointerCapture(e.pointerId);

        this._isPointerDown = false;
    }

    onRezized: (sender: Splitter) => void;

    isVertical: boolean = false;

    constructor(splitterElement: HTMLElement, sizedElement: HTMLElement) {
        this._splitterElement = splitterElement;
        this._sizedELement = sizedElement;

        this._splitterElement.onmousedown = (e: MouseEvent) => {e.preventDefault(); };
        this._splitterElement.onpointerdown = (e: PointerEvent) => { this.pointerDown(e); };
        this._splitterElement.onpointermove = (e: PointerEvent) => { this.pointerMove(e); };
        this._splitterElement.onpointerup = (e: PointerEvent) => { this.pointerUp(e); };
    }
}

var app: DesignerApp;
var horizontalSplitter: Splitter;
var propertyVerticalSplitter: Splitter;
var treeViewVerticalSplitter: Splitter;

window.onload = () => {
    const fullScreenHandler = new FullScreenHandler(document.querySelector(".js-enter-fullscreen"));
    fullScreenHandler.init();

    new Clipboard(".js-copy-json", {
        text: function () {
            return JSON.stringify(app.card.toJSON(), null, 4);
        }
    });

    horizontalSplitter = new Splitter(document.getElementById("horizontalSplitter"), document.getElementById("jsonEditorHost"));
    horizontalSplitter.onRezized = (splitter: Splitter) => {
        if (isMonacoEditorLoaded) {
            monacoEditor.layout();
        }
    }

    propertyVerticalSplitter
        = new Splitter(document.getElementById("propertyVerticalSplitter"), document.getElementById("propertySheetHost"));
    propertyVerticalSplitter.isVertical = true;
    propertyVerticalSplitter.onRezized = (splitter: Splitter) => {
        scheduleLayoutUpdate();
    }

    treeViewVerticalSplitter
        = new Splitter(document.getElementById("treeViewVerticalSplitter"), document.getElementById("treeViewSheetHost"));
    treeViewVerticalSplitter.isVertical = true;

    let card = new Adaptive.AdaptiveCard();
    card.onImageLoaded = (image: Adaptive.Image) => {
        scheduleLayoutUpdate();
    }
    card.parse(JSON.parse(Constants.defaultPayload));

    app = new DesignerApp(document.getElementById("designerHost"));
    app.propertySheetHostElement = document.getElementById("propertySheetHost");
    app.treeViewSheetHostElement = document.getElementById("treeViewSheetHost");
    app.commandListHostElement = document.getElementById("commandsHost");
    app.paletteHostElement = document.querySelector(".aside-items");

    app.createContainerPicker().attach(document.getElementById("containerPickerHost"));

    app.togglePanels();
    app.cloneNodesTrees();

    window.addEventListener("pointermove", (e: PointerEvent) => { app.handlePointerMove(e); });
    window.addEventListener("resize", () => { scheduleLayoutUpdate(); });
    window.addEventListener("pointerup", (e: PointerEvent) => { app.handlePointerUp(e); });

    app.card = card;

    loadMonacoEditor(adaptiveCardSchema, monacoEditorLoaded);
};
