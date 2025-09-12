//
// Created by warnawski on 12.09.2025.
//

#ifndef PROJECT_STATS_LSTAT_H
#define PROJECT_STATS_LSTAT_H
#include "../include/uthash.h"

typedef struct pub_stat
{
    char ext[16];
    char *language;
    UT_hash_handle hh;
} Public_stat;

extern Public_stat *statistics;



typedef struct info_stat
{
    char ext[16];
    long lines;
    UT_hash_handle hh;
} Info_stat;

extern Info_stat *extension;

void add_lines(const char *ext, long lines);

void add_ext(const char **ext, size_t count);

void init_all_ext(const char *ext[], size_t count);

void pub_add_lang(const char **ext, const char **lang, size_t count);

void init_all_lang(const char *ext[], const char *langs[], size_t count);

void init_st();

void print_lines_per_language();

#endif //PROJECT_STATS_LSTAT_H