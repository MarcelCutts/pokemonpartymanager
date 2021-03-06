// Generated by BUCKLESCRIPT VERSION 5.0.6, PLEASE EDIT WITH CARE

import * as Css from "bs-css/src/Css.js";
import * as List from "bs-platform/lib/es6/list.js";
import * as Block from "bs-platform/lib/es6/block.js";
import * as Curry from "bs-platform/lib/es6/curry.js";
import * as React from "react";
import * as V4 from "uuid/v4";
import * as Party$Pokemon from "./Party.bs.js";
import * as AddPokemon$Pokemon from "./AddPokemon.bs.js";

var app = Css.style(/* :: */[
      Css.display(/* flex */-1010954439),
      /* :: */[
        Css.flexDirection(/* column */-963948842),
        /* :: */[
          Css.alignItems(/* center */98248149),
          /* [] */0
        ]
      ]
    ]);

var Styles = /* module */[/* app */app];

function beltCapacity(party) {
  var match = List.length(party) < 7;
  if (match) {
    return /* NotFull */1;
  } else {
    return /* Full */0;
  }
}

function stateReducer(state, action) {
  if (action.tag) {
    var id = action[0];
    return /* record */[/* party */List.filter((function (p) {
                      return p[/* id */1] !== id;
                    }))(state[/* party */0])];
  } else {
    var p = action[0];
    var match = beltCapacity(state[/* party */0]);
    if (match) {
      return /* record */[/* party : :: */[
                /* record */[
                  /* pokemon : record */[
                    /* name */p[/* name */0],
                    /* number */p[/* number */1]
                  ],
                  /* id */V4()
                ],
                state[/* party */0]
              ]];
    } else {
      return state;
    }
  }
}

function App(Props) {
  var match = React.useReducer(stateReducer, /* record */[/* party : [] */0]);
  var dispatch = match[1];
  return React.createElement("div", {
              className: app
            }, React.createElement(AddPokemon$Pokemon.make, {
                  addHandler: (function (pokemon) {
                      return Curry._1(dispatch, /* Add */Block.__(0, [pokemon]));
                    })
                }), React.createElement(Party$Pokemon.make, {
                  party: match[0][/* party */0],
                  removeHandler: (function (id) {
                      return Curry._1(dispatch, /* Remove */Block.__(1, [id]));
                    })
                }));
}

var make = App;

export {
  Styles ,
  beltCapacity ,
  stateReducer ,
  make ,
  
}
/* app Not a pure module */
