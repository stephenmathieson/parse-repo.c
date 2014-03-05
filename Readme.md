
# parse-repo

  Parse GitHub-style repo slugs.

## Installation

  Install with [clib(1)](https://github.com/clibs/clib):

    $ clib install stephenmathieson/parse-repo.c

## API

```c

/**
 * Parse the repo owner from the given slug.
 *
 * If no owner is provided and `DEFAULT_REPO_OWNER`
 * is defined, will return a pointer to a copy of
 * `DEFAULT_REPO_OWNER`.
 *
 * Free the result when you're done with it.
 */

char *
parse_repo_owner(const char *);

/**
 * Parse the repo name from the given slug.
 *
 * Free the result when you're done with it.
 */

char *
parse_repo_name(const char *);

/**
 * Parse the repo version from the given slug.
 *
 * If no version is provided and `DEFAULT_REPO_VERSION`
 * is defined, will return a pointer to a copy of
 * `DEFAULT_REPO_VERSION`.
 *
 * Free the result when you're done with it.
 */

char *
parse_repo_version(const char *);

```


## License

(The MIT License)

Copyright (c) 2013 Stephen Mathieson &lt;me@stephenmathieson.com&gt;

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
'Software'), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.