type pokemon = {
  name: string,
  number: int,
};

type partyEntry = {
  pokemon,
  id: string,
};

type capacity =
  | Full
  | NotFull;