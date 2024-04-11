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
    World& world;
    orgType type;
    plantTypes plSpecies;
    animalTypes anSpecies;
public:
   // Organism();
    Organism(int x, int y, int strength, int initiative, char *symbol, orgType type, World& world);
    Organism(int x, int y, int strength, int initiative, char *symbol, World& world, plantTypes plSpecies);
    Organism(int x, int y, int strength, int initiative, char *symbol, World& world, animalTypes anSpecies);

    int getStrength();
    int getX();
    int getY();
    int getInitiative();
    int getAge();
    animalTypes getAnSpecies();
    plantTypes getPlSpecies();
    orgType getType();
    void setStrength(int strength);
    virtual void action() = 0;
    virtual void collision(Organism *org) = 0;
    void draw();
    void draw(WINDOW *win);
    void die();
};;
