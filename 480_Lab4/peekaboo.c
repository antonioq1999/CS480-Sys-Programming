#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

int main(){
    FILE *fp; 
    fp = fopen("peekaboo.txt", "w");
    fprintf(fp, "Peekaboo! I see you!"); 
    fflush(stdout);
    sleep(10); 
}