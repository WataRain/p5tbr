#ifndef CONSTS

#define CONSTS

#define SCREEN_WIDTH 1366
#define SCREEN_HEIGHT 768

#define TITLE "PeRSoNa 5: TeXt-BAseD RoYalE"

#define NUM_DAYS 60
#define NONE -1
#define INVENTORY_SIZE 10

#define PERSONA_RED (Color) {234, 7, 4, 255}

enum modes
{
    NEW_GAME,
    LOAD_GAME
};

enum confidants
{
    SOJIRO,
    RYUJI,
    ANN,
    YUSUKE,
    MAKOTO,
    FUTABA,
    HARU,
    TAE,
    SADAYO,
    SUMIRE,
    NUM_CONFIDANTS
};

enum points
{
    LOCKED = -2,
    UNLOCKABLE,
    CONF_LV1,
    CONF_LV2 = 7,
    CONF_LV3 = 17,
    CONF_MAX = 18
};

enum places
{
    LEBLANC_CAFE,
    BACK_ALLEY,
    CLINIC,
    TRAIN_STATION,
    UNDERGROUND_MALL,
    SHUJIN_ACADEMY,
    SHIBUYA,
    BIG_BANG_BURGER,
    ARCADE,
    NUM_PLACES
};

enum directions
{
    NORTH,
    SOUTH,
    EAST,
    WEST,
    NUM_DIRECTIONS
};

enum items
{
    // TODO
    NUM_ITEMS
};

#endif