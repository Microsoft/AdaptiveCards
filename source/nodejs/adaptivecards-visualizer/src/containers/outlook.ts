import { HostContainer } from "./host-container";
import {
    AdaptiveCard,
    HostConfig,
    Size,
    TextSize,
    TextColor,
    TextWeight,
    Spacing,
    ShowCardActionMode,
    Orientation,
    ActionAlignment,
    CardElement,
    Image,
    Container,
    Column,
    ActionSet,
    HttpAction
} from "adaptivecards";

export class OutlookContainer extends HostContainer {
    protected renderContainer(adaptiveCard: AdaptiveCard, target: HTMLElement): HTMLElement {
        var element = document.createElement("div");
        element.style.borderTop = "1px solid #F1F1F1";
        element.style.borderRight = "1px solid #F1F1F1";
        element.style.borderBottom = "1px solid #F1F1F1";
        element.style.border = "1px solid #F1F1F1"
        target.appendChild(element);

        adaptiveCard.render(element);

        return element;
    }

    public initialize() {
        super.initialize();

        AdaptiveCard.elementTypeRegistry.registerType("ActionSet", () => { return new ActionSet(); });

        AdaptiveCard.actionTypeRegistry.unregisterType("Action.Submit");
        AdaptiveCard.actionTypeRegistry.registerType("Action.Http", () => { return new HttpAction(); });

        AdaptiveCard.useAutomaticContainerBleeding = true;
        AdaptiveCard.preExpandSingleShowCardAction = true;
    }

    public parseElement(element: CardElement, json: any) {
        if (typeof json["isVisible"] === "boolean") {
            element.isVisible = json["isVisible"];
        }

        if (element instanceof Image) {
            (<Image>element).backgroundColor = json["backgroundColor"];
        }

        if (element instanceof Column) {
            (<Column>element).pixelWidth = json["pixelWidth"];
        }

        if (element instanceof Container) {
            (<Container>element).bleed = json["bleed"];
        }
    }

    public anchorClicked(anchor: HTMLAnchorElement): boolean {
        if (anchor.href.toLowerCase().startsWith("action:")) {
            alert("Executing inline action...");

            return true;
        }
        else {
            return false;
        }
    }

    public getHostConfig(): HostConfig {
        return new HostConfig({
            supportsInteractivity: true,
            fontFamily: "Segoe UI",
            spacing: {
                small: 10,
                default: 20,
                medium: 30,
                large: 40,
                extraLarge: 50,
                padding: 20
            },
            separator: {
                lineThickness: 1,
                lineColor: "#EEEEEE"
            },
            fontSizes: {
                small: 12,
                default: 14,
                medium: 17,
                large: 21,
                extraLarge: 26
            },
            fontWeights: {
                lighter: 200,
                default: 400,
                bolder: 600
            },
            imageSizes: {
                small: 40,
                medium: 80,
                large: 160
            },
            containerStyles: {
                default: {
                    backgroundColor: "#FFFFFF",
                    foregroundColors: {
                        default: {
                            default: "#333333",
                            subtle: "#EE333333"
                        },
                        accent: {
                            default: "#2E89FC",
                            subtle: "#882E89FC"
                        },
                        attention: {
                            default: "#cc3300",
                            subtle: "#DDcc3300"
                        },
                        good: {
                            default: "#54a254",
                            subtle: "#DD54a254"
                        },
                        warning: {
                            default: "#e69500",
                            subtle: "#DDe69500"
                        }
                    }
                },
                emphasis: {
                    backgroundColor: "#08000000",
                    foregroundColors: {
                        default: {
                            default: "#333333",
                            subtle: "#EE333333"
                        },
                        accent: {
                            default: "#2E89FC",
                            subtle: "#882E89FC"
                        },
                        attention: {
                            default: "#cc3300",
                            subtle: "#DDcc3300"
                        },
                        good: {
                            default: "#54a254",
                            subtle: "#DD54a254"
                        },
                        warning: {
                            default: "#e69500",
                            subtle: "#DDe69500"
                        }
                    }
                }
            },
            actions: {
                maxActions: 5,
                spacing: Spacing.Default,
                buttonSpacing: 10,
                showCard: {
                    actionMode: ShowCardActionMode.Inline,
                    inlineTopMargin: 16
                },
                actionsOrientation: Orientation.Horizontal,
                actionAlignment: ActionAlignment.Left
            },
            adaptiveCard: {
                allowCustomStyle: false
            },
            imageSet: {
                imageSize: Size.Medium,
                maxImageHeight: 100
            },
            factSet: {
                title: {
                    color: TextColor.Default,
                    size: TextSize.Default,
                    isSubtle: false,
                    weight: TextWeight.Bolder,
                    wrap: true,
                    maxWidth: 150,
                },
                value: {
                    color: TextColor.Default,
                    size: TextSize.Default,
                    isSubtle: false,
                    weight: TextWeight.Default,
                    wrap: true,
                },
                spacing: 10
            }
        });
    }
}