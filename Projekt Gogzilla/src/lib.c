#include "lib.h"
#include <stdlib.h>
#include <string.h>


FILE *open_file(const char *filename)
{
    char path[256] = "resource/";
    strcat(path, filename);
    // Open the file
    FILE *in;
    in = fopen(path, "r");
    if (!in)
    {
        printf("Failed to open text file\n");
    }
    return in;
}

void open_ascii_image(WINDOW *window, const char *filename)
{
    int line = 0;
    char c;
    FILE *image = open_file(filename);

    while ((c = getc(image)) != EOF)
    {
        if (c == '\n')
            line++;
        if (line > LINES - 2)
            break;
        waddch(window, c);
    }
    fclose(image);
}
