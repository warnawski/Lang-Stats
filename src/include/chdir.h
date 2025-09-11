//
// Created by warnawski on 08.09.2025.
//

#ifndef PROJECT_STATS_CHDIR_H
#define PROJECT_STATS_CHDIR_H
#include "../include/lstat.h"

int get_current_directory(char *buffer, size_t size);

int directory_traversal();

#endif //PROJECT_STATS_CHDIR_H