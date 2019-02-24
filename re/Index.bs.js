// Generated by BUCKLESCRIPT VERSION 4.0.18, PLEASE EDIT WITH CARE
'use strict';

var Css = require("bs-css/src/Css.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");
var Gatsby$ReactTemplate = require("./types/Gatsby.bs.js");

function str(prim) {
  return prim;
}

var component = ReasonReact.statelessComponent("Index");

var link = Css.style(/* :: */[
      Css.color(Css.hex("db4d3f")),
      /* :: */[
        Css.textDecoration(Css.none),
        /* [] */0
      ]
    ]);

var Styles = /* module */[/* link */link];

function make(_children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (_self) {
              return React.createElement("div", undefined, React.createElement("h1", undefined, "ianwilson.io: JavaScript, ReasonML, and GraphQL"), React.createElement("p", undefined, "I am Ian and I like to code and run, though not simultaneously."), React.createElement("p", undefined, "Sometimes you can find me..."), React.createElement("ul", undefined, React.createElement("li", undefined, "tweeting about web development and tech on twitter ", React.createElement("a", {
                                      href: "https://twitter.com/iwilsonq",
                                      target: "_blank"
                                    }, "@iwilsonq")), React.createElement("li", undefined, "blogging about all stack development on ", React.createElement("a", {
                                      href: "https://medium.com/@iwilsonq"
                                    }, "Medium"), " or on ", React.createElement("a", {
                                      href: "https://dev.to/iwilsonq",
                                      target: "_blank"
                                    }, "dev.to")), React.createElement("li", undefined, "attempting to record videos on Youtube and Twitch (coming soonish)"), React.createElement("li", undefined, "running about in the hills of the ", React.createElement("a", {
                                      href: "https://instagram.com/iwilsonq",
                                      target: "_blank"
                                    }, "SF Bay Area"))), React.createElement("p", undefined, "Tech note for the curious: this blog is bootstrapped with Gatsby and most of the components are built with ReasonML. The repo exists ", React.createElement("a", {
                                  href: "https://github.com/iwilsonq/ianwilson.io_re",
                                  target: "_blank"
                                }, "on Github.")), React.createElement("p", undefined, React.createElement("strong", undefined, "Looking to learn more about ReasonML or whatever else I'm working on?"), React.createElement("br", undefined), ReasonReact.element(undefined, undefined, Gatsby$ReactTemplate.Link[/* make */0]("/blog", link, /* array */["Definitely check out the blog"]))));
            }),
          /* initialState */component[/* initialState */10],
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */component[/* reducer */12],
          /* jsElementWrapped */component[/* jsElementWrapped */13]
        ];
}

var $$default = ReasonReact.wrapReasonForJs(component, (function (_jsProps) {
        return make(/* array */[]);
      }));

exports.str = str;
exports.component = component;
exports.Styles = Styles;
exports.make = make;
exports.$$default = $$default;
exports.default = $$default;
exports.__esModule = true;
/* component Not a pure module */