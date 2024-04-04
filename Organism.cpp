#include "Organism.hpp"

Organism::Organism()
{
    x = 0;
    y = 0;
    strength = 0;
    initiative = 0;
    age = 0;
    symbol[0] = '\0';
}


Organism::Organism(int x, int y, int strength, int initiative, char* symbol, orgType type, World& world)
{
    this->x = x;
    this->y = y;
    this->strength = strength;
    this->initiative = initiative;
    this->age =0;
    strcpy(this->symbol, symbol); 
    this->world = world;
    this->type = type;
}

void Organism::draw()
{
    mvaddch(y, x, symbol[0]);
}

int Organism::getStrength()
{
    return strength;
}

void Organism::setStrength(int strength)
{
    this->strength = strength;
}

void Organism::die()
{
    world.removeOrganism(this);
}
int Organism::getX()
{
    return x;
}
int Organism::getY()
{
    return y;
}