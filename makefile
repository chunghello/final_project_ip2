ALLEGRO_LIBRARIES := allegro-5 allegro_image-5 allegro_font-5 allegro_ttf-5 allegro_dialog-5 allegro_primitives-5 allegro_audio-5 allegro_acodec-5 allegro_video-5
ALLEGRO_FLAGS := $(shell pkg-config --cflags --libs $(ALLEGRO_LIBRARIES)) -lallegro  -lallegro_main#need to add -lallegro_main to let main to be seen ,i dont know why 
# when error:yld[14393]: symbol not found in flat namespace '__al_mangled_main' Abort trap: 6  occurs ,just remove  -lallegro_main

CC := g++
OUT:= game
MAIN:= Main.o Monster.o Wolf.o Tower.o Attack.o Circle.o  GameWindow.o global.o 

all: $(MAIN)
	$(CC) $(MAIN) -std=c++20 -o $(OUT) $(ALLEGRO_FLAGS) 
    
clean: 
	rm $(OUT) $(MAIN)
	 
