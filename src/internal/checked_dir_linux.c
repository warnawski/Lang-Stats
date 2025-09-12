//
// Created by warnawski on 08.09.2025.
//
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../include/chdir.h"
#include <sys/stat.h>

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

long read_and_counted_lines(char path[], struct dirent *entry)
{
    FILE *f = fopen(path, "r");
    if (f == NULL)
    {
        perror("fopen");
        return 1;
    }
    char ch;
    long lines = 0;
    while ((ch = fgetc(f)) != EOF)
    {
        if (ch == '\n')
        {
            lines++;
        }
    }
    return lines;
}

int directory_going_down(const char local_buff[4096])
{
    DIR *dir = opendir(local_buff);
    if (!dir)
    {
        perror("opendir");
        return 1;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL)
    {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
        {
            continue;
        }

        char path_buff[4096];
        snprintf(path_buff, sizeof(path_buff), "%s/%s", local_buff, entry->d_name);

        struct stat st;
        if (stat(path_buff, &st) == 0 && S_ISDIR(st.st_mode))
        {
            // printf("%s\n", path_buff);
            directory_going_down(path_buff);
        }
        else
        {
            char ext_result[20];
            int x = 0;

            const char *name = entry->d_name;
            size_t len = strlen(name);

            const char *dot = strrchr(name, '.');
            if (dot != NULL)
            {
                x = 0;
                dot++;
                while (*dot && x < sizeof(ext_result) - 1)
                {
                    ext_result[x++] = *dot++;
                }
                ext_result[x] = '\0';
            } else
            {
                ext_result[0] = '\0';
            }

            long i = read_and_counted_lines(path_buff, entry);
            add_lines(ext_result, i);
        }
    }
    closedir(dir);
    return 0;
}

int directory_traversal()
{

    char local_buff[4096];
    get_current_directory(local_buff, sizeof(local_buff));

    directory_going_down(local_buff);

    return 0;
}
