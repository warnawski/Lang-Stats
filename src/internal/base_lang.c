//
// Created by warnawski on 11.09.2025.
//
#include "../include/lstat.h"

void init_all_ext(const char *ext[], size_t count)
{
    add_ext(ext, count);
}

void init_all_lang(const char *ext[], const char *langs[], size_t count)
{

    pub_add_lang(ext, langs, count);
}

void init_st()
{
    const char *ext[] = {
        "c", "py", "go", "cpp", "js", "rs", "h", "java", "cs", "php", "sh", "hpp", "clj", "cr", "dart", "pas", "ex"
    };

    const char *langs[] = {
        "C", "Python", "Go", "C++", "JavaScript", "Rust", "Header C file", "Java", "C#", "PHP", "Bash", "Header C++ file" , "Clojure", "Crystal", "Dart", "Pascal", "Elexir"
    };

    size_t count = sizeof(ext) / sizeof(ext[0]);

    init_all_ext(ext, count);
    init_all_lang(ext, langs, count);
}
