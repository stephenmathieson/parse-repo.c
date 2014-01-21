//
// parse-repo.h
//
// Copyright (c) 2013 Stephen Mathieson
// MIT licensed
//

#ifndef PARSE_REPO_H
#define PARSE_REPO_H 1

#define PARSE_REPO_DEFAULT_OWNER   "clibs"
#define PARSE_REPO_DEFAULT_VERSION "master"

typedef struct {
  const char *owner;
  const char *name;
  const char *version;
  char *slug;
} parsed_repo_t;

parsed_repo_t *parse_repo(const char *str);

void parse_repo_free(parsed_repo_t *repo);


#endif
