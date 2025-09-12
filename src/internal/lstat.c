//
// Created by warnawski on 12.09.2025.
//
#include "../include/lstat.h"
#include <stdio.h>

Public_stat *statistics = NULL;
Info_stat *extension = NULL;

void add_lines(const char *ext, long lines)
{
    Info_stat *i;
    HASH_FIND_STR(extension, ext, i);
    if (i == NULL)
    {
        i = calloc(1, sizeof(Info_stat));
        strcpy(i->ext, ext);
        i->lines = lines;
        HASH_ADD_STR(extension, ext, i);
    } else
    {
        i->lines += lines;
    }
}

void add_ext(const char **ext, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        Info_stat *s = calloc(1, sizeof(Info_stat));
        strcpy(s->ext, ext[i]);
        s->lines = 0;
        HASH_ADD_STR(extension, ext, s);
    }
}

void pub_add_lang(const char **ext, const char **lang, size_t count)
{
    for (size_t i = 0; i < count; i++)
    {
        Public_stat *p = calloc(1, sizeof(Public_stat));
        strncpy(p->ext, ext[i], sizeof(p->ext) - 1);
        p->ext[sizeof(p->ext) - 1] = '\0';
        p->language = strdup(lang[i]);
        HASH_ADD_STR(statistics, ext, p);
    }
}

void print_lines_per_language()
{
    Public_stat *p, *tmp;
    Info_stat *info;
    long total_lines = 0;
    HASH_ITER(hh, statistics, p, tmp) {
        HASH_FIND_STR(extension, p->ext, info);
        long lines_count = info ? info->lines : 0;
        if (lines_count > 0)
        {
            printf("%s: %ld lines\n", p->language, lines_count);
            total_lines += lines_count;
        }
    }
    printf("<-------------------------->\n");
    printf("TOTAL LINES: %ld\n", total_lines);
}