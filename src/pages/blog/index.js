import React from 'react'
import { graphql } from 'gatsby'

import Layout from '../../components/layout'
import MarkdownBlog from '../../../re/MarkdownBlog.bs'
import MediumBlog from '../../../re/MediumBlog.bs'

const BlogPage = ({ data }) => {
  const markdownPosts = data.allMarkdownRemark.edges.map(edge => edge.node)
  const mediumPosts = data.allMediumPost.edges.map(edge => edge.node)
  return (
    <Layout>
      <h1>Homemade Blog Experience</h1>
      <p><em>Mainly ReasonML and whatever else I currently fancy</em></p>
      <MarkdownBlog posts={markdownPosts} />

      <h2>From Other Mediums</h2>
      <MediumBlog posts={mediumPosts} />
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
    allMediumPost {
      edges {
        node {
          id
          title
          uniqueSlug
          createdAt(formatString: "dddd, MMMM D, YYYY")
          virtuals {
            tags {
              name
            }
          }
          previewContent {
            subtitle
            bodyModel {
              paragraphs {
                type
                metadata {
                  id
                }
              }
            }
          }
        }
      }
    }
  }
`

export default BlogPage
