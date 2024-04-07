#include "Antelope.hpp"

Antelope::Antelope(int x, int y, World &world):Animal(x, y, 4, 4, "A", world, ANTELOPE)
{
}

Animal* Antelope::newAnimal(int x, int y)
{
    return new Antelope(x, y, world);
}

void Antelope::move()
{
    int dist = 2;
    int direction = rand() % 4;
    moving(dist, direction);
}

void Antelope::retreat()
{
    bool dirs [4] = {false};
    if (!world.isOccupied(x,y-1) || world.getOrganism(x,y-2)->getStrength()<=this->strength)
    {
        dirs[0]=true;
    }
    if (!world.isOccupied(x,y+1) || world.getOrganism(x,y+2)->getStrength()<=this->strength)
    {
        dirs[1]=true;
    }
    if (!world.isOccupied(x-1,y) || world.getOrganism(x-2,y)->getStrength()<=this->strength)
    {
        dirs[2]=true;
    }
    if (!world.isOccupied(x+1,y) || world.getOrganism(x+2,y)->getStrength()<=this->strength)
    {
        dirs[3]=true;
    }
    int dir = rand()%4;
    while (!dirs[dir])
    {
        dir = rand()%4;
    }
    moving(1,dir);
}

void Antelope::collision(Organism *org)
{
    switch(rand() % 2)
    {
        case 0:
            Animal::collision(org);
            break;
        case 1:
            retreat();
            break;
    }
}