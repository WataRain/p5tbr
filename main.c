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
    struct Data data;
    struct Place places[NUM_PLACES];
    Mode mode;

    InitPlaces(places);
    InitConfidants(data.confidants);
    data.day = 0;
    data.yen = 0;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE);
    SetTargetFPS(30);
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
    }

    // GameLoop(&data);

    // ???
    if (data.day == NUM_DAYS)
    {
        EventEnding(data);
    }

    CloseWindow();

    return 0;
}