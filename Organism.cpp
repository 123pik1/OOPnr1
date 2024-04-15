#include "Organism.hpp"
using namespace std;
// Organism::Organism(int x, int y, int strength, int initiative, char *symbol, orgType type, World *world)
//     : x(x), y(y), strength(strength), initiative(initiative), age(0), type(type), world(world), plSpecies(NO_PLANT), anSpecies(NO_ANIMAL)
// {
//     strcpy(this->symbol, symbol);
// }

Organism::Organism(int x, int y, int strength, int initiative, char *symbol, World* world, plantTypes plSpecies, std::string name)
    : x(x), y(y), strength(strength), initiative(initiative), age(0), type(PLANT), plSpecies(plSpecies), anSpecies(NO_ANIMAL), world(world), name(name)
{
    strcpy(this->symbol, symbol);
}

Organism::Organism(int x, int y, int strength, int initiative, char *symbol, World* world, animalTypes anSpecies, std::string name)
    : x(x), y(y), strength(strength), initiative(initiative), age(0), type(ANIMAL), plSpecies(NO_PLANT), anSpecies(anSpecies), world(world), name(name)
{
    strcpy(this->symbol, symbol);
}

void Organism::draw()
{
    mvprintw(y, x, symbol);
}

void Organism::draw(WINDOW *win)
{
    mvwprintw(win, y+1, x+1, symbol);
}

int Organism::getStrength()
{
    return strength;
}

void Organism::setStrength(int strength)
{
    this->strength = strength;
}
string Organism::getSaveString()
{
    saveString = to_string(x) + " " + to_string(y) + " " + to_string(strength)+" " + to_string(age) + " " + string(1,anSpecies) + string(1,plSpecies) ;
    return saveString;
}


void Organism::die()
{
    world->removeOrganism(this);
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

void Organism::setAge(int age)
{
    this->age = age;
}

string Organism::getName()
{
    return name;
}
string Organism::getCommunicate()
{
    return communicate;
}

void Organism::die(Organism *org)
{
    world->removeOrganism(org);
}