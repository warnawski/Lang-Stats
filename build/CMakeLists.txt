cmake_minimum_required(VERSION 4.0)

project(project-stats C)

set(CMAKE_C_STANDARD 23)

add_executable(project-stats
        ../src/main/main.c
        ../src/internal/checked_dir_linux.c
        ../src/include/chdir.h
        ../src/internal/base_lang.c
        ../src/include/lstat.h
        ../src/internal/lstat.c

)