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
#define max_camp_y 540
#define min_camp_y 60
#define max_camp_x 800-80
#define min_camp_x 800-240
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

struct Clock{
public:
    Clock(){
        second=0;
        mili_second=0;
    }
    void add(){
        mili_second++;
        if(mili_second==60){
            second++;
            mili_second=0;
        }
    }
    float get_time(){return second+(float)mili_second/60;}
    float get_second(){return (float)second;}
    float get_mili_second(){return (float)mili_second;}
private:
    int second;
    int mili_second;
};

#endif // GLOBAL_H_INCLUDED
