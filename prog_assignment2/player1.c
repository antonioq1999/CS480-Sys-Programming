/***********************************************
 * Programming Assignment 2                    *
 * player1.c                                   *
 * Antonio Quintanilla and Naotoshi Yoshida    *
 * 22 February 2023                            *
 **********************************************/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    FILE *fplayer1;
    char buffer[BUFSIZ + 1];
    int chars_read;
    char input[60];
    int res = mkfifo("/tmp/my_fifo", 0777);

    if (res == 0)
        printf("FIFO created\n");
    memset(buffer, '\0', sizeof(buffer));
    printf("Enter a string of 5's and 7's: ");
    fplayer1 = popen("od -c", "w");

    printf("Your string was: %s", fplayer1);

    return 0;
}