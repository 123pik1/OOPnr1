#pragma once
#include <ncurses.h>
#include "World.hpp"
#include <cstring> 


class Organism
{
protected:
    int x,y;
    int strength;
    int initiative;
    int age;
    char symbol[5];
    World world;
public:
    Organism();
    Organism(int x, int y, int strength, int initiative, char* symbol, World& world);
    virtual void action() = 0;
    virtual void collision(Organism* org) = 0;
    virtual void draw();
};