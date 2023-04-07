#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>

int main() {
    int *t; 
    srand(time(NULL));
    int xArr[9] = {4, 6 , 8, 10, 12, 14, 16, 18, 20}; 
    int yArr[9] = {4, 6, 8, 10, 12, 14, 16, 18, 20}; 

    initscr(); 
    for(int i = 3; i < 10; i++){ 
        for(int j = 0; j<i; j++){
            mvprintw(yArr[rand() % 9], xArr[rand() % 9], "%s", "0");
        }
        refresh(); 
        sleep(2);
        clear(); 
    }
    refresh(); 
    sleep(10); 

    endwin(); 

    exit(EXIT_SUCCESS); 
}