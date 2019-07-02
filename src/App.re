type action =
  | Add(string)
  | Remove(string);

type state = {party: T.party};

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | Add(p) => {party: [{name: p, id: Uuid.v4()}, ...state.party]}
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