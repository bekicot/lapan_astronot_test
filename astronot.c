#include "astronot.h"
#include <ncurses.h>
#define KEY_LEFT 68
#define KEY_RIGHT 67


astronot astronotBaru(koordinat posisi){
    astronot yana;
    yana.posisi = posisi;
    astronotSumon(yana);
    return yana;
}
void astronotPindah(astronot *yana, int key){
  char keyStr[3];
  sprintf(keyStr, "%d", key);
  mvprintw(0, 1, keyStr);
  switch(key){
    case KEY_LEFT:
      _astronotKeKiri(yana);
      break;
    case KEY_RIGHT:
      _astronotKeKanan(yana);
      break;
  }
}
void _astronotKeKiri(astronot *yana){
    koordinat posisiBaru;
    posisiBaru.x = yana->posisi.x - 1;
    posisiBaru.y = yana->posisi.y;
    // mvprintw(0, 10, keyStr);
    mvprintw(0, 10, "ganti");
    if(_astronotSetPosisi(yana, posisiBaru)){
        astronotSumon(*yana);
    }
}
void _astronotKeKanan(astronot *yana){
    koordinat posisiBaru;
    posisiBaru.x = yana->posisi.x + 1;
    posisiBaru.y = yana->posisi.y;
    if(_astronotSetPosisi(yana, posisiBaru)){
        astronotSumon(*yana);
    }
}
int _astronotSetPosisi(astronot *yana, koordinat posisi){
    yana->posisi = posisi;
    return 1;
}
void astronotSumon(astronot yana){
    _astronotClearSummonLocation(yana);
    mvprintw(yana.posisi.y, yana.posisi.x, "  /\\");
    mvprintw(yana.posisi.y + 1, yana.posisi.x, " (__)");
    mvprintw(yana.posisi.y + 2, yana.posisi.x, "/[ ♥]\\");
    mvprintw(yana.posisi.y + 3, yana.posisi.x, " //\\\\");
}

void _astronotClearSummonLocation(astronot yana){
  for (int i = 0; i < 3; ++i)
  {
    move(yana.posisi.y + i + 1, 0);
    clrtoeol();
  }

}


