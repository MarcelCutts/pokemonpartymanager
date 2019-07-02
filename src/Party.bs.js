// Generated by BUCKLESCRIPT VERSION 6.0.3, PLEASE EDIT WITH CARE
'use strict';

var List = require("bs-platform/lib/js/list.js");
var $$Array = require("bs-platform/lib/js/array.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");

function Party(Props) {
  var party = Props.party;
  var removeHandler = Props.removeHandler;
  return React.createElement("div", undefined, $$Array.of_list(List.map((function (p) {
                        return React.createElement("h1", {
                                    key: p[/* id */1],
                                    onClick: (function (param) {
                                        return Curry._1(removeHandler, p[/* id */1]);
                                      })
                                  }, p[/* name */0]);
                      }), party)));
}

var make = Party;

exports.make = make;
/* react Not a pure module */
