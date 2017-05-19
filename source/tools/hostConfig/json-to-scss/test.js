var convert = require('./index');

var config = {
    supportsInteractivity: true,
    strongSeparation: {
        spacing: 40,
        lineThickness: 1,
        lineColor: "#80EEEEEE"
    },
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
    colors: {
        dark: {
            normal: "#333333",
            subtle: "#EE333333"
        },
        light: {
            normal: "#FFFFFF",
            subtle: "#88FFFFFF"
        },
        accent: {
            normal: "#2E89FC",
            subtle: "#882E89FC"
        },
        attention: {
            normal: "#FFD800",
            subtle: "#DDFFD800"
        },
        good: {
            normal: "#00FF00",
            subtle: "#DD00FF00"
        },
        warning: {
            normal: "#FF0000",
            subtle: "#DDFF0000"
        }
    },
    imageSizes: {
        small: 40,
        medium: 80,
        large: 160
    },
    actions: {
        maxActions: 5,
        separation: {
            spacing: 8
        },
        buttonSpacing: 20,
        stretch: false,
        showCard: {
            actionMode: "inlineEdgeToEdge",
            inlineTopMargin: 16,
            backgroundColor: "#08000000",
            padding: {
                top: 8,
                right: 8,
                bottom: 8,
                left: 8
            }
        },
        actionsOrientation: "horizontal",
        actionAlignment: "left"
    },
    adaptiveCard: {
        backgroundColor: "#FFFFFF",
        padding: {
            left: 8,
            top: 8,
            right: 8,
            bottom: 8
        }
    },
    container: {
        separation: {
            spacing: 8
        },
        normal: {
        },
        emphasis: {
            backgroundColor: "#EEEEEE",
            borderColor: "#AAAAAA",
            borderThickness: {
                top: 1,
                right: 1,
                bottom: 1,
                left: 1
            },
            padding: {
                top: 10,
                right: 10,
                bottom: 10,
                left: 10
            }
        }
    },
    textBlock: {
        color: "dark",
        separations: {
            small: {
                spacing: 8,
            },
            normal: {
                spacing: 8
            },
            medium: {
                spacing: 8
            },
            large: {
                spacing: 8
            },
            extraLarge: {
                spacing: 8
            }
        }
    },
    image: {
        size: "medium",
        separation: {
            spacing: 8
        }
    },
    imageSet: {
        imageSize: "medium",
        separation: {
            spacing: 8
        }
    },
    factSet: {
        separation: {
            spacing: 8
        },
        title: {
            color: "dark",
            size: "normal",
            isSubtle: false,
            weight: "bolder",
            wrap: true,
            maxWidth: 150
        },
        value: {
            color: "dark",
            size: "normal",
            isSubtle: false,
            weight: "normal",
            wrap: true
        },
        spacing: 10
    },
    input: {
        separation: {
            spacing: 8
        }
    },
    columnSet: {
        separation: {
            spacing: 8
        }
    },
    column: {
        separation: {
            spacing: 8
        }
    }
};

var conversion = convert(config);

process.stdout.write(conversion);
