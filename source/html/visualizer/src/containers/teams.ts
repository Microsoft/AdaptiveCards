import { HostContainer} from "./host-container";
import * as Adaptive from "microsoft-adaptivecards";

export class TeamsContainer extends HostContainer {
    protected renderContainer(renderedCard: HTMLElement): HTMLElement {
        var element = document.createElement("div");
        element.style.borderTop = "1px solid #F1F1F1";
        element.style.borderRight = "1px solid #F1F1F1";
        element.style.borderBottom = "1px solid #F1F1F1";
        element.style.border = "1px solid #F1F1F1"

        element.appendChild(renderedCard);

        return element;
    }

    public getHostConfig(): Adaptive.IHostConfig {
        return {
            spacing: {
                small: 3,
                default: 8,
                medium: 20,
                large: 30,
                extraLarge: 40,
                padding: 20
            },
            separator: {
                lineThickness: 1,
                lineColor: "#EEEEEE"        
            },
            supportsInteractivity: true,
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
                    backgroundColor: "#00000000",
                    fontColors: {
                        default: {
                            normal: "#333333",
                            subtle: "#EE333333"
                        },
                        accent: {
                            normal: "#2E89FC",
                            subtle: "#882E89FC" 
                        },
                        attention: {
                            normal: "#cc3300",
                            subtle: "#DDcc3300"
                        },
                        good: {
                            normal: "#54a254",
                            subtle: "#DD54a254"
                        },
                        warning: {
                            normal: "#e69500",
                            subtle: "#DDe69500"
                        }
                    }
                },
                emphasis: {
                    backgroundColor: "#08000000",
                    fontColors: {
                        default: {
                            normal: "#333333",
                            subtle: "#EE333333"
                        },
                        accent: {
                            normal: "#2E89FC",
                            subtle: "#882E89FC" 
                        },
                        attention: {
                            normal: "#cc3300",
                            subtle: "#DDcc3300"
                        },
                        good: {
                            normal: "#54a254",
                            subtle: "#DD54a254"
                        },
                        warning: {
                            normal: "#e69500",
                            subtle: "#DDe69500"
                        }
                    }
                }
            },
            imageSizes: {
                small: 40,
                medium: 80,
                large: 160
            },
            actions: {
                maxActions: 5,
                spacing: "default",
                buttonSpacing: 10,
                showCard: {
                    actionMode: "inline",
                    inlineTopMargin: 16
                },
                actionsOrientation: "horizontal",
                actionAlignment: "stretch"
            },
            adaptiveCard: {
                allowCustomStyle: false
            },
            image: {
                size: "medium"
            },
            imageSet: {
                imageSize: "medium",
                maxImageHeight: 100
            },
            factSet: {
                title: {
                    color: "default",
                    size: "normal",
                    isSubtle: false,
                    weight: "bolder",
                    wrap: true,
                    maxWidth: 150,
                },
                value: {
                    color: "default",
                    size: "normal",
                    isSubtle: false,
                    weight: "normal",
                    wrap: true,
                },
                spacing: 10
            }
        };
    }
}
