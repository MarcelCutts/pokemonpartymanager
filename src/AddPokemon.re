[@react.component]
let make = () => {
  let (name, setName) = React.useState(() => "");

  let handleSubmit = e => {
    ReactEvent.Form.preventDefault(e);
    setName(_ => "");
  };

  <form onSubmit=handleSubmit>
    <input
      placeholder="Enter a pokemon..."
      value=name
      onChange={e => ReactEvent.Form.target(e)##value |> setName}
    />
    <input type_="submit" value="Add" />
    <h1> {ReasonReact.string(name)} </h1>
  </form>;
};