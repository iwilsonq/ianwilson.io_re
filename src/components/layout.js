import React from 'react'
import PropTypes from 'prop-types'
import Helmet from 'react-helmet'
import { StaticQuery, graphql } from 'gatsby'
import './styles.css'

import Header from '../../re/Header.bs'

const Layout = ({ children }) => (
  <StaticQuery
    query={graphql`
      query SiteTitleQuery {
        site {
          siteMetadata {
            title
          }
        }
      }
    `}
    render={data => (
      <>
        <Helmet
          title={data.site.siteMetadata.title}
          meta={[
            {
              name: 'description',
              content: 'Static site built with Gatsbyjs, ReasonML, and React.',
            },
            { name: 'keywords', content: 'reasonml, bucklescript, react' },
          ]}
        >
          <html lang="en" />
        </Helmet>
        <Header siteTitle={data.site.siteMetadata.title} />
        <div
          style={{
            fontFamily:
              '-apple-system,BlinkMacSystemFont,Segoe UI,Helvetica,Arial,sans-serif',
            lineHeight: 1.6,
            margin: '0 auto',
            maxWidth: 700,
            padding: '0px 1.0875rem 1.45rem',
            paddingTop: 0,
          }}
        >
          {children}
        </div>
      </>
    )}
  />
)

Layout.propTypes = {
  children: PropTypes.node.isRequired,
}

export default Layout
