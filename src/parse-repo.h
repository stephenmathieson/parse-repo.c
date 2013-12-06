
#ifndef __PARSE_REPO__
#define __PARSE_REPO__ 1

#define PARSE_REPO_DEFAULT_OWNER   "clibs"
#define PARSE_REPO_DEFAULT_VERSION "master"

typedef struct {
  const char *owner;
  const char *name;
  const char *version;
} parsed_repo_t;

parsed_repo_t *parse_repo(const char *str);

#endif
