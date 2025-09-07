//
// Created by warnawski on 07.09.2025.
//

#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        perror("Wrong number of arguments");
        return 1;
    }

    switch (*argv[1])
    {
        case '--help':
            printf("");
            return 0;

        case '--fetch':
            printf("Fetching...\n");
            return 0;

        case '--info':
            printf("Info:\n");
            return 0;

        default:
            printf("Unknown command\n");
            return 1;
    }
}
