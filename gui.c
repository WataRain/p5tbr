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
    Font ARSENAL = LoadFont("resources/font/Arsenal-Regular.ttf");
    Font EXPOSE = LoadFont("resources/font/Expose-Regular.otf");
    Font EARWIG = LoadFont("resources/font/earwig factory rg.otf");
    int titleSize = 60;
    int spacing = 1;
    int selection = 0;
    Vector2 vect;
    str options[3] = {"NeW GaMe", "LoAD gAmE", "QuIT game"};

    while (!IsKeyPressed(KEY_SPACE) && !WindowShouldClose())
    {
        (*frame)++;
        ClearBackground(BLACK);
        BeginDrawing();
        vect = TextCenteredV(TITLE, EARWIG, titleSize, spacing, SCREEN_WIDTH, SCREEN_HEIGHT);
        vect.y -= SCREEN_HEIGHT/3;
        DrawTextEx(EARWIG, TITLE, vect, titleSize, spacing, WHITE);
        for (int i = 0; i < 3; i++)
        {
            vect = TextCenteredV(options[i], EXPOSE, titleSize, spacing, SCREEN_WIDTH, SCREEN_HEIGHT);
            vect.y += i * MeasureTextEx(EXPOSE, options[i], titleSize, spacing).y;
            DrawTextEx(EXPOSE, options[i], vect, titleSize, spacing, (selection == i) ? PERSONA_RED : WHITE);
        }
        EndDrawing();
        printf("frame: %d\n", *frame);
        selection = UpDownSelect(selection, 3);
    }
    return selection;
}
