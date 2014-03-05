
#include "describe/describe.h"
#include "parse-repo.h"

describe("parse_repo_owner", {
  char *owner = NULL;

  it("should return NULL when given an invalid slug", {
    assert(NULL == parse_repo_owner(NULL));
    assert(NULL == parse_repo_owner(""));
    assert(NULL == parse_repo_owner("/"));
    assert(NULL == parse_repo_owner("/@master"));
    assert(NULL == parse_repo_owner("@master"));
  });

  it("should support slugs with versions", {
    owner = parse_repo_owner("foo/bar@*");
    assert_str_equal("foo", owner);
    free(owner);

    owner = parse_repo_owner("foo/bar@baz");
    assert_str_equal("foo", owner);
    free(owner);

    owner = parse_repo_owner("foo/bar@10.11.12");
    assert_str_equal("foo", owner);
    free(owner);
  });

  #ifdef DEFAULT_REPO_OWNER
    it("should default to the defined owner", {
      owner = parse_repo_owner("bar@*");
      assert_str_equal(DEFAULT_REPO_OWNER, owner);
      free(owner);

      owner = parse_repo_owner("bar@baz");
      assert_str_equal(DEFAULT_REPO_OWNER, owner);
      free(owner);

      owner = parse_repo_owner("bar@10.11.12");
      assert_str_equal(DEFAULT_REPO_OWNER, owner);
      free(owner);
    });
  #endif
});
