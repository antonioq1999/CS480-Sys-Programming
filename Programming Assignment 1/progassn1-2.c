#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *in_file = fopen("lyric_out.txt", "r");
    FILE *out_file = fopen("lyric_out_line.txt", "w");

    char c[256];
    int i;
    int j;
    while (fgets(c, sizeof(c), in_file) != NULL)
    {
        while (!((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z' || c[i] == '\0')))
        {
            for (j = 1; c[j] != '\0'; ++j)
            {
                c[j] = c[j + 1];
            }
            c[j] = '\0';
        }
        fputs(c, out_file);
    }
    fclose(in_file);
    fclose(out_file);
    return 0;
}