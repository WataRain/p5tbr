main:
	gcc main.c -o game.exe -O2 -std=c99 -Wall -I$(RAYLIB_PATH)/src/external -I$(RAYLIB_PATH)/src -I$(RAYLIB_PATH)/src/extras -DPLATFORM_DESKTOP -lraylib -lopengl32 -lgdi32 -lwinmm     
