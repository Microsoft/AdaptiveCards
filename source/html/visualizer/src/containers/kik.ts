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

export class KikContainer extends HostContainer {
    private _width: number;

    constructor(width: number, styleSheet: string) {
        super(styleSheet);

        this._width = width;
        this.supportsActionBar = false;
    }

    protected renderContainer(renderedCard: HTMLElement): HTMLElement {
        var outerElement = document.createElement("div");
        outerElement.className = "kikOuterContainer";
        outerElement.style.width = this._width + "px";
        outerElement.appendChild(renderedCard);
        return outerElement;
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
            fontFamily: "Calibri, Candara, Segoe, 'Segoe UI', Optima, Arial, sans-serif;",
            fontSizes: {
                small: 12,
                normal: 14,
                medium: 16,
                large: 19,
                extraLarge: 22
            },
            fontWeights: {
                lighter: 200,
                normal: 400,
                bolder: 600
            },
            containerStyles: {
                default: {
                    backgroundColor: "#FFFFFF",
                    fontColors: {
                        default: {
                            normal: "#FF101010",
                            subtle: "#b2101010"
                        },
                        accent: {
                            normal: "#FF0000FF",
                            subtle: "#b20000FF"
                        },
                        good: {
                            normal: "#FF008000",
                            subtle: "#b2008000"
                        },
                        warning: {
                            normal: "#FFFFD700",
                            subtle: "#b2FFD700"
                        },
                        attention: {
                            normal: "#FF8B0000",
                            subtle: "#b28B0000"
                        }
                    }
                },
                emphasis: {
                    backgroundColor: "#08000000",
                    fontColors: {
                        default: {
                            normal: "#FF101010",
                            subtle: "#b2101010"
                        },
                        accent: {
                            normal: "#FF0000FF",
                            subtle: "#b20000FF"
                        },
                        good: {
                            normal: "#FF008000",
                            subtle: "#b2008000"
                        },
                        warning: {
                            normal: "#FFFFD700",
                            subtle: "#b2FFD700"
                        },
                        attention: {
                            normal: "#FF8B0000",
                            subtle: "#b28B0000"
                        }
                    }
                }
            },
            imageSizes: {
                small: 60,
                medium: 120,
                large: 180
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
                    maxWidth: 150
                },
                value: {
                    color: TextColor.Default,
                    size: TextSize.Normal,
                    isSubtle: false,
                    weight: TextWeight.Normal,
                    wrap: true
                },
                spacing: 10
            }
        };
    }
}