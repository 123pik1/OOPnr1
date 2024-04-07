#include "Animal.hpp"

Animal::Animal(int x, int y, int strength, int initiative, char *symbol, World &world, animalTypes anSpecies) : Organism(x, y, strength, initiative, symbol, world, anSpecies)
{
}

void Animal::action()
{
    prevX = x;
    prevY = y;
    move();
    age++;
}

void Animal::moving(int dist, int direction)
{
    switch (direction)
    {
    case 0:
        if (!world.isOccupied(x, y - dist))
        {
            this->y -= dist;
        }
        else
        {
            this->collision(world.getOrganism(x, y - dist));
        }
        break;
    case 1:
        if (!world.isOccupied(x, y + dist))
        {
            this->y += dist;
        }
        else
        {
            this->collision(world.getOrganism(x, y + dist));
        }
        break;
    case 2:
        if (!world.isOccupied(x - dist, y))
        {
            this->x -= dist;
        }
        else
        {
            this->collision(world.getOrganism(x - dist, y));
        }
        break;
    case 3:
        if (!world.isOccupied(x + dist, y))
        {
            this->x += dist;
        }
        else
        {
            this->collision(world.getOrganism(x + dist, y));
        }
        break;
    default:
        break;
    }
}

void Animal::move()
{
    int dist = 1;
    int direction = rand() % 4;
    moving(dist, direction);
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
    if (anSpecies == org->getAnSpecies())
    {
        int i = 0;
        if (world.isOccupied(x, y + 1) == false)
        {
            i++;
        }
        if (world.isOccupied(x, y - 1) == false)
        {
            i++;
        }
        if (world.isOccupied(x + 1, y) == false)
        {
            i++;
        }
        if (world.isOccupied(x - 1, y) == false)
        {
            i++;
        }
        if (i != 0)
        {
            int option = (rand() % i) + 1;
            switch (option)
            {
            case 1:
                world.addOrganism(newAnimal(x, y + 1));
                break;
            case 2:
                world.addOrganism(newAnimal(x + 1, y));
                break;
            case 3:
                world.addOrganism(newAnimal(x, y - 1));
                break;
            case 4:
                world.addOrganism(newAnimal(x - 1, y));
                break;
            default:
                break;
            }
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
        anCollision((Animal *)org);
    }
    else
    {
        org->collision(this);
    }
}

void Animal::retreat()
{
    x = prevX;
    y = prevY;
}