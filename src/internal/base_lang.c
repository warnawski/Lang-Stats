//
// Created by warnawski on 11.09.2025.
//
#include "../include/lstat.h"

void init_all_ext()
{
    const char *ext[] = {
        "c", "py", "go", "cpp", "js", "rs", "h",
    };
    add_ext(ext, sizeof(ext) / sizeof(ext[0]));
}

void init_all_lang()
{
    const char *langs[] = {
        "C", "Python", "Go", "C++", "JavaScript", "Rust", "Header C file",
    };

    const char *ext[] = {
        "c", "py", "go", "cpp", "js", "rs", "h",
    };

    pub_add_lang(ext, langs, sizeof(langs) / sizeof(langs[0]));
}