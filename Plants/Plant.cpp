#include "Plant.hpp"

Plant::Plant(int x, int y, int strength, char* symbol,plantTypes type, World* world) : Organism(x, y, strength, 0, symbol, world, type)
{
    
}

void Plant::action()
{
    int i = 0;
    if (world->isOccupied(x, y + 1) == false && y+1<world->getHeight())
    {
        i++;
    }
    if (world->isOccupied(x, y - 1) == false && y-1>=0)
    {
        i++;
    }
    if (world->isOccupied(x + 1, y) == false && x+1<world->getWidth())
    {
        i++;
    }
    if (world->isOccupied(x - 1, y) == false && x-1>=0)
    {
        i++;
    }
    int option = (rand() % (i+20))+1;
    if (option <= i)
    {
        switch (i)
        {
        case 1:
            world->addOrganism(newPlant(x, y + 1));
            break;
        case 2:
            world->addOrganism(newPlant(x + 1, y));
            break;
        case 3:
            world->addOrganism(newPlant(x, y - 1));
            break;
        case 4:
            world->addOrganism(newPlant(x - 1, y));
            break;
        default:
            break;
        }
    }
}

void Plant::collision(Organism* org)
{
    this->die();
}