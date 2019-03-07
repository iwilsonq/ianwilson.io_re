let component = ReasonReact.statelessComponent("Divider");

module Styles = {
  open Css;
  let hr =
    style([
      borderBottom(px(0), `none, black),
      borderTop(px(1), `solid, hex("ccc")),
      margin2(~v=px(24), ~h=`auto),
    ]);
};

let make = _children => {
  ...component,
  render: _self => <hr className=Styles.hr />,
};

let default = ReasonReact.wrapReasonForJs(~component, _jsProps => make([||]));