open T;

[@react.component]
let make = (~party, ~removeHandler) =>
  <div>
    {party
     |> List.map(partyEntry =>
          <h1 key={partyEntry.id} onClick={_ => removeHandler(partyEntry.id)}>
            {ReasonReact.string(partyEntry.pokemon.name)}
          </h1>
        )
     |> Array.of_list
     |> ReasonReact.array}
  </div>;