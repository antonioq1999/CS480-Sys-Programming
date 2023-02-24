/*
* Created by Naotoshi and Antonio
*/
#include <stdio.h>
#include <stdlib.h>

void main()
{

    FILE *in_file = fopen("Hey Boy! Hey Boy!.txt", "r"); // read only
    FILE *out_file = fopen("lyric_out.txt", "w");        // write to only

    char c;

    do
    {
        c = getc(in_file);
        putc(c, out_file);
    } while (c != EOF);

    fclose(in_file);
    fclose(out_file);
}
