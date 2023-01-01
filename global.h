#ifndef GLOBAL_H_INCLUDED
#define GLOBAL_H_INCLUDED

#include <allegro5/allegro_font.h>

#define font_size 12
#define grid_width 40
#define grid_height 40

#define window_width 800
#define window_height 600
#define field_width 500
#define field_height 600
#define lava_width 20
#define lava_height 600
#define max_camp_y 490
#define min_camp_y 10
#define max_camp_x 720
#define min_camp_x 560
#define Num_TowerType 5
#define Num_MonsterType 4
#define NumOfGrid (field_width / grid_width) * (field_height / grid_height)

extern int Tower_x;
extern int Tower_y;
extern int TowerRadius[];
extern char TowerClass[][20];
extern int TowerWidth[];
extern int TowerHeight[];
extern char MonsterClass[][20];
extern int MonsterRadius[];
extern char CampClass[][20];
extern int CampRadius[];



enum {ARCANE = 0, ARCHER, CANON, POISON, STORM};
enum {WOLF = 0, WOLFKNIGHT, DEMONNIJIA, CAVEMAN};
enum {HELL=0};

#endif // GLOBAL_H_INCLUDED
