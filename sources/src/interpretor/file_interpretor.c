#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include "brainfuck2.h"

static int get_file_size(const char *file_path)
{
    struct stat st;

    if (stat(file_path, &st) != 0) {
        fprintf (stderr, "bf2: cannot access '%s': %s.\n",
            file_path, strerror (errno));
        return (-1);
    }
    return (st.st_size);
}

unsigned char *read_file(const char *file_path)
{
    int file_size;
    unsigned char *contents;
    FILE *f;
    int bytes_read;

    file_size = get_file_size(file_path);
    if (file_size < 0)
        return (NULL);
    contents = malloc(sizeof(unsigned char) * (file_size + 1));
    if (!contents) {
        fprintf(stderr, "bf2: malloc failed.\n");
        return (NULL);
    }
    f = fopen(file_path, "r");
    if (!f) {
        fprintf(stderr, "bf2: cannot open '%s': %s.\n", file_path, strerror(errno));
        free(contents);
        return (NULL);
    }
    bytes_read = fread(contents, sizeof(unsigned char), file_size, f);
    if (bytes_read != file_size) {
        fprintf(stderr, "bf2: cannot read '%s': %s.\n", file_path, strerror (errno));
        free(contents);
        fclose(f);
        return (NULL);
    }
    contents[bytes_read] = '\0';
    fclose(f);
    return contents;
}

int file_interpretor(char const *file_path)
{
    int rtn_value;
    unsigned char *file_content = read_file(file_path);

    if (!file_content)
        return (EXIT_FAILURE);
    rtn_value = interpretor(file_content);
    free(file_content);
    return (rtn_value);
}