[@react.component]
let make = (~pokemon) =>
  <div>
    {List.mapi(
       (index, pokemon) =>
         <h1 key={string_of_int(index)}> {ReasonReact.string(pokemon)} </h1>,
       pokemon,
     )
     |> Array.of_list
     |> ReasonReact.array}
  </div>;