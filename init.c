#include "consts.h"
#include "types.h"

void CopyArrayI(int arr1[], int arr2[], int num)
{
    for (int i = 0; i < num; i++)
    {
        arr1[i] = arr2[i];
    }
}

/*
Initialize place data (i.e., names, neighbors)

@param places
*/
void InitPlaces(struct Place places[NUM_PLACES])
{
    str names[NUM_PLACES] = {
        "LeBlanc Cafe", "Back Alley", "Clinic", "Train Station", "Underground Mall",
        "Shuijin Academy", "Shibuya", "Big Bang Burger", "Arcade"
    };
    int neighbors[NUM_PLACES][NUM_DIRECTIONS] = {
    //   NORTH             SOUTH             EAST              WEST               OF
        {NONE,             BACK_ALLEY,       NONE,             NONE},          // LEBLANC_CAFE
        {LEBLANC_CAFE,     CLINIC,           TRAIN_STATION,    NONE},          // BACK_ALLEY
        {BACK_ALLEY,       NONE,             NONE,             NONE},          // CLINIC
        {SHUJIN_ACADEMY,   UNDERGROUND_MALL, SHIBUYA,          NONE},          // TRAIN_STATION
        {TRAIN_STATION,    NONE,             NONE,             NONE},          // UNDERGROUND_MALL
        {NONE,             TRAIN_STATION,    NONE,             TRAIN_STATION}, // SHUJIN_ACADEMY
        {NONE,             ARCADE,           BIG_BANG_BURGER,  TRAIN_STATION}, // SHIBUYA
        {NONE,             NONE,             NONE,             SHIBUYA},       // BIG_BANG_BURGER
        {SHIBUYA,          NONE,             NONE,             NONE},          // ARCADE
    };
    for (int i = 0; i < NUM_PLACES; i++)
    {
        strcpy(places[i].name, names[i]);
        CopyArrayI(places[i].neighbors, neighbors[i], NUM_DIRECTIONS);
    }
}

/*
Initialize confidant data (i.e., names, LOCKED status)

@param confidants
*/
void InitConfidants(struct Confidant confidants[NUM_CONFIDANTS])
{
    str names[NUM_CONFIDANTS] = {
        "Sojiro", "Ryuji", "Ann", "Yusuke", "Makoto",
        "Futaba", "Haru", "Takemi", "Kawakami", "Sumire"
    };
    for (int i = 0; i < NUM_PLACES; i++)
    {
        strcpy(confidants[i].name, names[i]);
        confidants[i].points = LOCKED;
        confidants[i].id = i;
    }
}

/*
Initialize shop item data (i.e., item names, prices, effects)

@param items
*/
void InitShopData(struct Item items[NUM_ITEMS])
{
    return; // TBA
};