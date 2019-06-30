type state = {pokemon: list(string)};

type action =
  | Add(string);

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | Add(p) => {pokemon: [p, ...state.pokemon]}
        },
      {pokemon: []},
    );

  <div>
    <AddPokemon addHandler={p => dispatch(Add(p))} />
    <Party pokemon={state.pokemon} />
  </div>;
};