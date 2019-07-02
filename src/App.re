type action =
  | Add(string)
  | Remove(string);

type full =
  | Full
  | NotFull;

type state = {party: T.party};

let partyFullness = party => party |> List.length < 7 ? NotFull : Full;

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | Add(p) =>
          switch (partyFullness(state.party)) {
          | Full => state
          | NotFull => {party: [{name: p, id: Uuid.v4()}, ...state.party]}
          }
        | Remove(id) => {
            party: state.party |> List.filter((p: T.pokemon) => p.id != id),
          }
        },
      {
        {party: []};
      },
    );

  <div>
    <AddPokemon addHandler={p => dispatch(Add(p))} />
    <Party removeHandler={id => dispatch(Remove(id))} party={state.party} />
  </div>;
};