//
// Created by warnawski on 08.09.2025.
//
#include <dirent.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/chdir.h"

int get_current_directory(char *buffer, size_t size)
{
    if (buffer == NULL)
    {
        perror("get_current_path");
        return 1;
    }
    if (getcwd(buffer, size) == NULL)
    {
        perror("getcwd");
        return 1;
    }
    return 0;
}

