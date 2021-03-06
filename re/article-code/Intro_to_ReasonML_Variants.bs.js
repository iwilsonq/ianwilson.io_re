// Generated by BUCKLESCRIPT VERSION 5.0.4, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Caml_obj = require("bs-platform/lib/js/caml_obj.js");

function restrictRange(number, min, max) {
  if (Caml_obj.caml_greaterthan(number, max)) {
    return max;
  } else if (Caml_obj.caml_lessthan(number, min)) {
    return min;
  } else {
    return number;
  }
}

function restrictRangef(number, min, max) {
  if (Caml_obj.caml_greaterthan(number, max)) {
    return max;
  } else if (Caml_obj.caml_lessthan(number, min)) {
    return min;
  } else {
    return number;
  }
}

function validatePercentage(pct) {
  return restrictRangef(pct, 0.0, 1.0);
}

function validateRgb(red, blue, green) {
  var red$1 = restrictRange(red, 0, 255);
  var green$1 = restrictRange(green, 0, 255);
  var blue$1 = restrictRange(blue, 0, 255);
  return /* tuple */[
          red$1,
          blue$1,
          green$1
        ];
}

function getMonthlyPriceForCarColor(color) {
  if (typeof color === "number") {
    switch (color) {
      case 0 : 
          return 28;
      case 1 : 
          return 24;
      case 2 : 
          return 20;
      case 3 : 
          return 0;
      
    }
  } else if (color.tag) {
    var match = validateRgb(color[0], color[1], color[2]);
    var sum = (match[0] + match[1] | 0) + match[2] | 0;
    if (sum > 500) {
      return 36;
    } else {
      return 32;
    }
  } else {
    return restrictRangef(color[0], 0.0, 1.0) * 20.0 | 0;
  }
}

console.log(getMonthlyPriceForCarColor(/* Grey */Block.__(0, [0.64])));

console.log(28);

console.log(getMonthlyPriceForCarColor(/* Rgb */Block.__(1, [
            150,
            210,
            67
          ])));

console.log(getMonthlyPriceForCarColor(/* Rgb */Block.__(1, [
            150,
            210,
            167
          ])));

exports.restrictRange = restrictRange;
exports.restrictRangef = restrictRangef;
exports.validatePercentage = validatePercentage;
exports.validateRgb = validateRgb;
exports.getMonthlyPriceForCarColor = getMonthlyPriceForCarColor;
/*  Not a pure module */
