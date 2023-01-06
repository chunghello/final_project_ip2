#include "Host.h"

Host::Host(int diffi)
{
   difficulty=diffi;
   level=1;
   amo=0;
   amo_recover=1;
   evilpower=0;
   evil_recover=1;
   score=0;
}
int
Host::renew(){
    clock.add();
    if(clock.get_time()/amo_recover==(int)(clock.get_time()/amo_recover)){
        amo++;
    }
    if(clock.get_time()/evil_recover==(int)(clock.get_time()/evil_recover)){
        evilpower++;
    }
    if(clock.get_time()/20==(int)(clock.get_time()/20)){
        printf("Level up\n");
        Level_up();
    }

}
void
Host::Level_up(){
    level++;
    //evil_recover--;
}
void
Host::add_score(){
    score++;
   // amo_recover-=0.01;
}
bool
Host::use_amo(int usage){
    if(usage>amo)return false;
    else{
        amo-=usage;
        return true;
    }
}
bool
Host::use_camp(int usage){
    if(usage>evilpower)return false;
    else{
        evilpower-=usage;
        return true;
    }
}
