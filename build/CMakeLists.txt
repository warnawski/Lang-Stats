cmake_minimum_required(VERSION 4.0)

project(lang-stats LANGUAGES C CXX)

set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(lang-stats
        ../src/internal/checked_dir_linux.c
        ../src/include/chdir.h
        ../src/internal/base_lang.c
        ../src/include/lstat.h
        ../src/internal/lstat.c
        ../src/main/main.cpp

)