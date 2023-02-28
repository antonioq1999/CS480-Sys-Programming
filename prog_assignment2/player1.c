#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    char arr[10];
    char *myfifo = "/tmp/myfifo"; 
    char *lose = "You lose!"; 
    int len = 0; 
    int fd;
    double timer = 1.5; 


    printf("Please enter a string of 5s and 7s.\n");
    fgets(arr, 10, stdin);
    for(int i=0; i<(strlen(arr)-1); i++){
        if(arr[i] == '5' || arr[i] == '7'){
        }
        else{
            printf("Invalid character in string.\n");
        }
    }

    len = strlen(arr); 
    printf("Starting string: %s\n", arr);
    printf("Starting length: %d\n", len-1); 

    mkfifo(myfifo, 0666); 
    fd = open(myfifo, O_WRONLY); 
    write(fd, arr, strlen(arr)+1); 
    close(fd);
    sleep(5);  

    while(1 && len != 1){

        fd = open(myfifo, O_RDONLY);
        read(fd, arr, strlen(arr)+1);
        close(fd); 

        if(arr[0] == 'L'){
            break; 
        }
        else{
            len = strlen(arr);
            printf("String1: %s\n", arr);
            printf("Length1: %d\n", len); 

            arr[len - 1] = '\0';
            len = strlen(arr); 
            printf("String2: %s\n", arr);
            printf("Length2: %d\n", len);
            

            fd = open(myfifo, O_WRONLY); 
            write(fd, arr, strlen(arr));
            close(fd); 
            timer = timer + .5; 
            sleep(timer);    
        }
    }

    fd = open(myfifo, O_RDONLY); 
    read(fd, arr, strlen(arr)+1); 
    close(fd); 
    len = strlen(arr);
    printf("String3: %s\n", arr);
    printf("Length3: %d\n", len); 

    if(arr[0] == '5' || arr[0] == '7'){
        printf("You win!");
        // fd = open(myfifo, O_WRONLY); 
        // write(fd, lose, strlen(lose));
        // sleep(3); 
    } else{
        printf("You Lose ");
    }

    printf("no more characters in the array.\n");
    return 0; 
}