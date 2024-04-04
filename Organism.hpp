#pragma once
#include <ncurses.h>
#include "World.hpp"
#include <cstring>
#include "typedefs.hpp"

class Organism
{
protected:
    
    int x, y;
    int strength;
    int initiative;
    int age;
    char symbol[5];
    World world;
    orgType type;

public:
    Organism();
    Organism(int x, int y, int strength, int initiative, char *symbol, orgType type, World &world);
    int getStrength();
    int getX();
    int getY();
    orgType getType();
    void setStrength(int strength);
    virtual void action() = 0;
    virtual void collision(Organism *org) = 0;
    virtual void draw();
    void die();
};