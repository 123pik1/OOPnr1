#include "Grass.hpp"

Grass::Grass(int x, int y, int strength,  World& world) : Plant(x, y, strength, "G", GRASS, world)
{
}

void Grass::collision(Organism* org)
{
    
}

Plant* Grass::newPlant(int x, int y)
{
    return new Grass(x, y, 0, world);
}