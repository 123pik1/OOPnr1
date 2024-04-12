#include "Grass.hpp"

Grass::Grass(int x, int y,  World* world) : Plant(x, y, 0, "G", GRASS, world)
{
}

void Grass::collision(Organism* org)
{
    
}

Plant* Grass::newPlant(int x, int y)
{
    return new Grass(x, y, world);
}