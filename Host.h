#ifndef HOST_H_INCLUDED
#define HOST_H_INCLUDED
//goood
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_primitives.h>

#include "Clock.h"

class Host{
private:
   int level;
   Clock clock;
   int amo;
   float amo_recover;
   int evilpower;
   float evil_recover;
   int score;
   int difficulty;

public:
   Host(int);
   int get_level(){return level;}
   Clock get_clock(){return clock;}
   int get_amo(){return amo;}
   int get_evilpower(){return evilpower;}
   int get_score(){return score;}
   int renew();
   void Level_up();
   void add_score();
   bool use_amo(int);
   bool use_camp(int);

};





#endif