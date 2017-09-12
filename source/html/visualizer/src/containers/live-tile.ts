import { HostContainer } from "./host-container";
import {
    IHostConfig,
    Size,
    TextSize,
    TextColor,
    TextWeight,
    Spacing,
    ShowCardActionMode,
    Orientation,
    ActionAlignment
} from "microsoft-adaptivecards";

export class LiveTileContainer extends HostContainer {
    // static backgroundColor: string = "#0078D7";

    private _width: number;
    private _height: number;

    constructor(width: number, height: number, styleSheet: string) {
        super(styleSheet);

        this._width = width;
        this._height = height;
        this.supportsActionBar = false;
    }

    protected renderContainer(renderedCard: HTMLElement): HTMLElement {
        var element = document.createElement("div");
        element.style.width = this._width + "px";
        element.style.height = this._height + "px";
        // element.style.backgroundColor = LiveTileContainer.backgroundColor;
        element.style.overflow = "hidden";

        renderedCard.style.height = "100%";

        element.appendChild(renderedCard);

        return element;
    }

    public getHostConfig(): IHostConfig {
        return {
            spacing: {
                small: 3,
                default: 8,
                medium: 20,
                large: 30,
                extraLarge: 40,
                padding: 10
            },
            separator: {
                lineThickness: 1,
                lineColor: "#EEEEEE"
            },
            supportsInteractivity: false,
            fontFamily: "Segoe UI",
            fontSizes: {
                small: 12,
                normal: 14,
                medium: 17,
                large: 21,
                extraLarge: 26
            },
            fontWeights: {
                lighter: 200,
                normal: 400,
                bolder: 600
            },
            containerStyles: {
                default: {
                    backgroundColor: "#0078D7",
                    fontColors: {
                        default: {
                            normal: "#FFFFFF",
                            subtle: "#88FFFFFF"
                        },
                        accent: {
                            normal: "#00c2ff",
                            subtle: "#8800c2ff"
                        },
                        attention: {
                            normal: "#ffa700",
                            subtle: "#DDffa700"
                        },
                        good: {
                            normal: "#00FF00",
                            subtle: "#DD00FF00"
                        },
                        warning: {
                            normal: "#FFD800",
                            subtle: "#DDFFD800"
                        }
                    }
                },
                emphasis: {
                    backgroundColor: "08000000",
                    fontColors: {
                        default: {
                            normal: "#FFFFFF",
                            subtle: "#88FFFFFF"
                        },
                        accent: {
                            normal: "#00c2ff",
                            subtle: "#8800c2ff"
                        },
                        attention: {
                            normal: "#ffa700",
                            subtle: "#DDffa700"
                        },
                        good: {
                            normal: "#00FF00",
                            subtle: "#DD00FF00"
                        },
                        warning: {
                            normal: "#FFD800",
                            subtle: "#DDFFD800"
                        }
                    }
                }
            },
            imageSizes: {
                small: 40,
                medium: 80,
                large: 120
            },
            actions: {
                maxActions: 5,
                spacing: Spacing.Default,
                buttonSpacing: 20,
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
            image: {
                size: Size.Medium,
            },
            imageSet: {
                imageSize: Size.Medium,
                maxImageHeight: 100
            },
            factSet: {
                title: {
                    color: TextColor.Default,
                    size: TextSize.Normal,
                    isSubtle: false,
                    weight: TextWeight.Bolder,
                    wrap: true,
                    maxWidth: 150,
                },
                value: {
                    color: TextColor.Default,
                    size: TextSize.Normal,
                    isSubtle: false,
                    weight: TextWeight.Normal,
                    wrap: true,
                },
                spacing: 10
            }
        };
    }
}