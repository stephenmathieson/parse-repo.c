
#include "describe/describe.h"
#include "parse-repo.h"

describe("parse_repo_version", {
  char *version = NULL;

  it("should return NULL when given an invalid slug", {
    assert(NULL == parse_repo_version(NULL));
    assert(NULL == parse_repo_version(""));
    assert(NULL == parse_repo_version("/"));
  });

  it("should support omitting owner", {
    version = parse_repo_version("foo@bar");
    assert_str_equal("bar", version);
    free(version);

    version = parse_repo_version("foo@1.0.0");
    assert_str_equal("1.0.0", version);
    free(version);

    version = parse_repo_version("foo@x.y.z");
    assert_str_equal("x.y.z", version);
    free(version);
  });

  it("should support owner/name@version", {
    version = parse_repo_version("foo/bar@baz");
    assert_str_equal("baz", version);
    free(version);
  });

  #ifdef DEFAULT_REPO_VERSION
    it("should use the default when one is set", {
      version = parse_repo_version("foo/bar");
      assert_str_equal(DEFAULT_REPO_VERSION, version);
      free(version);
    });
  #endif
});
