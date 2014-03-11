
#include "describe/describe.h"
#include "parse-repo.h"

describe("parse_repo_owner", {
  char *owner = NULL;

  it("should return NULL when given an invalid slug", {
    assert(NULL == parse_repo_owner(NULL, NULL));
    assert(NULL == parse_repo_owner("", NULL));
    assert(NULL == parse_repo_owner("/", NULL));
    assert(NULL == parse_repo_owner("/@master", NULL));
    assert(NULL == parse_repo_owner("@master", NULL));
  });

  it("should support slugs with versions", {
    owner = parse_repo_owner("foo/bar@*", NULL);
    assert_str_equal("foo", owner);
    free(owner);

    owner = parse_repo_owner("foo/bar@baz", NULL);
    assert_str_equal("foo", owner);
    free(owner);

    owner = parse_repo_owner("foo/bar@10.11.12", NULL);
    assert_str_equal("foo", owner);
    free(owner);
  });

  it("should default to the fallback for valid slugs", {
    owner = parse_repo_owner("bar@*", "foo");
    assert_str_equal("foo", owner);
    free(owner);

    owner = parse_repo_owner("bar@baz", "foo");
    assert_str_equal("foo", owner);
    free(owner);

    owner = parse_repo_owner("bar@10.11.12", "foo");
    assert_str_equal("foo", owner);
    free(owner);
  });
});
