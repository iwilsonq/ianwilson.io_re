module Styles = {
  open Css;
  let header =
    style([backgroundColor(hex("db4d3f")), marginBottom(px(16))]);
  let h1 = style([margin(px(0))]);
  let link =
    style([color(white), textDecoration(none), marginRight(px(16))]);
  let nav =
    style([
      display(`flex),
      alignItems(`center),
      justifyContent(`spaceBetween),
      margin2(~v=px(0), ~h=`auto),
      maxWidth(px(1000)),
      padding2(~v=px(0), ~h=px(24)),
    ]);
  let logo =
    style([height(px(64)), marginRight(px(36)), marginTop(px(8))]);
};

[@react.component]
let make = (~siteTitle) => {
  Js.log(siteTitle);
  <header className=Styles.header>
    <nav className=Styles.nav>
      <Gatsby.Link _to="/" className=Styles.link>
        <img className=Styles.logo src="/images/iw-logo-1.png" alt="logo" />
      </Gatsby.Link>
      <div>
        <Gatsby.Link _to="/blog" className=Styles.link>
          {"Blog" |> ReasonReact.string}
        </Gatsby.Link>
        <Gatsby.Link _to="/" className=Styles.link>
          {"About" |> ReasonReact.string}
        </Gatsby.Link>
      </div>
    </nav>
  </header>;
};

let default = make;