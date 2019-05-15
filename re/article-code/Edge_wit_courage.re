type animal =
  | Dog
  | Cat
  | Octopus;

let animalToString = animal =>
  switch (animal) {
  | Dog => "dog"
  | Cat => "cat"
  | Octopus => "octopus"
  };

let getWelcomeMessage = (name, visits, animal) => {
  "Hello "
  ++ name
  ++ ", you've visited this website "
  ++ string_of_int(visits)
  ++ " times and your favorite animal is the "
  ++ animalToString(animal);
};