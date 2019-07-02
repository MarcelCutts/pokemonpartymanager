[@react.component]
let make = (~party, ~removeHandler) =>
  <div>
    {party
     |> List.map((p: T.pokemon) =>
          <h1 key={p.id} onClick={_ => removeHandler(p.id)}>
            {ReasonReact.string(p.name)}
          </h1>
        )
     |> Array.of_list
     |> ReasonReact.array}
  </div>;