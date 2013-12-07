
#include <stdio.h>
#include "parse-repo.h"

int main() {
  char *repo = "stephenmathieson/parse-repo.c";
  parsed_repo_t *parsed = parse_repo(repo);
  printf("%s\n", repo);
  printf("  name: %s\n", parsed->name);
  printf("  owner: %s\n", parsed->owner);
  printf("  version: %s\n", parsed->version);
  parse_repo_free(parsed);
  return 0;
}
