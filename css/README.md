## Template for STklos web site

We use the [w3.css](https://www.w3schools.com/lib/w3.css) framework. This is not the more popular one, but it
is sufficient to make simple static pages and avoid the use of
JavaScript.

## Code  Highlighting

We use the native Pandoc code highlighting. Its main advantage is that
the highlighting is computed at compile time and is then completely static.

Pandoc highlighting is a bit hard-coded (this is not true, since pandoc can
output a JSON file of a theme, but it is easier to manipulate a CSS file).
Since we don't directly use the pandoc template system. The script
`./build-highlight-css.sh` permits to exports all Pandoc highlight themes as
CSS files (they are of the form `hl-*.css`).
