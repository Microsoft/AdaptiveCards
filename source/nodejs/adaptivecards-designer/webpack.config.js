var webpack = require("webpack");
var path = require("path");

var designer = {
    devtool: "source-map",
    entry: {
        "adaptivecards-designer": ["./src/app.ts"],
        "adaptivecards-designer.min": ["./src/app.ts"]
    },
    output: {
        path: path.resolve(__dirname, "dist"),
        filename: "[name].js",
    },
    resolve: {
        extensions: [".ts", ".tsx", ".js"]
    },
    plugins: [
        new webpack.optimize.UglifyJsPlugin({
            minimize: true,
            sourceMap: true,
            include: /\.min\.js$/,
        })
    ],
    module: {
        rules: [
            {
                test: /\.ts$/,
                loader: "ts-loader"
            },
            {
                test: /\.json$/,
                loader: "json-loader",
            }
        ]
    },
    externals: {
        "markdown-it": "markdownit"
    }
};

module.exports = designer;
