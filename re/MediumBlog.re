let str = ReasonReact.string;

type post = {
  .
  id: string,
  title: string,
  subtitle: string,
  uniqueSlug: string,
  createdAt: string,
  tags: list(string),
};

let component = ReasonReact.statelessComponent("MediumBlog");

let make = (~posts, _children) => {
  ...component,
  render: _self => {
    let renderPosts =
      posts
      ->Belt_Array.map(post => <MediumPost key=post##id post />)
      ->ReasonReact.array;
    <div> renderPosts </div>;
  },
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~posts=jsProps##posts, [||])
  );