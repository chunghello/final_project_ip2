#include "Camp.h"


Camp::Camp(int pos_x, int pos_y){

    this->circle = new Circle(pos_x,pos_y,0);
}

Camp::~Camp(){
    delete circle;

    al_destroy_bitmap(camp_img);
    this->MonsterType.clear();
}


void 
Camp::Draw(){
    int draw_x = circle->x;
    int draw_y = circle->y;
    
    al_draw_bitmap(camp_img, draw_x, draw_y, 0);
}

   
Monster*
Camp::BornMonster(Clock clock){
  
  if((clock.get_time())/(float)Frequency==(int)((clock.get_time())/(float)Frequency) && clock.get_second()!=0){
    srand(time(NULL));
    int x = rand() % (MonsterType.size() - 0 );
    switch(x){
      
      case WOLF : {
        Wolf *m = NULL;
        m = new Wolf(circle->x,circle->y);
        return m;
        break;
      }
      default:
        return NULL;
        
    }
  }
  else return NULL;
  


}