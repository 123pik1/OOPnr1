#include "Antelope.hpp"

Antelope::Antelope(int x, int y, World *world) : Animal(x, y, 4, 4, "A", world, ANTELOPE, "Antelope")
{
}

Animal *Antelope::newAnimal(int x, int y)
{
    return new Antelope(x, y, world);
}

void Antelope::move()
{
    int dist = 2;
    bool dirs[4] = {false, false, false, false};
    if (y - dist >= 0)
    {
        dirs[0] = true;
    }
    if (y + dist < world->getHeight())
    {
        dirs[1] = true;
    }
    if (x - dist >= 0)
    {
        dirs[2] = true;
    }
    if (x + dist < world->getWidth())
    {
        dirs[3] = true;
    }
    int direction = rand() % 4;
    while (dirs[direction] == false)
    {
        direction = rand() % 4;
    }
    moving(dist, direction);
}

void Antelope::retreat()
{
    bool dirs[4] = {false};
    if ((!world->isOccupied(x, y - 1) || (world->getOrganism(x,y-2)!=nullptr && world->getOrganism(x, y - 2)->getStrength() <= this->strength)) && y - 2 >= 0)
    {
        dirs[0] = true;
    }
    if ((!world->isOccupied(x, y + 1) || (world->getOrganism(x,y+2)!=nullptr && world->getOrganism(x, y + 2)->getStrength() <= this->strength) )&& y + 2 < world->getHeight())
    {
        dirs[1] = true;
    }
    if ((!world->isOccupied(x - 1, y) || (world->getOrganism(x-2,y)!=nullptr && world->getOrganism(x - 2, y)->getStrength() <= this->strength)) && x - 2 >= 0)
    {
        dirs[2] = true;
    }
    if ((!world->isOccupied(x + 1, y) ||(world->getOrganism(x+2,y)!=nullptr && world->getOrganism(x + 2, y)->getStrength() <= this->strength)) && x + 2 < world->getWidth())
    {
        dirs[3] = true;
    }
    int option = rand() % 4;

    while (dirs[option] == false)
    {
        option++;
        if (option == 4)
        {
            option = 0;
        }
    }
    option++;

    moving(1, option);
}

void Antelope::collision(Organism *org)
{
    switch (rand() % 2)
    {
    case 0:
        Animal::collision(org);
        break;
    case 1:
        retreat();
        break;
    }
}