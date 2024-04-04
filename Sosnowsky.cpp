#include "Sosnowsky.hpp"

Sosnowsky::Sosnowsky(int x, int y, World& world) : Plant(x, y, 10, "S", SOSNOWSKY_HOGWEED, world)
{

}

void Sosnowsky::collision(Organism* org)
{
    org->die();
}

void Sosnowsky::action() 
{
    if (world.isOccupied(x, y + 1) == true)
    {
        Organism* org = world.getOrganism(x, y + 1);
        if (org->getType() == ANIMAL)
        {
            if (org->getAnSpecies()!=CYBER_SHEEP)
                org->die();
        }
        
    }
    Plant::action(); 
}

Plant* Sosnowsky::newPlant(int x, int y)
{
    return new Sosnowsky(x, y, world);
}