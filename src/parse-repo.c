
//
// parse-repo.c
//
// Copyright (c) 2013 Stephen Mathieson
// MIT licensed
//

#include <string.h>
#include <stdlib.h>
#include "parse-repo.h"
#include "substr.h"

parsed_repo_t *parse_repo(const char *str) {
  parsed_repo_t *repo = malloc(sizeof(parsed_repo_t));

  int pos;

  char *version;
  if ((version = strstr(str, "@"))) {
    pos = version - str;
    version++;
    repo->version = version;
  } else {
    repo->version = PARSE_REPO_DEFAULT_VERSION;
  }

  char *cpy;
  if (version) {
    cpy = substr(str, 0, pos);
  } else {
    cpy = strdup(str);
  }

  char *name;
  if ((name = strstr(cpy, "/"))) {
    pos = name - cpy;
    name++;
    repo->name = name;
    repo->owner = substr(cpy, 0, pos);
  } else {
    repo->owner = PARSE_REPO_DEFAULT_OWNER;
    repo->name = cpy;
  }

  return repo;
}
