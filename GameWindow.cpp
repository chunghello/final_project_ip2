#include "GameWindow.h"
#include "global.h"
#include <iostream>


#define WHITE al_map_rgb(255, 255, 255)
#define BLACK al_map_rgb(0, 0, 0)
#define ORANGE_LIGHT al_map_rgb(255, 196, 87)
#define ORANGE_DARK al_map_rgb(255, 142, 71)
#define PURPLE al_map_rgb(149, 128, 255)
#define BLUE al_map_rgb(77, 129, 179)

#define min(a, b) ((a) < (b)? (a) : (b))
#define max(a, b) ((a) > (b)? (a) : (b))


float Attack::volume = 1.0;

void set_attack_volume(float volume)
{
    Attack::volume = volume;
}


void
GameWindow::game_init()
{
    char buffer[50];

    icon = al_load_bitmap("media/icon.png");
    background = al_load_bitmap("media/StartBackground.jpg");
    al_set_display_icon(display, icon);
    al_reserve_samples(3);

    sample = al_load_sample("media/growl.wav");
    startSound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(startSound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(startSound, al_get_default_mixer());

    sample = al_load_sample("media/BackgroundMusic.ogg");
    backgroundSound = al_create_sample_instance(sample);
    al_set_sample_instance_playmode(backgroundSound, ALLEGRO_PLAYMODE_ONCE);
    al_attach_sample_instance_to_mixer(backgroundSound, al_get_default_mixer());

}

bool // detect mouse on bound
GameWindow::mouse_hover(int startx, int starty, int width, int height)
{
    if(mouse_x >= startx && mouse_x <= startx + width)
        if(mouse_y >= starty && mouse_y <= starty + height)
            return true;

    return false;
}


Tower*
GameWindow::create_tower(int pos_x,int pos_y,int type)
{
    switch(type){
        case CANON:
         Canon *t = NULL;
         t = new Canon(pos_x,pos_y);
         return t;
    }

}

Camp*
GameWindow::create_camp(int pos_x,int pos_y,int type,float t){
    switch (type)
    {
    case HELL:
        Hell *h=NULL;
        h= new Hell(pos_x,pos_y,t);
        return h;
        break;
    }

}
void
GameWindow::new_camp(Host * host,std::vector<Camp*> & Campset){
     std::vector<int> choose_y{10,90,170,250,330,410,490};
     std::vector<int> choose_x{560,640,720};
     std::set<std::pair<int,int>>s;
     for(auto i : choose_x){
        for(auto j: choose_y){
            s.insert({i,j});
        }
     }
     for(auto i : CampSet){
        s.erase({i->getCircle()->x,i->getCircle()->y});
     }
    if(!s.empty()){
        if(host->use_camp(1)){

            srand(time(NULL));
            std::vector<std::pair<int,int>> v(s.begin(),s.end());
            std::pair<int,int> tmp;
            if(v.size()==1) tmp=v[0];
            else tmp=v[rand()%(v.size()-1 - 0 )];
            int pos_x=tmp.first;
            int pos_y=tmp.second;
            int type = rand() % (HELL+1 - 0 );
            CampSet.push_back(create_camp(pos_x,pos_y,type,host->get_clock().get_time()));
        }
    }
    else return ;

}

void
GameWindow::game_play()
{
    int msg;

    srand(time(NULL));

    msg = -1;
    game_reset();

    game_begin();

    while(msg != GAME_EXIT)
    {
        msg = game_run();
    }

    show_err_msg(msg);
}

void
GameWindow::show_err_msg(int msg)
{
    if(msg == GAME_TERMINATE)
        fprintf(stderr, "Game Terminated...");
    else
        fprintf(stderr, "unexpected msg: %d", msg);

    game_destroy();
    exit(9);
}

GameWindow::GameWindow()
{
    if (!al_init())
        show_err_msg(-1);

    printf("Game Initializing...\n");

    display = al_create_display(window_width, window_height);
    event_queue = al_create_event_queue();
    timer = al_create_timer(1.0 / FPS);


    if(timer == NULL)
        show_err_msg(-1);

    if (display == NULL || event_queue == NULL)
        show_err_msg(-1);

    al_init_primitives_addon();
    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon(); // initialize the ttf (True Type Font) addon
    al_init_image_addon(); // initialize the image addon
    al_init_acodec_addon(); // initialize acodec addon

    al_install_keyboard(); // install keyboard event
    al_install_mouse();    // install mouse event
    al_install_audio();    // install audio event


    font = al_load_ttf_font("media/Caviar_Dreams_Bold.ttf",12,0); // load small font
    Medium_font = al_load_ttf_font("media/Caviar_Dreams_Bold.ttf",24,0); //load medium font
    Large_font = al_load_ttf_font("media/Caviar_Dreams_Bold.ttf",36,0); //load large font

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    game_init();

}

void
GameWindow::game_begin()
{

    draw_running_map();

    al_play_sample_instance(startSound);
    while(al_get_sample_instance_playing(startSound));
    al_play_sample_instance(backgroundSound);

    al_start_timer(timer);


}

int
GameWindow::game_run()
{
    int error = GAME_CONTINUE;

    if (!al_is_event_queue_empty(event_queue)) {

        error = process_event();
    }
    return error;
}

int
GameWindow::game_update()
{
    unsigned int i, j;
    towerpointer->UpdateAttack();
    for(i=0; i < monsterSet.size(); i++)
    {
        towerpointer->TowerAttack(monsterSet[i]);
        bool died = false;
        died = monsterSet[i]->Move();

        if(died)
        {
            Monster *m = monsterSet[i];
            monsterSet.erase(monsterSet.begin() + i);
            i--;
            delete m;

        }
        else  monsterSet[i]->TriggerAttack(towerpointer);
    }
    for(int i=0;i<CampSet.size();i++){

        if(CampSet[i]->getHealth()<=0){

            Camp *c=CampSet[i];

            CampSet.erase(CampSet.begin()+i);

            i--;
            delete c;
        }
        else{
            Monster* newMonster =CampSet[i]->BornMonster(host->get_clock());

            if(newMonster!=NULL)monsterSet.push_back(newMonster);
        }
    }

    new_camp(host,CampSet);
   // printf("%d\n",host->get_evilpower());


    return GAME_CONTINUE;
}

void
GameWindow::game_reset()
{

    key_state=std::vector<bool>(ALLEGRO_KEY_MAX,false);
    monsterSet.clear();
    CampSet.clear();
    towerpointer=create_tower(Tower_x,Tower_y,CANON);
    shooterpointer= new Shooter1(200,200,ShooterRadius);
    host=new Host(1);
    CampSet.push_back(create_camp(720,250,HELL,host->get_clock().get_time()));
    mute = false;
    redraw = false;


    // stop sample instance
    al_stop_sample_instance(backgroundSound);
    al_stop_sample_instance(startSound);

    // stop timer
    al_stop_timer(timer);
}

void
GameWindow::game_destroy()
{
    game_reset();

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_font(font);
    al_destroy_font(Medium_font);
    al_destroy_font(Large_font);

    al_destroy_timer(timer);


    al_destroy_bitmap(icon);
    al_destroy_bitmap(background);

    al_destroy_sample(sample);
    al_destroy_sample_instance(startSound);
    al_destroy_sample_instance(backgroundSound);

}

int
GameWindow::process_event()
{
    int i;
    int instruction = GAME_CONTINUE;

    // offset for pause window
    int offsetX = field_width/2 - 200;
    int offsetY = field_height/2 - 200;

    al_wait_for_event(event_queue, &event);
    redraw = false;

    if(event.type == ALLEGRO_EVENT_TIMER) {
        if(event.timer.source == timer) {
            host->renew();
            redraw = true;
        }
        else {

        }
    }
    else if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
        return GAME_EXIT;
    }
    else if(event.type == ALLEGRO_EVENT_KEY_DOWN) {
        key_state[event.keyboard.keycode]=true;
        switch(event.keyboard.keycode) {

            case ALLEGRO_KEY_P:
                /*TODO: handle pause event here*/
                break;
            case ALLEGRO_KEY_M:

                mute = !mute;
                if(mute)
                    al_stop_sample_instance(backgroundSound);
                else
                    al_play_sample_instance(backgroundSound);
                break;
            case ALLEGRO_KEY_W: // shooter1 rotate up
                //shooter1->rotate(-1);
                break;

            case ALLEGRO_KEY_S: // shooter1 rotate down
                //shooter1->rotate(1);
                break;

            case ALLEGRO_KEY_SPACE: // shooter1 shoot
                towerpointer->Towershoot(host);
                break;


        }
    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
        shooterpointer->Shootershoot(host);
        //shooter2 shoots

    }
    else if(event.type==ALLEGRO_EVENT_KEY_UP){
        key_state[event.keyboard.keycode]=false;
    }
    else if(event.type == ALLEGRO_EVENT_MOUSE_AXES){
        mouse_x = event.mouse.x;
        mouse_y = event.mouse.y;
    }

    if(key_state[ALLEGRO_KEY_W]){
        towerpointer->rotate(-1);

    }
    if(key_state[ALLEGRO_KEY_S]){
        towerpointer->rotate(1);
    }
    if(key_state[ALLEGRO_KEY_UP]){
        shooterpointer->Move(4);
        std::cout<<"up";
    }
    if(key_state[ALLEGRO_KEY_DOWN]){
        shooterpointer->Move(3);
        std::cout<<"down";
    }
    if(key_state[ALLEGRO_KEY_LEFT]){
        shooterpointer->Move(2);
        std::cout<<"left";
    }
    if(key_state[ALLEGRO_KEY_RIGHT]){
        shooterpointer->Move(1);
        std::cout<<"right";
    }

    if(redraw) {
        // update each object in game
        instruction = game_update();

        // Re-draw map
        draw_running_map();
        redraw = false;
    }

    return instruction;
}

void
GameWindow::draw_running_map()
{
    unsigned int i, j;

    al_clear_to_color(al_map_rgb(100, 100, 100));
    al_draw_bitmap(background, 0, 0, 0);
    al_draw_filled_rectangle(field_width, 0,field_width+lava_width, lava_height, ORANGE_DARK);
    al_draw_filled_rectangle(field_width+lava_width, 0, window_width, window_height, al_map_rgb(100, 100, 100));
    for(i=0; i<monsterSet.size(); i++)
    {
        monsterSet[i]->Draw();
    }

    for(i=0;i<CampSet.size();i++){
        CampSet[i]->Draw();
    }

    towerpointer->Draw();
    shooterpointer->Draw();
    al_flip_display();
}
