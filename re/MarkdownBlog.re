let str = ReasonReact.string;

type post = {
  .
  "id": string,
  "excerpt": string,
  "frontmatter": {
    .
    title: string,
    date: string,
  },
};

let component = ReasonReact.statelessComponent("MarkdownBlog");

let make = (~posts, _children) => {
  ...component,
  render: _self => {
    let renderPosts =
      posts
      |> Array.map(post => <MarkdownPost key=post##id post />)
      |> ReasonReact.array;
    <div> renderPosts </div>;
  },
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~posts=jsProps##posts, [||])
  );