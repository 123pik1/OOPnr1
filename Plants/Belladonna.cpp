#include "Belladonna.hpp"

Belladonna::Belladonna(int x, int y, World* world) : Plant(x, y, 99, "B", BELLADONNA, world, "Belladonna")
{

}

void Belladonna::collision(Organism* org)
{
    org->die();
    Plant::collision(org);
}

void Belladonna::action() 
{
    Plant::action(); 
}

Plant* Belladonna::newPlant(int x, int y)
{
    return new Belladonna(x, y, world);
}