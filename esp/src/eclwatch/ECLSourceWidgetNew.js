
define([
    "dojo/_base/declare",
    "dojo/_base/lang",
    "dojo/i18n",
    "dojo/i18n!./nls/hpcc",
    "dojo/dom",
    "dojo/request/xhr",
    "dojo/topic",

    "dijit/registry",

    "hpcc/_Widget",
    "src/ESPWorkunit",

    "@hpcc-js/comms",
    "@hpcc-js/tree",
    "@hpcc-js/codemirror",
    "@hpcc-js/phosphor",
    "@hpcc-js/util",

    "dojo/text!../templates/ECLSourceWidgetNew.html",

    "dijit/layout/BorderContainer",
    "dijit/layout/ContentPane",
    "dijit/Toolbar",
    "dijit/ToolbarSeparator",
    "dijit/form/Button"

], function (declare, lang, i18n, nlsHPCC, dom, xhr, topic,
    registry,
    _Widget, ESPWorkunit,
    hpccjsComms,
    hpccjsTree,
    hpccjsCodemirror,
    hpccjsPhosphor,
    hpccjsUtil,
    template) {
    return declare("ECLSourceWidgetNew", [_Widget], {
        templateString: template,
        baseClass: "ECLSourceWidgetNew",
        i18n: nlsHPCC,

        borderContainer: null,
        eclSourceContentPane: null,
        wu: null,
        editor: null,
        markers: [],
        highlightLines: [],
        readOnly: false,

        buildRendering: function (args) {
            this.inherited(arguments);
        },

        postCreate: function (args) {
            this.inherited(arguments);
            this.borderContainer = registry.byId(this.id + "BorderContainer");
        },

        startup: function (args) {
            this.inherited(arguments);
        },

        resize: function (args) {
            this.inherited(arguments);
            this.borderContainer.resize();
            if (this.archiveViewer) {
                this.archiveViewer
                    .resize()
                    .render()
                ;
            }
        },

        //  Plugin wrapper  ---
        init: function (params) {
            if (this.inherited(arguments))
                return;

            const context = this;

            const directoryTree = new hpccjsTree.DirectoryTree()
                .textFileIcon("fa fa-file-code-o")
                .omitRoot(true)
                ;
            const editor = new hpccjsCodemirror.ECLEditor();
            const panels = new hpccjsPhosphor.SplitPanel("horizontal")
                .target(this.id + "EclContent")
                .addWidget(directoryTree)
                .addWidget(editor)
                .relativeSizes([0.38,0.62])
                ;
            
            const wu = hpccjsComms.Workunit.attach({ baseUrl: "" }, params.Wuid);
            wu.refresh(true).then(wuInfo=>{
                editor.text(wuInfo.Query.Text);
                directoryTree
                    .data({
                        label: "root",
                        children: [
                            {
                                label:"loading...",
                            }
                        ]
                    })
                    .iconSize(0)
                    .rowItemPadding(2)
                    ;
                
                wu.fetchArchive().then(archiveResp => {
                    const json = hpccjsUtil.xml2json(archiveResp);
                    let pathToQuery = "";
                    try{
                        pathToQuery = json._children[0]._children.find(n=>n.name && n.name.toLowerCase()==="query")["$"].attributePath;
                    }catch(e){

                    }
                    const data = {
                        label: "",
                        children: []
                    };
                    if (json._children && json._children[0]) {
                        if (json._children[0].name === "html") {
                            data.children.push({
                                label: "ECL Query",
                                iconClass: "fa fa-file-code-o",
                                content: wuInfo.Query.Text
                            });
                            data.children.push({
                                label: "error loading archive",
                                iconClass: "fa fa-exclamation-triangle",
                                content: JSON.stringify(json, null, 4)
                            });
                        } else {
                            const rootModule = json._children[0]._children
                                .find(n=>n.name && n["$"] && typeof n["$"].name === "")
                                ;
                            if(rootModule){
                                if(rootModule._children) {
                                    data.children = rootModule._children.map(n=>{
                                        return transformNode(n);
                                    })
                                    .filter(n=>n)
                                    ;
                                }
                                json._children[0]._children
                                    .filter(n=>n.name && n["$"] && typeof n["$"].name !== "")
                                    .forEach(n=>{
                                        const _node = transformNode(n);
                                        if(_node)data.children.push(_node);
                                    })
                            } else {
                                json._children[0]._children.forEach(n=>{
                                    const _node = transformNode(n);
                                    if(_node)data.children.push(_node);
                                });
                            }
                        }
                    }
                    directoryTree
                        .data(data)
                        .iconSize(12)
                        .rowItemPadding(2)
                        ;
        
                    directoryTree.rowClick = contentStr => {
                        editor.text(contentStr);
                    }
                    
                    panels.render(()=>{
                        const rw = directoryTree.calcRequiredWidth() + 20;
                        const pw = panels.width();
                        const ratio = rw / pw;
                        panels.relativeSizes([ratio, 1 - ratio]);
                    });
                    function transformNode(node, pathStr = "") {
                        const _node = {};
                        _node.label = node["$"] && node["$"].name ? node["$"].name : "";
                        if (!_node.label && node.name) {
                            _node.label = node.name;
                        }
                        if (node._children && node._children.length > 0) {
                            if (node._children.length === 1 && node._children[0].name === "Text") {
                                _node.content = node._children[0].content;
                                if ((pathStr.length > 0 ? pathStr+"." : "")+_node.label === pathToQuery) {
                                    _node.bold = true;
                                }
                            } else {
                                _node.children = node._children.map(n => {
                                        return transformNode(n, pathStr.length > 0 ? pathStr+"."+_node.label : _node.label);
                                    })
                                    .filter(n => n)
                                    ;
                            }
                        } else if (typeof node.content === "string" && node.content.trim()) {
                            _node.content = node.content;
                            if ((pathStr.length > 0 ? pathStr+"." : "")+_node.label === pathToQuery) {
                                _node.bold = true;
                            }
                        } else {
                            if(node.name){
                                return {
                                    label: node.name,
                                    content: JSON.stringify(node, undefined, 4)
                                }
                            }
                            return false;
                        }
                        return _node;
                    }
                });
            });
        }
    });
});

