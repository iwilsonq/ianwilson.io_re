---
title: Intro to ReasonML Variants
date: 2019-03-02T21:25:04.540Z
path: intro-to-reasonml-variants
description: Learn to wield ReasonML variants to create better, typesafe web applications
tags: reason,javascript,webdev,functional
---

ReasonML is a super fast, expressive, and functional programming language. Currently, it can be compiled to optimized JavaScript for the web, WebGL/OpenGL for graphics rendering, or even native bytecode.

One of my favorite features of Reason are variant data types. These types allow us to handle enums in a sane way, forcing us to handle all possibilities for a particular scenario. We can define a variant type like this:

```reason
type color =
  | Red
  | Blue
  | White
  | Black
  | Grey;
```

We see that the type `color` can be represented as this enumeration of different colors. Not too complicated, but not too enlightening either. In JavaScript, we could handle this with an object mapping:

```javascript
const COLORS = {
  RED: 'red',
  BLUE: 'blue',
  WHITE: 'white',
  BLACK: 'black',
  GREY: 'grey',
}
```

I used maps like this all the time in my JavaScript projects, they help a ton when your goal is to keep constants defined in the same place. If you need to update, add, or remove a field, you only need to do so in one location.

If this were the whole story, I would probably decide that a compiled-to-js programming language like Reason is not worth the effort involved when I could just add TypeScript support. After all, so far it has only saved us a tiny amount of code.

Let's take a look at an example to see how Reason would help us where ordinary JavaScript falls short.

```javascript
function getMonthlyPriceForCarColor(color) {
  switch(color) {
    case COLORS.RED:
      return 28;
    case COLORS.BLUE:
      return 24;
    case COLORS.WHITE:
      return 20;
  }
}
```

This function takes a color (from our convenient colors lookup-map) and returns to us the additional monthly price of getting a Tesla Model S. In other words, getting a red Tesla costs more because it is the best color. 

One other thing you might notice is that I did not provide a default case, and as an imperfect programmer, I neglected some of the other colors. JavaScript will not yell at me for this on its own, so I will probably have to find out the hard way that I forgot some of the other cases. 

Hopefully QA will catch this bug before my code lands in production. But even if they're really thorough, I'd still have to make changes and push/review more code. Wouldn't it be nice if our typechecker could alert us on the fly?

The same function in Reason looks like this:

```reason
let getMonthlyPriceForCarColor = color =>
  switch(color) {
    | Red => 28
    | Blue => 24
    | White => 20
  };
```

First of all there's less code, which is great, but beside the point. In practice, this function will actually have red squiggly underlines, alerting us that our switch is not exhaustive - it does not cover all of the possibilities or our `color` variant. 

The error message is actually quite helpful when this happens.

![Error: Non exhaustive switch statement](/images/non-exhaustive.png)

Fixing this issue simply requires that you cover the other possibilities.

```reason
let getMonthlyPriceForCarColor = color =>
  switch(color) {
    | Red => 28
    | Blue => 24
    | White => 20
    | Black => 0
    | Grey => 0
  };
```

Reason wont let us compile our code if we don't have a case for each possibility in this function. This is a sampling of the incredibly powerful typesystem we have with Reason.

## Variants as Constructors

As I've demonstrated so far, variants can be used as enumerations, but they exhibit a power that takes enumeration to a whole new level. Variants can be used as generic constructors that take arguments, allowing developers to further customize applications for their use case.

For example, we can adjust our price (arbitraily) based on the shade of grey or even go as far as to specify a totally arbitrary color somewhere in the RGB scale.

Updating our color type to the following:

```reason
type color =
  | Red
  | Blue
  | White
  | Black
  | Grey(float)
  | Rgb(int, int, int);
```

Now when we run our function, we can let the customer to pick whatever color they want. To keep make the pricing more reasonable with our already hardcoded values, we'll allow grey to range from $0 to $20. depending on whatever number given between 0.0 and 1.0.

The `Rgb` constructor will be the most expensive since we have to create new paint in order to satisfy that requirement. The higher the values of red, blue, and green color, the closer to $36 it will be.

```reason
let getMonthlyPriceForCarColor = color =>
  switch(color) {
    | Red => 28
    | Blue => 24
    | White => 20
    | Black => 0
    | Grey(pct) => int_of_float(pct *. 20.0)
    | Rgb(red, green, blue) => {
      /* completely random calculation. Tesla probably does not do this */
      let sum = red + green + blue;
      if (sum > 500) {
        36
      } else {
        32
      }
    }
  };

Js.log(getMonthlyPriceForCarColor(Red));                /* 28 */
Js.log(getMonthlyPriceForCarColor(Grey(0.64)));         /* 12 */
Js.log(getMonthlyPriceForCarColor(Rgb(150, 210, 67)));  /* 32 */
Js.log(getMonthlyPriceForCarColor(Rgb(150, 210, 167))); /* 36 */
```

This is pretty neat huh? This example displays the expressive power of a robust type-safe language like Reason.

When we introduce constructor arguments like this, we no longer have an ordinary switch statement that you can find in most programming languages. We call this *pattern matching* in Reason. 

In conjuction with data structures like variants, tuples, and lists, pattern matching creates a readable and concise flow of logic.

## Refactor with confidence

The only thing I have yet to do to make this example stronger, is validate the constructor inputs. So to send off this post with a bang, I am going to make some helper functions.

```reason
let validatePercentage = pct =>
  restrictRangef(pct, 0.0, 1.0);

let validateRgb = (red, blue, green) => {
  let red = restrictRange(red, 0, 255);
  let green = restrictRange(green, 0, 255);
  let blue = restrictRange(blue, 0, 255);
  (red, blue, green);
};
```

These functions validate the required input to the extend that they cut off the values if they are too low or too high. Here are their corresponding `restrictRange` functions.

```reason
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
```

One last thing to note is that we must have separate `restrictRange` functions for `int` and `float` types. By convention, when we have functions that take ints, their float variation will have the same name but with an "f" at the end.

A little extra code here is a small price to pay here when we have superior type coverage.

Finally I can update our `getMonthlyPriceForCarColor` function with our new helpers:

```reason
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
```

# And thats a wrap

We've taken a look at variants and how we can use them with constructor arguments through pattern matching. This is a super powerful feature that you won't find in just any modern programming language.

When you build an application with complete type safety, you begin to reap the advantages as the size of your project grows and you begin to make refactors. Knowing that your code compiles increases your confidence that you wont break critical or even basic features in production.
