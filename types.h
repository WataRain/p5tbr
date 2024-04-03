#include "consts.h"

#ifndef TYPES

#define TYPES

typedef int Mode;
typedef int Effect;
typedef char str[33];

struct Confidant
{
    str name;
    int points;
    int id;
};

struct Place
{
    str name;
    int neighbors[4];
};

struct Item
{
    str name;
    int price;
    Effect effect;
};

struct Data
{
    int day;
    int yen;
    struct Confidant confidants[NUM_CONFIDANTS];
    struct Item items[INVENTORY_SIZE];
};

#endif