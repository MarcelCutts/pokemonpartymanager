open T;

module Styles = {
  open Css;
  let app =
    style([display(`flex), flexDirection(`column), alignItems(`center)]);
};

let beltCapacity = party => party |> List.length < 7 ? NotFull : Full;

type action =
  | Add(pokemon)
  | Remove(string);
type state = {party: list(T.partyEntry)};
let stateReducer = (state, action) =>
  switch (action) {
  | Add(p) =>
    switch (beltCapacity(state.party)) {
    | Full => state
    | NotFull => {
        party: [
          {
            pokemon: {
              name: p.name,
              number: p.number,
            },
            id: Uuid.v4(),
          },
          ...state.party,
        ],
      }
    }
  | Remove(id) => {
      party: state.party |> List.filter((p: partyEntry) => p.id != id),
    }
  };

[@react.component]
let make = () => {
  let (state, dispatch) = React.useReducer(stateReducer, {party: []});

  <div className=Styles.app>
    <AddPokemon addHandler={pokemon => dispatch(Add(pokemon))} />
    <Party removeHandler={id => dispatch(Remove(id))} party={state.party} />
  </div>;
};