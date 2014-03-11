
#include "describe/describe.h"
#include "parse-repo.h"

describe("parse_repo_version", {
  char *version = NULL;

  it("should return NULL when given an invalid slug", {
    assert(NULL == parse_repo_version(NULL, NULL));
    assert(NULL == parse_repo_version("", NULL));
    assert(NULL == parse_repo_version("/", NULL));
  });

  it("should support omitting owner", {
    version = parse_repo_version("foo@bar", "master");
    assert_str_equal("bar", version);
    free(version);

    version = parse_repo_version("foo@1.0.0", "master");
    assert_str_equal("1.0.0", version);
    free(version);

    version = parse_repo_version("foo@x.y.z", "master");
    assert_str_equal("x.y.z", version);
    free(version);
  });

  it("should support owner/name@version", {
    version = parse_repo_version("foo/bar@baz", "master");
    assert_str_equal("baz", version);
    free(version);
  });

  it("should use the fallback when one is set", {
    version = parse_repo_version("foo/bar", "master");
    assert_str_equal("master", version);
    free(version);
  });
});
