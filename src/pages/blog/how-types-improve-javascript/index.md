---
title: How a Type System Improves your JavaScript Code
date: 2019-02-24T21:25:04.540Z
path: how-types-improve-javascript
description: Discover how a type system improves your developer workflow
tags: reasonm,react,javascript,typescript
---

Vanilla JavaScript is untyped by nature, some will call it “smart” because it is able to figure out what is a number or a string.

This makes it easier to run JavaScript code, it simply needs to be executed in a browser or Node.js runtime. However, its vulnerable to numerous runtime errors that can spoil your user experience.

If you’ve ever experienced the following, you would benefit from adopting a type system.

- After fetching a list of data you may find that a certain field doesn’t exist on one of the records, causing the app to crash unless explicitly handled.
- An instance of a class you imported doesn’t have a method you’re trying to invoke.
- Your IDE doesn’t know what methods and properties are available, so it cannot easily assist you with autocomplete.
- Difficulty reasoning about code, type systems at a glance make it easier to refactor

## Flow, TypeScript, or ReasonML

Let's say you have an existing codebase that you wish to make bulletproof. With respect to type errors, you could try adopting Flow or TypeScript -- they have a fairly similar syntax.

On the other hand adopting one of these in a large, existing codebase is difficult. You would have a backlog crammed with tasks relating to creating types and interfaces with code that made not have been designed in a type friendly way.

On top of all of this, Flow and TypeScript do not offer 100% type safety in their code.

Reason accomplished perfect type safety through inference, and makes annotating variables and function signatures much more straightforward. 

## Simple and Clearly Contrived Examples

Consider the following code:

```reason
let add = (a, b) => a + b;
```

In basic JavaScript these arguments can be numbers or strings. In TypeScript or Flow these arguments can be annotated like so

```javascript
let add = (a: number, b: number) => a + b
```

The first code snippet knows that we are adding two int values. Not two floats nor two strings, there are different operators for those addition operations. JavaScript can hardly tell the difference between an int and a float.

Allow me now to expose this gradual typing with a contrived example.

```javascript
let add = (a: string, b: number) => a + b
add('some string', 5) // outputs: "some string5"
```

That function works! This is absolutely preposterous! Now how does Reason handle this?

```reason
let add = (a, b) => a + b;
add("some string", 5);
/*
This has type:
  string
but somewhere wanted:
  int
*/
```

This function was flawed at the implementation level. Reason has different operators for int, float, and string addition. 

The purpose of this contrived example was to show that it is still very possible to have odd type "errors" even though it wont _break_ the application.

In a pure Reason program, developers will not have to deal with productions bugs that have to do with types or null values.

## Developer Experience

One of the neatest features of TypeScript is the enhancement you get in code editor suggestions & autocompletion.

This is one area where TypeScript has a leg up on Reason, because a TypeScript program doesn't need to compile perfectly in order to offer autocompletion. Reason makes you fix errors in syntax or types before it gives you helpful autosuggestion. 

This is the case on VSCode, but I know many Reason developers use vim. I cannot answer for the level of support each editor has.

Even though I am a big fan of ReasonML, I have built production applications with TypeScript or Flow and I enjoy them as well. The wave behind TypeScript makes it especially good to pick up these days, considering there is plenty of writing and community support behind it.

Reason on the other hand is harder to pick up because there is comparatively less writing and content behind it. Through blog posts like this, I am hoping to change that. 

If you have some interest in checking out Reason, I'd start with the [docs here](https://reasonml.github.io). Also, be sure to follow people like [@jordwalke](https://twitter.com/@jordwalke), [@jaredforsyth](https://twitter.com/@jaredforsyth), and [@sgrove](https://twitter.com/@sgrove) on twitter. They are pretty knowledgable with respect to the ReasonML/OCaml ecosystem.

If you want to how ReasonML works seamlessly with GraphQL, check out this article I wrote on [ReasonML with GraphQL, the Future of Type-Safe Web Applications](https://medium.com/open-graphql/reasonml-with-graphql-the-future-of-type-safe-web-applications-65be2e8f34c8).
