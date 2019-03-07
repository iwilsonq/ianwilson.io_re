let str = ReasonReact.string;
let component = ReasonReact.statelessComponent("NewsletterSignup");

module Styles = {
  open Css;
  let label = style([color(hex("7e8a9a"))]);
  let input =
    style([
      border(px(1), `solid, hex("ced3d9")),
      borderRadius(px(4)),
      boxSizing(`borderBox),
      padding2(~v=em(0.75), ~h=em(1.0)),
      width(pct(100.)),
    ]);
  let form = style([backgroundColor(hex("#fff"))]);
  let button =
    style([
      backgroundColor(hex("db4d3f")),
      borderRadius(px(4)),
      border(px(0), `none, hex("ced3d9")),
      color(white),
      margin2(~v=px(16), ~h=`auto),
      padding2(~v=em(0.75), ~h=em(1.0)),
      width(pct(100.)),
    ]);
};

let make = _children => {
  ...component,
  render: _self =>
    <form
      action="https://buttondown.email/api/emails/embed-subscribe/iwilsonq"
      method="post"
      onSubmit={_event => ()}
      className=Styles.form>
      <h2> {"Ian's Spirits and Such Dev Newsletter" |> str} </h2>
      <p>
        {"If you want to stay in the loop with respect to what I'm currently building or learning about, "
         ++ "sign up for my newsletter. Emails go out roughly once every 1 - 2 weeks."
         |> str}
      </p>
      <label className=Styles.label htmlFor="bd-email">
        {"Email" |> str}
        <br />
        <input
          className=Styles.input
          type_="email"
          name="email"
          id="bd-email"
        />
      </label>
      <br />
      <input type_="hidden" value="1" name="embed" />
      <input className=Styles.button type_="submit" value="Subscribe" />
      <p>
        <i>
          {"I promise not to send you spam, only stimulating tech articles :) "
           |> str}
        </i>
      </p>
    </form>,
};
let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));