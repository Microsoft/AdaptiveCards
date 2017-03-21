import { HostContainer} from "./HostContainer";
import * as Adaptive from "../../Adaptive";
import * as Utils from "../../Utils";

export class LiveTileContainer extends HostContainer {
    static backgroundColor: string = "#0078D7";
    static textColor: Adaptive.TextColor = Adaptive.TextColor.Light;

    private _width: number;
    private _height: number;

    constructor(width: number, height: number, styleSheet: string) {
        super(styleSheet);

        this._width = width;
        this._height = height;
        this.supportsActionBar = false;
    }

    render(card: Adaptive.AdaptiveCard): HTMLElement {
        let element = document.createElement("div");
        element.style.width = this._width + "px";
        element.style.height = this._height + "px";
        element.style.backgroundColor = LiveTileContainer.backgroundColor;
        element.style.overflow = "hidden";

        card.body.textColor = LiveTileContainer.textColor;

        let renderedCard = card.render();
        renderedCard.style.height = "100%";

        Utils.appendChild(element, renderedCard);
        let hostDiv = document.createElement("div");
        Utils.appendChild(hostDiv, element);
        Utils.appendChild(hostDiv, super.render(card));
        return hostDiv;
    }
}