#include "Organism.hpp"

Organism::Organism(int x, int y, int strength, int initiative, char *symbol, orgType type, World &world)
    : x(x), y(y), strength(strength), initiative(initiative), age(0), type(type), world(world), plSpecies(NO_PLANT), anSpecies(NO_ANIMAL)
{
    strcpy(this->symbol, symbol);
}

Organism::Organism(int x, int y, int strength, int initiative, char *symbol, World &world, plantTypes plSpecies)
    : x(x), y(y), strength(strength), initiative(initiative), age(0), type(PLANT), plSpecies(plSpecies), anSpecies(NO_ANIMAL), world(world)
{
    strcpy(this->symbol, symbol);
}

Organism::Organism(int x, int y, int strength, int initiative, char *symbol, World &world, animalTypes anSpecies)
    : x(x), y(y), strength(strength), initiative(initiative), age(0), type(ANIMAL), plSpecies(NO_PLANT), anSpecies(anSpecies), world(world)
{
    strcpy(this->symbol, symbol);
}

void Organism::draw()
{
    mvprintw(y, x, symbol);
}

void Organism::draw(WINDOW *win)
{
    mvwprintw(win, y, x, symbol);
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