
//
// parse-repo.c
//
// Copyright (c) 2013 Stephen Mathieson
// MIT licensed
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "parse-repo.h"
#include "substr.h"

/**
 * Parse `str` into a GitHub repo slug
 */

parsed_repo_t *parse_repo(const char *str) {
  parsed_repo_t *repo = malloc(sizeof(parsed_repo_t));

  int pos;

  // right of @ is version
  char *version;
  if ((version = strstr(str, "@"))) {
    pos = version - str;
    // drop @
    version++;
    repo->version = version;
  } else {
    repo->version = PARSE_REPO_DEFAULT_VERSION;
  }

  char *cpy;
  if (version) {
    // remove @*
    cpy = substr(str, 0, pos);
  } else {
    cpy = strdup(str);
  }

  char *name;
  // name is after slash
  if ((name = strstr(cpy, "/"))) {
    pos = name - cpy;
    name++;
    repo->name = name;
    repo->owner = substr(cpy, 0, pos);
    repo->slug = cpy;
  } else {
    repo->owner = PARSE_REPO_DEFAULT_OWNER;
    repo->name = cpy;
    repo->slug = malloc(sizeof(char)
                        * strlen(repo->owner)
                        + strlen(repo->name)
                        + 1);
    sprintf(repo->slug, "%s/%s", repo->owner, repo->name);
  }

  return repo;
}

/**
 * Free `repo`
 */

void parse_repo_free(parsed_repo_t *repo) {
  free(repo);
  repo = NULL;
}
