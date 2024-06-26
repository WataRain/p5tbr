#include <raylib.h>
#include <stdio.h>
#include <string.h>
#include "consts.h"
#include "types.h"
#include "init.c"
#include "gui.c"
#include "events.c"

void GameLoop(struct Data *data);

int main()
{
    int frame = 0;
    bool quit = false;
    struct Data data;
    struct Place places[NUM_PLACES];
    Mode mode;

    InitPlaces(places);
    InitConfidants(data.confidants);
    data.day = 0;
    data.yen = 0;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    InitAudioDevice();
    SetTargetFPS(60);
    printf("Starting TitleScreen...\n");
    mode = TitleScreen(&frame);
    printf("mode: %d\n", mode);
    switch (mode)
    {
        case LOAD_GAME:
            // LoadGame(&data);
            break;
        case NEW_GAME:
            EventIntro();
            break;
        case QUIT_GAME:
            quit = true;
            break;
        case GAME_CREDITS:
            break;
    }

    if (!quit)
    {
        // GameLoop(&data);
        // ???
        if (data.day == NUM_DAYS)
        {
            EventEnding(data);
        }
    }

    CloseWindow();

    return 0;
}