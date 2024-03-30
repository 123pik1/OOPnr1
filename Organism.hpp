#pragma once
#include <ncurses.h>
#include "World.hpp"
#include <cstring>
#include "typedefs.hpp"

class Organism
{
protected:
    typedef int orgType;
    int x, y;
    int strength;
    int initiative;
    int age;
    char symbol[5];
    World world;
    orgType type;

public:
    Organism();
    Organism(int x, int y, int strength, int initiative, char *symbol, orgTypes type, World &world);
    int getStrength();
    void setStrength(int strength);
    virtual void action() = 0;
    virtual void collision(Organism *org) = 0;
    virtual void draw();
    void die();
};