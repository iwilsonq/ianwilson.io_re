import React from 'react'
import { graphql } from 'gatsby'

import Layout from '../../components/layout'
import MarkdownBlog from '../../../re/MarkdownBlog.bs'

const BlogPage = ({ data }) => {
  const markdownPosts = data.allMarkdownRemark.edges.map(edge => edge.node)
  return (
    <Layout>
      <h1>Homemade Blog Experience</h1>
      <p><em>Mainly ReasonML and whatever else I currently fancy</em></p>
      <MarkdownBlog posts={markdownPosts} />
    </Layout>
  )
}

export const PostsQuery = graphql`
  query PostsQuery {
    allMarkdownRemark {
      edges {
        node {
          tableOfContents(pathToSlugField: "frontmatter.path")
          frontmatter {
            path
            title
            date
          }
          id
          excerpt
        }
      }
    }
  }
`

export default BlogPage
