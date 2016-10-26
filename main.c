#include <ncurses.h>
#include <unistd.h>
#include <time.h>
#include "astronot.c"
#include "koordinat.c"

#define DELAY 1000000

void printHead(int x, int y);

int main(int argc, char const *argv[])
{
    // variables
    int tombol_ditekan;
    astronot yana;
    koordinat posisiYana;
    
    // Persiapan screen
    initscr();
    noecho();
    curs_set(FALSE);
    posisiYana = koordinatBaru(10,10);
    yana = astronotBaru(posisiYana);

    while(1){
        mvprintw(50, 20, "hello");
        astronotPindah(&yana, getch());
        mvprintw(50, 20, "world");

    }
    getchar();
    endwin();
    return 0;
}
      //   /\
      //  (__)
      // /[ ♥]\
      //  //\\
