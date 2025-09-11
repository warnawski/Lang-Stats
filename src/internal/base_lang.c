//
// Created by warnawski on 11.09.2025.
//
#include "../include/lstat.h"

void init_all_ext()
{
    const char *ext[] = {
        "c", "py", "go", "cpp", "js", "rs", "h",
    };
    add_lang(ext, 7);
}

void init_all_lang()
{
    const char *langs[] = {
        "C", "Python", "Go", "C++", "JavaScript", "Rust", "Header C file",
    };

    const char *ext[] = {
        "c", "py", "go", "cpp", "js", "rs", "h",
    };
}