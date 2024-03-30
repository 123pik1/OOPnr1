#include "Organism.hpp"

Organism::Organism()
{
    x = 0;
    y = 0;
    strength = 0;
    initiative = 0;
    age = 0;
    symbol[0] = ' ';
    symbol[1] = ' ';
    symbol[2] = ' ';
    symbol[3] = ' ';
    symbol[4] = ' ';
}


Organism::Organism(int x, int y, int strength, int initiative, char symbol[], World& world)
{
    this->x = x;
    this->y = y;
    this->strength = strength;
    this->initiative = initiative;
    this->age =0;
    strcpy(this->symbol, symbol); 
    this->world = world;
}

void Organism::draw()
{
    mvaddch(y, x, symbol[0]);
}