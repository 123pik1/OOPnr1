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
    bool alive = true;
    char symbol[5];
    World* world;
    orgType type= NO_ORGANISM;
    plantTypes plSpecies;
    animalTypes anSpecies;
    std::string name;
    std::string saveString;
    std::string communicate;
public:
    // Organism(int x, int y, int strength, int initiative, char *symbol, orgType type, World* world);
    Organism(int x, int y, int strength, int initiative, char *symbol, World* world, plantTypes plSpecies, std::string name);
    Organism(int x, int y, int strength, int initiative, char *symbol, World* world, animalTypes anSpecies, std::string name);
    Organism(int x, int y, int strength, int initiative, char *symbol, World* world, animalTypes type, std::string name, int age);
    int getStrength();
    int getX();
    int getY();
    int getInitiative();
    int getAge();
    std::string getName();
    std::string getCommunicate();
    void setAge(int age);
    animalTypes getAnSpecies();
    plantTypes getPlSpecies();
    orgType getType();
    virtual std::string getSaveString();
    void setStrength(int strength);
    virtual void action() = 0;
    virtual void collision(Organism *org) = 0;
    virtual void die(Organism *org);
    void draw();
    void draw(WINDOW *win);
    void die();
    bool getAlive();
    void aging();
};;
