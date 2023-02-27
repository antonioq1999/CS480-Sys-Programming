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

int main(){
    
    int fd;
    char *myfifo = "/tmp/myfifo"; 
    char arr1[10] = {0}; 
    
    mkfifo(myfifo, 0666); 

    printf("Please enter a string of 5s and 7s.\n Length Limit = 10 \n"); 
    fgets(arr1, 11, stdin); 

    for(int i=0; i<(strlen(arr1)-1); i++){

            if(arr1[i] == '5' || arr1[i] == '7'){

            }
            else{
                printf("Invalid character in string.\n");
            }
    }

    fd = open(myfifo, O_WRONLY); 
    write(fd, arr1, strlen(arr1));  
    close(fd); 
    
    while(1){ 

        /*fd = open(myfifo, O_WRONLY); 
        write(fd, arr1, strlen(arr1));  
        close(fd); */

        fd = open(myfifo, O_RDONLY);
        read(fd, arr1, strlen(arr1));
        close(fd);

        printf("String: %s\n", arr1);
        printf("Player1 will reduce the string by 3.\n"); 

        for(int i=0; i<2; i++){
            for(int j=0; j<strlen(arr1); j++){
                arr1[j] = arr1[j+1]; 
            }
        }
        fd = open(myfifo, O_WRONLY); 
        printf("\nSending response to Player 2. \n"); 
        write(fd, arr1, strlen(arr1)); 
        close(fd); 

    }
    
}