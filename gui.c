#include <raylib.h>

#include "types.h"
#include "consts.h"

/*
@return `x_pos` for which `text` will be centered within `screenWidth`
*/
int TextCenteredX(char *text, Font font, int fontSize, int spacing, int screenWidth)
{
    int x = MeasureTextEx(font, text, fontSize, spacing).x;
    return screenWidth/2 - x/2;
}


/*
@return `y_pos` for which `text` will be centered within `screenHeight`
*/
int TextCenteredY(char *text, Font font, int fontSize, int spacing, int screenHeight)
{
    int y = MeasureTextEx(font, text, fontSize, spacing).y;
    return screenHeight/2 - y/2;
}

/*
@return a Vector2 `vector` for which `text` will be centered within `screenWidth` and `screenHeight`
*/
Vector2 TextCenteredV(char *text, Font font, int fontSize, int spacing, int screenWidth, int screenHeight)
{
    Vector2 vect = MeasureTextEx(font, text, fontSize, spacing);
    return (Vector2) { .x = screenWidth/2 - vect.x/2, .y = screenHeight/2 - vect.y/2 };
}

void FrameCtr(int frame)
{
    str strFrame;
    sprintf(strFrame, "FRAME %d", frame);
    DrawText(strFrame, SCREEN_WIDTH/32, SCREEN_HEIGHT/32, 16, WHITE);
}

int UpDownSelect(int current, int limit)
{
    switch (GetKeyPressed())
    {
        case KEY_UP:
            current--;
            break;
        case KEY_DOWN:
            current++;
            break;
    }
    current = (current + limit) % limit;
    return current;
}

// TODO
Mode TitleScreen(int *frame)
{
    // Text
    Font EXPOSE = LoadFont("resources/font/Expose-Regular.otf");
    Font EARWIG = LoadFont("resources/font/earwig factory rg.otf");
    Font ARSENAL = LoadFont("resources/font/Arsenal-Regular.ttf");
    const unsigned int titleSize = 60;
    const unsigned int spacing = 1;
    const unsigned int NUM_OPTIONS = 4;
    str options[] = {"NeW GaMe", "LoAD gAmE", "GAME credits", "QuIT game"};
    int selection = 0;
    Vector2 vect;

    // Music
    Music MUS_TITLE = LoadMusicStream("resources/bgm/last_surprise_by_lumena_tan_and_jilly_shears.mp3");
    PlayMusicStream(MUS_TITLE);

    // Morgana
    unsigned int frameDataOffset = 0;
    unsigned int currentAnimFrame = 0;
    int animFrames = 100; // No idea if lucky guess or if this works
    const unsigned int frameDelay = 2;
    Image ANIM_MORGANA = LoadImageAnim("resources/sprite/morgana_by_molegato.gif", &animFrames);
    Texture2D TEX_MORGANA = LoadTextureFromImage(ANIM_MORGANA);

    while (!IsKeyPressed(KEY_SPACE) && !WindowShouldClose())
    {
        (*frame)++;
        ClearBackground(BLACK);
        // Music
        UpdateMusicStream(MUS_TITLE);
        // Graphics
            // Text
        BeginDrawing();
        FrameCtr(*frame);
        vect = TextCenteredV(TITLE, EARWIG, titleSize, spacing, SCREEN_WIDTH, SCREEN_HEIGHT);
        vect.y -= SCREEN_HEIGHT/3;
        DrawTextEx(EARWIG, TITLE, vect, titleSize, spacing, WHITE);
        for (int i = 0; i < NUM_OPTIONS; i++)
        {
            vect = TextCenteredV(options[i], EXPOSE, titleSize, spacing, SCREEN_WIDTH, SCREEN_HEIGHT);
            vect.y += SCREEN_HEIGHT/5 + i * MeasureTextEx(EXPOSE, options[i], titleSize, spacing).y;
            DrawTextEx(EXPOSE, options[i], vect, titleSize, spacing, (selection == i) ? PERSONA_RED : WHITE);
        }
            // Morgana
        if (*frame >= frameDelay)
        {
            currentAnimFrame++;
            if (currentAnimFrame >= animFrames)
            {
                currentAnimFrame = 0;
            }
            frameDataOffset = ANIM_MORGANA.width * ANIM_MORGANA.height * 4 * currentAnimFrame;
            UpdateTexture(TEX_MORGANA, ANIM_MORGANA.data + frameDataOffset);
            *frame = 0;
        }
        DrawTextureEx(TEX_MORGANA, (Vector2) {SCREEN_WIDTH/2 - TEX_MORGANA.width/4, SCREEN_HEIGHT/4}, 0, 0.5f, WHITE);
        EndDrawing();

        // Menu Control
        selection = UpDownSelect(selection, NUM_OPTIONS);
    }
    UnloadTexture(TEX_MORGANA);
    UnloadImage(ANIM_MORGANA);
    return selection;
}
