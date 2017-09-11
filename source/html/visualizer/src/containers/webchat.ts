import { HostContainer } from "./host-container";
import * as Adaptive from "microsoft-adaptivecards";

export class WebChatContainer extends HostContainer {
    protected renderContainer(renderedCard: HTMLElement): HTMLElement {
        var outerElement = document.createElement("div");
        outerElement.className = "webChatOuterContainer";

        window.addEventListener(
            "resize",
            () => {
                if (outerElement.parentElement) {
                    var bounds = outerElement.parentElement.getBoundingClientRect();

                    var newWidth: string = "216px";

                    if (bounds.width >= 500) {
                        newWidth = "416px";
                    }
                    else if (bounds.width >= 400) {
                        newWidth = "320px";
                    }

                    if (outerElement.style.width != newWidth) {
                        outerElement.style.width = newWidth;
                    }
                }
            });

        var innerElement = document.createElement("div");
        innerElement.className = "webChatInnerContainer";

        innerElement.appendChild(renderedCard);
        outerElement.appendChild(innerElement);

        return outerElement;
    }

    public getHostConfig(): Adaptive.IHostConfig {
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
                    backgroundColor: "#FFFFFF",
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
                            normal: "#FF0000",
                            subtle: "#DDFF0000"
                        },
                        good: {
                            normal: "#54a254",
                            subtle: "#DD54a254"
                        },
                        warning: {
                            normal: "#c3ab23",
                            subtle: "#DDc3ab23"
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
                            normal: "#FF0000",
                            subtle: "#DDFF0000"
                        },
                        good: {
                            normal: "#54a254",
                            subtle: "#DD54a254"
                        },
                        warning: {
                            normal: "#c3ab23",
                            subtle: "#DDc3ab23"
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
                buttonSpacing: 20,
                showCard: {
                    actionMode: "inline",
                    inlineTopMargin: 16
                },
                actionsOrientation: "horizontal",
                actionAlignment: "left"
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
                    maxWidth: 150
                },
                value: {
                    color: "default",
                    size: "normal",
                    isSubtle: false,
                    weight: "normal",
                    wrap: true
                },
                spacing: 10
            }
        };
    }
}