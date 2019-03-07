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
      ->Belt_SortArray.stableSortBy((postA, postB) =>
          postA##frontmatter##date < postB##frontmatter##date ? 1 : (-1)
        )
      ->Belt_Array.map(post => <MarkdownPost key=post##id post />)
      ->ReasonReact.array;
    <div> renderPosts </div>;
  },
};

let default =
  ReasonReact.wrapReasonForJs(~component, jsProps =>
    make(~posts=jsProps##posts, [||])
  );