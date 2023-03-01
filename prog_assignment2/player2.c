/*
* Created by: Antonio and Naotoshi 
* Modified: 02/28/2023
* CS 480 - Systems Programming
* Assignment #2
*/
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    char arr[10];
    char *myfifo = "/tmp/myfifo"; 
    char lose[1] = "L"; 
    int len = 0;
    int fd; 
    int timer = 1;
 

    while(1){

        fd = open(myfifo, O_RDONLY); 
        read(fd, arr, sizeof(arr)); 
        close(fd); 
        len = strlen(arr);

        if(len == 1){
            fd = open(myfifo, O_WRONLY); 
            write(fd, lose, strlen(lose)); 
            close(fd); 
            break;
        } 
        else{
            printf("String1: %s\n", arr); 
            printf("Length1: %d\n", len); 

            arr[len - 1] = '\0'; 
            len = strlen(arr); 
            printf("String2: %s\n", arr); 
            printf("Length2: %d\n", len); 
            fd = open(myfifo, O_WRONLY); 
            write(fd, arr, strlen(arr)); 
            close(fd); 
            timer = timer + 1; 
            sleep(timer); 
        }

    }

    printf("String3: %s\n", arr);
    printf("Length3: %d\n", len); 

    if(arr[0] == '5' || arr[0] == '7'){
        printf("You win!"); 
    } else {
        printf("You lose");
    }

    printf("\nno more characters in the string.\n"); 
    return 0; 

}