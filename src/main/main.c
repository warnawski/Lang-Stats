//
// Created by warnawski on 07.09.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/chdir.h"


#define CLI_VERSION "0.0.1"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        perror("Wrong number of arguments");
        return 1;
    }

    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
    {
        printf("");
        return 0;
    }

    else if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0)
    {
        printf("LangStat Version: %s\n", CLI_VERSION);
    }
    else if (strcmp(argv[1], "--fetch") == 0 || strcmp(argv[1], "--f") == 0)
    {
        char *buffer = malloc(4096);
        if (!buffer)
        {
            perror("malloc");
            exit(1);
        }
        get_current_directory(buffer, 4096);
        printf("VOT %s\n", buffer);
        free(buffer);
        return 0;
    }
    else
    {
        perror("Unknown command, please send command '--help'");
        return 1;
    }
}
