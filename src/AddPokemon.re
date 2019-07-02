[@react.component]
let make = (~addHandler) => {
  let (name, setName) = React.useState(() => "");

  let handleSubmit = e => {
    ReactEvent.Form.preventDefault(e);
    addHandler(name);
    setName(_ => "");
  };

  <form onSubmit=handleSubmit>
    <input
      placeholder="Enter a pokemon..."
      value=name
      onChange={e => ReactEvent.Form.target(e)##value |> setName}
    />
    <input type_="submit" value="Add" />
  </form>;
};