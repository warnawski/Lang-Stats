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
        "c", "py", "go", "cpp", "js", "rs", "h", "java", "cs", "php", "sh", "hpp", "clj", "cr", "dart", "pas", "ex",
        "swift", "kt", "m", "mm", "rb", "ts", "scala", "vb", "pl", "pm", "r", "jl", "lua", "hs", "lhs", "fs", "fsi",
        "fsscript", "ml", "mli", "erl", "hrl", "exs", "scm", "ss", "lisp", "el", "awk", "tcl", "ada", "d", "nim",
        "zig", "vala", "vbnet", "asm", "s", "v", "sv", "vhd", "sql", "prc", "ada", "cbl", "f", "f90", "for", "bas",
        "m4", "groovy", "gradle", "hx", "pro", "cl", "idl", "rego", "cue", "ipynb", "md", "tex", "bib", "xml", "yml",
        "yaml", "json", "toml", "ini"
    };

    const char *langs[] = {
        "C", "Python", "Go", "C++", "JavaScript", "Rust", "Header C file", "Java", "C#", "PHP", "Bash", "Header C++ file",
        "Clojure", "Crystal", "Dart", "Pascal", "Elixir", "Swift", "Kotlin", "Objective-C", "Objective-C++",
        "Ruby", "TypeScript", "Scala", "Visual Basic", "Perl", "Perl Module", "R", "Julia", "Lua", "Haskell", "Literate Haskell",
        "F#", "F# Interface", "F# Script", "OCaml", "OCaml Interface", "Erlang", "Erlang Header", "Elixir Script", "Scheme",
        "Scheme Script", "Common Lisp", "Emacs Lisp", "Awk", "Tcl", "Ada", "D", "Nim", "Zig", "Vala", "VB.NET",
        "Assembly", "Assembly (AT&T/Intel)", "Verilog", "SystemVerilog", "VHDL", "SQL", "Procedural SQL", "Ada (dup)",
        "COBOL", "Fortran", "Fortran 90", "Fortran (legacy)", "BASIC", "M4 Macro", "Groovy", "Gradle Script", "Haxe",
        "Prolog", "OpenCL", "IDL", "Rego", "CUE", "Jupyter Notebook", "Markdown", "LaTeX", "BibTeX", "XML",
        "YAML", "YAML", "JSON", "TOML", "INI"
    };

    size_t count = sizeof(ext) / sizeof(ext[0]);

    init_all_ext(ext, count);
    init_all_lang(ext, langs, count);
}
