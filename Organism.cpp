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
    plSpecies = NO_PLANT;
    anSpecies = NO_ANIMAL;
}

Organism::Organism(int x, int y, int strength, int initiative, char* symbol, World& world, plantTypes plSpecies)
{
    this->x = x;
    this->y = y;
    this->strength = strength;
    this->initiative = initiative;
    this->age =0;
    strcpy(this->symbol, symbol); 
    this->world = world;
    this->type = PLANT;
    this->plSpecies = plSpecies;
    anSpecies = NO_ANIMAL;
}

Organism::Organism(int x, int y, int strength, int initiative, char* symbol, World& world, animalTypes anSpecies)
{
    this->x = x;
    this->y = y;
    this->strength = strength;
    this->initiative = initiative;
    this->age =0;
    strcpy(this->symbol, symbol); 
    this->world = world;
    this->type = ANIMAL;
    plSpecies = NO_PLANT;
    this->anSpecies = anSpecies;
}

void Organism::draw()
{
    mvaddch(y, x, symbol[0]);
}

void Organism::draw(WINDOW* win)
{
    mvwaddch(win, y, x, symbol[0]);
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
int Organism::getInitiative()
{
    return initiative;
}
int Organism::getAge()
{
    return age;
}
animalTypes Organism::getAnSpecies()
{
    return anSpecies;
}
plantTypes Organism::getPlSpecies()
{
    return plSpecies;
}
orgType Organism::getType()
{
    return type;
}