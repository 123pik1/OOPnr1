#include "Animal.hpp"

Animal::Animal(int x, int y, int strength, int initiative, char *symbol, World &world, animalTypes anSpecies) : Organism(x, y, strength, initiative, symbol, world, anSpecies)
{
}

void Animal::action()
{

}

void Animal::move(int dist)
{
    int direction = rand() % 4;
    switch (direction)
    {
    case 0:
        if (!world.isOccupied(x, y-dist))
        {
            this->y -= dist;
        }  
        else 
        {
            this->collision(world.getOrganism(x, y-dist));
        }
        break;
    case 1:
        if (!world.isOccupied(x, y+dist))
        {
            this->y += dist;
        }  
        else 
        {
            this->collision(world.getOrganism(x, y+dist));
        }
        break;
    case 2:
        if (!world.isOccupied(x-dist, y))
        {
            this->x -= dist;
        }  
        else 
        {
            this->collision(world.getOrganism(x-dist, y));
        }
        break;
    case 3:
        if (!world.isOccupied(x+dist, y))
        {
            this->x += dist;
        }  
        else 
        {
            this->collision(world.getOrganism(x+dist, y));
        }
        break;
    default:
        break;
    }
}
void Animal::fight(Organism *org)
{
    if (this->getStrength() > org->getStrength())
        {
            org->die();
        }
        else
        {
            this->die();
        }
}
void Animal::anCollision(Animal *org)
{
    if (anSpecies==org->getAnSpecies())
    {
        int x = rand() % 2;
        if (x == 0)
        {
            this->move(1);
        }
        else
        {
            org->move(1);
        }
    }
    else
    {
        fight(org);
    }
}
void Animal::collision(Organism *org)
{
    if (org->getType() == ANIMAL)
    {
        anCollision((Animal*)org);   
    }
    else
    {
        org->collision(this);
    }
}
