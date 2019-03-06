let log = Js.log("hell0o");

type color =
  | Red
  | Blue
  | White
  | Black
  | Grey(float)
  | Rgb(int, int, int);


let restrictRange = (number, min, max) => 
  if (number > max) {
    max;
  } else if (number < min) {
    min;
  } else {
    number;
  };

let restrictRangef = (number, min, max) => 
  if (number > max) {
    max;
  } else if (number < min) {
    min;
  } else {
    number;
  };

let validatePercentage = pct =>
  restrictRangef(pct, 0.0, 1.0);

let validateRgb = (red, blue, green) => {
  let red = restrictRange(red, 0, 255);
  let green = restrictRange(green, 0, 255);
  let blue = restrictRange(blue, 0, 255);
  (red, blue, green);
};

let getMonthlyPriceForCarColor = color =>
  switch (color) {
  | Red => 28
  | Blue => 24
  | White => 20
  | Black => 0
  | Grey(pct) => int_of_float(validatePercentage(pct) *. 20.0)
  | Rgb(red, green, blue) => {
      let (r, g, b) = validateRgb(red, green, blue);
      let sum = r + g + b;
      if (sum > 500) {
        36
      } else {
        32
      };
    }
  };

Js.log(getMonthlyPriceForCarColor(Grey(0.64)));
Js.log(getMonthlyPriceForCarColor(Red));
Js.log(getMonthlyPriceForCarColor(Rgb(150, 210, 67)));
Js.log(getMonthlyPriceForCarColor(Rgb(150, 210, 167)));