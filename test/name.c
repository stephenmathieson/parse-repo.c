
#include "describe/describe.h"
#include "parse-repo.h"

describe("parse_repo_name", {
  char *name = NULL;

  it("should return NULL when given an invalid slug", {
    assert(NULL == parse_repo_name(NULL));
    assert(NULL == parse_repo_name(""));
    assert(NULL == parse_repo_name("/"));
    assert(NULL == parse_repo_name("/@master"));
    assert(NULL == parse_repo_name("@master"));
  });

  it("should support slugs with versions", {
    name = parse_repo_name("foo/bar@*");
    assert_str_equal("bar", name);
    free(name);

    name = parse_repo_name("foo/bar@baz");
    assert_str_equal("bar", name);
    free(name);

    name = parse_repo_name("foo/bar@10.11.12");
    assert_str_equal("bar", name);
    free(name);
  });

  it("should support slugs omitting owner", {
    name = parse_repo_name("bar@*");
    assert_str_equal("bar", name);
    free(name);

    name = parse_repo_name("bar@baz");
    assert_str_equal("bar", name);
    free(name);

    name = parse_repo_name("bar@10.11.12");
    assert_str_equal("bar", name);
    free(name);
  });

  it("should fail on slugs omitting name", {
    assert(NULL == parse_repo_name("foo/@*"));
    assert(NULL == parse_repo_name("foo/@baz"));
    assert(NULL == parse_repo_name("foo/@10.11.12"));
  });
});
