module Styles = {
  open Css;
  let hr =
    style([
      borderBottom(px(0), `none, black),
      borderTop(px(1), `solid, hex("ccc")),
      margin2(~v=px(24), ~h=`auto),
    ]);
};

[@react.component]
let make = () => <hr className=Styles.hr />;

let default = make;