#include "Fox.hpp"

Fox::Fox(int x, int y, World &world):Animal(x, y, 3, 7, "F", world, FOX)
{
}

Animal* Fox::newAnimal(int x, int y)
{
    return new Fox(x, y, world);
}

void Fox::action()
{
    bool dirs [4] = {false};
    if (!world.isOccupied(x,y-1) || world.getOrganism(x,y-1)->getStrength()<=this->strength)
    {
        dirs[0]=true;
    }
    if (!world.isOccupied(x,y+1) || world.getOrganism(x,y+1)->getStrength()<=this->strength)
    {
        dirs[1]=true;
    }  
    if (!world.isOccupied(x-1,y) || world.getOrganism(x-1,y)->getStrength()<=this->strength)
    {
        dirs[2]=true;
    }
    if (!world.isOccupied(x+1,y) || world.getOrganism(x+1,y)->getStrength()<=this->strength)
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