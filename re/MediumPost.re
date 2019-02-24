let str = ReasonReact.string;

module Styles = {
  open Css;
  let article = style([marginBottom(px(32))]);
  let link =
    style([
      textDecoration(`none),
      hover([textDecoration(`underline), textDecorationColor(red)]),
    ]);
  let h2 = style([color(red)]);
  let p = style([color(black)]);
  let date = style([color(darkgray)]);
};

let component = ReasonReact.statelessComponent("MediumPost");

let make = (~post, _children) => {
  ...component,
  render: _self =>
    <article className=Styles.article>
      <a
        className=Styles.link
        href={"https://medium.com/@iwilsonq/" ++ post##uniqueSlug}
        rel="noopener noreferrer"
        target="_blank">
        <h2 className=Styles.h2> {post##title |> str} </h2>
      </a>
      <small className=Styles.date>
        {post##createdAt}
      </small>
    </article>,
};