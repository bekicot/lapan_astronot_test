#ifndef ASTRONOT_H_INCLUDED
#define ASTRONOT_H_INCLUDED

#include "koordinat.h"

typedef struct
{
  koordinat posisi;
  int amunisi;
} astronot;

astronot astronotBaru(koordinat posisi);
void astronotPindah(astronot *yana, int key);
void _astronotKeKiri(astronot *yana);
void _astronotKeKanan(astronot *yana);
int _astronotSetPosisi(astronot *yana, koordinat posisi);
void astronotSumon(astronot yana);
void _astronotClearSummonLocation(astronot yana);


#endif
