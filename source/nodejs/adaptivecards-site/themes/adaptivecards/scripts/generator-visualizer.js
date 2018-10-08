"use strict";

var fs = require("hexo-fs");
var path = require("path");

hexo.extend.generator.register("generator-visualizer", function (locals) {

    return {
        path: "visualizer/index.html",
        layout: "visualizer",
        data: {
            title: "Visualizer"
        }
    };

});
