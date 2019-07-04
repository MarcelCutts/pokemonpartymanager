open T;

module Styles = {
  open Css;

  let form =
    style([display(`flex), flexDirection(`column), maxWidth(px(700))]);
};

module Decode = {
  let pokemon = json =>
    Json.Decode.{
      name: json |> field("name", string),
      number: json |> field("id", int),
    };
};

[@react.component]
let make = (~addHandler) => {
  let (name, setName) = React.useState(() => "");

  let handleSubmit = e => {
    ReactEvent.Form.preventDefault(e);

    Js.Promise.(
      Fetch.fetch("https://pokeapi.co/api/v2/pokemon/" ++ name)
      |> then_(Fetch.Response.json)
      |> then_(json => json |> Decode.pokemon |> addHandler |> resolve)
      |> catch(e => Js.log(e) |> resolve)
      |> ignore
    );

    setName(_ => "");
  };

  <form onSubmit=handleSubmit className=Styles.form>
    <input
      placeholder="Enter a pokemon..."
      value=name
      onChange={e => ReactEvent.Form.target(e)##value |> setName}
    />
    <input type_="submit" value="Add" />
  </form>;
};