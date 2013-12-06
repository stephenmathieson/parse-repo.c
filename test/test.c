
#include <stdlib.h>
#include <stdio.h>
#include "describe.h"
#include "parse-repo.h"

int main(void) {
  describe("parse_repo(str)", {
    it("should handle simple cases", {
      parsed_repo_t *repo = parse_repo("stephenmathieson/parse-repo.c@blahblah");
      assert_str_equal("stephenmathieson", repo->owner);
      assert_str_equal("parse-repo.c", repo->name);
      assert_str_equal("blahblah", repo->version);
      free(repo);
    });
    it("should use a default version", {
      parsed_repo_t *repo = parse_repo("stephenmathieson/parse-repo.c");
      assert_str_equal("stephenmathieson", repo->owner);
      assert_str_equal("parse-repo.c", repo->name);
      assert_str_equal("master", repo->version);
      free(repo);
    });
    it("should use a default owner", {
      parsed_repo_t *repo = parse_repo("parse-repo.c@foo");
      assert_str_equal("clibs", repo->owner);
      assert_str_equal("parse-repo.c", repo->name);
      assert_str_equal("foo", repo->version);
      free(repo);
    });
    it("should use a default owner and version", {
      parsed_repo_t *repo = parse_repo("parse-repo.c");
      assert_str_equal("clibs", repo->owner);
      assert_str_equal("parse-repo.c", repo->name);
      assert_str_equal("master", repo->version);
      free(repo);
    });
  });

  return assert_failures();
}
