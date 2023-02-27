#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd1;

    // FIFO file path
    char *myfifo = "/tmp/myfifo";
    char arr1[10] = {0}; 
    char win[3] = "win"; 
    char lose[4] = "lose"; 
    int i =0;

    while(1) {


        // First open in read only and read
        fd1 = open(myfifo, O_RDONLY);
        read(fd1, arr1, sizeof(arr1));

        // Print the read string and close
        printf("String: %s\n", arr1);
        close(fd1);
        
        printf("/*closed the read only*/\n");
        printf("Player2 will remove 1 number from the string.\n"); 

        for (int j=0; j < strlen(arr1); j++) {  
                arr1[j] = arr1[j+1]; 
        }
        
        // Now open in write mode and write
        // string taken from user.

        fd1 = open(myfifo,O_WRONLY);
        printf("\nSending response to Player 1.\n"); 
        write(fd1, arr1, strlen(arr1));
        close(fd1);

        if(arr1[0] != '5' || arr1[0] != '7'){
            printf("\nYou lose\n"); 
            fd1 = open(myfifo,O_WRONLY);
            printf("\nSending response to Player 1.\n"); 
            write(fd1, win, strlen(win));
            close(fd1);
            return 0; 
        }

        sleep(3); 
    } 
    return 1;
}