//
// Created by warnawski on 07.09.2025.
//

#include <stdio.h>
#include <string.h>

#define VERSION "0.0.1"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        perror("Wrong number of arguments");
        return 1;s
    }

    if (strcmp(argv[1], "--help") == 0)
    {
        printf("Usage: %s [OPTIONS]\n", argv[0]);
    }
    else if (strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-V") == 0)
    {
        printf("%s\n", VERSION);
    }
    else if (strcmp(argv[1], "--fetch") == 0)
    {

    }
    else
    {
       perror("Unknown command");
       return 1;
    }
}
