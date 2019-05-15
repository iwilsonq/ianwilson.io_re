---
title: The Edge, Wit, and Courage of ReasonML
date: 2019-03-19T21:25:04.540Z
path: edge-wit-courage-reasonml
description: Discover the features of Reason that make it so appealing to a JavaScript developer.
tags: reason,ocaml,javascript,fp
---

ReasonML has stolen my attention recently.

If I'm not at work or running about, I am probably digging into some ReasonML/OCaml repositories like an addict in the tenderloin.

Perhaps I like it for the unparalleled incremental build speed.

Perhaps I like it because its not too different from JavaScript yet it nets me a plethora of built-in advantages like type safety.

Perhaps I like it because of my affinity for math in school, and the functional paradigm gives me a warm fuzzy feeling inside.

There are a few reasons, no pun intended, for my love of Reason. Just like a functional program wields function composition with immutable state to achieve its goal, Reason's composition of the best of OCaml and JavaScript make it a strong candidate for the future of programming.

## The Edge of OCaml

For starters, Reason is basically a syntax upgrade to OCaml. Let me start by describing how that helps us.

### Speed

OCaml is a pretty damn fast language. It's incremental build times dwarf that of almost any other language. Since Reason is just a toolchain on top of OCaml, it maintains the many of the same characteristics of OCaml.

For instance take a look at this table from the docs of [fastpack](https://fastpack.sh), an alternative to Webpack or Parcel for bundling JavaScript applications.

_~1100 modules / 5.3Mb / MB Pro 2017_

|                  | Fastpack | Webpack | Parcel |
| ---------------- | -------- | ------- | ------ |
| initial build    | 0.811s   | 3.86s   | 11.07s |
| persistent cache | 0.208s   | N/A     | 1.39s  |
| watch mode       | 0.088s   | 0.226s  | 0.291s |

Fastpack is still rather new but these numbers are promising -- and the result implies we can made super-quick devtools for a vanilla JavaScript workflow.

### Static Typing

Another thing Reason inherits from OCaml is a power, nearly impenetrable type system. The compiler does a solid job of making sure you exhaust all of your options in branching logic.

It also does away with silly errors like "undefined is not a function" or "cannot read property 'x'". The same could be said about adopting TypeScript or Flow, but they do not _force_ you to cover such cases.

### ...with Great Inference

It's powerful type inference cleans up a lot of the verbosity associated with annotating functions and variables with types. The following function adds two integers. Not two floats or two strings, just two integers.

```reason
  /* the type system knows that the arguments and the return value are ints here */
  let add = (a, b) => a + b;
```

If that example is too basic, then try this one. Note how I am not annotating the types in the function signatures:

```reason
  type animal =
    | Dog
    | Cat
    | Octopus;

  let animalToString = animal =>
    switch(animal) {
    | Dog => "dog"
    | Cat => "cat"
    | Octopus => "octopus"
    };

  let getWelcomeMessage = (name, visits, animal) => {
    "Hello " ++
    name ++
    ", you've visited this website " ++
    string_of_int(visits) ++
    " times and your favorite animal is the " ++
    animalToString(animal);
  };
```
The ReasonML/OCaml type system is capable of inferring based on our usage what the return types are, as well as each of the arguments. How neat is that?

### Industry Proven

OCaml is a proven language of academics and industries where safety and mission critical code is paramount. This was one of the reason's it was adopted as the base for ReasonML.

At Facebook, OCaml is used to build some of their important everyday tools, like [Flow](https://flow.org) and [Hack](https://hacklang.org). But they're also working on Reason, which in my opinion, is neat because Reason brings more joy than flow.

## The Wit of JavaScript

With Reason comes a lighter, more JavaScript-like syntax. The first example I showed above would work just as well in regular JavaScript. 

### Syntax

Reason syntax is far easier to read and digest than that of OCaml, and most other functional languages for that matter.

### Easy Build System

Its massively more accessible to newcomers than OCaml in that you probably wont spend days trying to install your dependencies properly. When using BuckleScript its often just another npm install {package}.

### JavaScript Interop

If you need training wheels when writing Reason, do not fear. You can use special directives to write JavaScript directly in your Reason code. Its not cheating, the language was designed this way to make migrating codebases easier.

### NodeJS Too

The language that powers web applications can be used on the server with the help of NodeJS. The language being Reason of course. Since it transpiles to JavaScript, theres no reason you cannot simply write Reason which becomes server code.

You can write basically everything in your tech stack with JavaScript and in most cases it will be just fine. What motive would someone have to write Reason then, especially if they have built their likely profitable career on JavaScript?

## The Courage of Reason

Over the past few weeks, I've been exploring writing Native Reason code. I think some of the projects that are being developed show great courage in showing off the potential of ReasonML.

While I certainly appreciate it's benefits on the frontend when transpiled to JavaScript, it would be super neat if I could write it on the server too.

I want to communicate with databases, make blazing quick command line tools, and write super efficient servers, perhaps serving GraphQL.

And I want to do it with the same language that I'm writing in for my web applications.

Currently, we can do this with JavaScript, but I think we can do better.

By further leveraging the OCaml ecosystem we can actually write incredibly robust servers and developer tools.

The [Esy](https://esy.sh) package manager allows us to install and build packages from npm or opam in a convenient package.json fashion without having to manually hack system dependencies.

As Esy further develops, Reason on the backend will become increasingly more accessible to developers looking to write stupidly fast native code.

If you're interested in what's already been made with Esy, check out the following projects:

- [fnm](https://github.com/Schniz/fnm), an alternative to nvm for managing your NodeJS version. It's much faster than nvm.
- [fastpack](https://fastpack.sh/), a ridiculously fast JavaScript bundler
- [revery](https://www.outrunlabs.com/revery/), a desktop UI framework like electron, except without downloading a whole browser onto your users' computer.

And there are more out there in the **Forests of Open Source**.

This certainly won't be my last post on this topic so stay tuned for more Reason evangelism on the horizon.
