let str = ReasonReact.string;
let component = ReasonReact.statelessComponent("Index");

module Styles = {
  open Css;
  let link = style([color(hex("db4d3f")), textDecoration(none)]);
};

[@react.component]
let make = () => {
  <div>
    <h1> {"Ian Wilson: JavaScript, ReasonML, and GraphQL" |> str} </h1>
    <p>
      {"I am Ian and I like to code and run, though not simultaneously." |> str}
    </p>
    <p> {"Sometimes you can find me..." |> str} </p>
    <ul>
      <li>
        {"tweeting about web development and tech on twitter " |> str}
        <a href="https://twitter.com/iwilsonq" target="_blank">
          {"@iwilsonq" |> str}
        </a>
      </li>
      <li>
        {"blogging about all stack development on " |> str}
        <a href="https://medium.com/@iwilsonq"> {"Medium" |> str} </a>
        {" or on " |> str}
        <a href="https://dev.to/iwilsonq" target="_blank">
          {"dev.to" |> str}
        </a>
      </li>
      <li>
        {"attempting to record videos on Youtube and Twitch (coming soonish)"
         |> str}
      </li>
      <li>
        {"running about in the hills of the " |> str}
        <a href="https://instagram.com/iwilsonq" target="_blank">
          {"SF Bay Area" |> str}
        </a>
      </li>
    </ul>
    <p>
      {"Tech note for the curious: this blog is bootstrapped with Gatsby and most of the components are built with ReasonML. The repo exists "
       |> str}
      <a href="https://github.com/iwilsonq/ianwilson.io_re" target="_blank">
        {"on Github." |> str}
      </a>
    </p>
    <p>
      <strong>
        {"Looking to learn more about ReasonML or whatever else I'm working on?"
         |> str}
      </strong>
      <br />
      <Gatsby.Link _to="/blog" className=Styles.link>
        {"Definitely check out the blog" |> str}
      </Gatsby.Link>
    </p>
    <Divider />
    <Newsletter />
  </div>;
};

let default = make;