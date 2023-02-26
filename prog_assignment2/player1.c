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
#include <fcntl.h>

int main()
{
    int fd; 
    char compare; 

    char *myfifo = "/tmp/myfifo";

    mkfifo(myfifo, 0666); 

    char arr1[11], arr2[11]; 
    printf("Please enter a string of 5 and 7s. Limit 10\n");
    while(1){

        fd = open(myfifo, O_WRONLY);
        
        fgets(arr2, 11, stdin); 

        // ASCII value for int 5 and string 5 do not compare
        for(int i=0; i<(strlen(arr2)-1); i++){

            if(arr2[i] == '5' || arr2[i] == '7'){

            }
            else{
                printf("Invalid character in string.\n");
            }
        }
        write(fd, arr2, strlen(arr2)+1); 
        close(fd);
        sleep(5); 
        fd = open(myfifo, O_RDONLY); 
        read(fd, arr1, sizeof(arr1));

        printf("User2: %s\n", arr1); 
        close(fd);
    }

    printf("Enter a String of 5's and 7's:\n");
    printf("%s", arr2);
    scanf("%s", arr2); 
    return 0;
}