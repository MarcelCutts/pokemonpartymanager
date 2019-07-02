// Generated by BUCKLESCRIPT VERSION 6.0.3, PLEASE EDIT WITH CARE

import * as List from "bs-platform/lib/es6/list.js";
import * as $$Array from "bs-platform/lib/es6/array.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";

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

export {
  make ,
  
}
/* react Not a pure module */
