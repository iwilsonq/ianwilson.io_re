// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var React = require("react");
var Belt_Array = require("bs-platform/lib/js/belt_Array.js");
var Belt_SortArray = require("bs-platform/lib/js/belt_SortArray.js");
var MarkdownPost$ReactTemplate = require("./MarkdownPost.bs.js");

function str(prim) {
  return prim;
}

function MarkdownBlog(Props) {
  var posts = Props.posts;
  var renderPosts = Belt_Array.map(Belt_SortArray.stableSortBy(posts, (function (postA, postB) {
              var match = postA.frontmatter.date < postB.frontmatter.date;
              if (match) {
                return 1;
              } else {
                return -1;
              }
            })), (function (post) {
          return React.createElement(MarkdownPost$ReactTemplate.make, {
                      post: post,
                      key: post.id
                    });
        }));
  return React.createElement("div", undefined, renderPosts);
}

var make = MarkdownBlog;

var $$default = MarkdownBlog;

exports.str = str;
exports.make = make;
exports.$$default = $$default;
exports.default = $$default;
exports.__esModule = true;
/* react Not a pure module */
