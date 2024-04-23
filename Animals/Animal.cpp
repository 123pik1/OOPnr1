#include "Animal.hpp"
using namespace std;
Animal::Animal(int x, int y, int strength, int initiative, char *symbol, World *world, animalTypes anSpecies, std::string name) : Organism(x, y, strength, initiative, symbol, world, anSpecies, name)
{
    prevX = x;
    prevY = y;
}

void Animal::action()
{
    communicate = "";
    prevX = x;
    prevY = y;
    move();
    aging();
}

void Animal::moving(int dist, int direction)
{
    Organism *organism;
    prevX = x;
    prevY = y;
    if(!world->setFalse(x, y))
    {
        returnToPos();
        return;
    }
    switch (direction)
    {
    case 0:
        if (y - dist >= 0)
        {
            if (!world->isOccupied(x, y - dist))
            {
                this->y -= dist;
            }
            else
            {
                organism = world->getOrganism(x, y - dist);
                if (organism)
                {
                    this->collision(organism);
                };
            }
        }
        break;
    case 1:
        if (y + dist < world->getHeight())
        {
            if (!world->isOccupied(x, y + dist))
            {
                this->y += dist;
            }
            else
            {
                organism = world->getOrganism(x, y + dist);
                if (organism)
                {
                    this->collision(organism);
                }
            }
        }
        break;
    case 2:
        if (x - dist >= 0)
        {
            if (!world->isOccupied(x - dist, y))
            {
                this->x -= dist;
            }
            else
            {
                organism = world->getOrganism(x- dist,y);
                if (organism)
                {
                    this->collision(organism);
                }
            }
        }
        break;
    case 3:
        if (x + dist < world->getWidth())
        {
            if (!world->isOccupied(x + dist, y))
            {
                this->x += dist;
            }
            else
            {
                organism = world->getOrganism(x + dist, y);
                if (organism)
                {
                    this->collision(organism);
                }
            }
        }
        break;
    default:
        break;
    }
    if (!world->setTrue(x, y))
    {
        return;
    }
    //tu może coś poprawić?
}

void Animal::move()
{
    int dist = 1;
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
    for (int i = 1; i <= 4; i++)
    {
        if (dirs[i - 1] == true)
        {
            break;
        }
        if (i == 4)
        {
            return;
        }
    }

    moving(dist, direction);
    prevX = x;
    prevY = y;
}
void Animal::fight(Organism *org)
{

    if (this->getStrength() > org->getStrength())
    {
        org->die();
        communicate = this->getName() + " killed " + org->getName();
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
        bool dirs[4] = {false, false, false, false};
        if (world->isOccupied(x, y + 1) == false && y + 1 < world->getHeight())
        {
            i++;
            dirs[0] = true;
        }
        if (world->isOccupied(x, y - 1) == false && y - 1 >= 0)
        {
            i++;
            dirs[1] = true;
        }
        if (world->isOccupied(x + 1, y) == false && x + 1 < world->getWidth())
        {
            i++;
            dirs[2] = true;
        }
        if (world->isOccupied(x - 1, y) == false && x - 1 >= 0)
        {
            i++;
            dirs[3] = true;
        }
        if (i != 0)
        {
            int option = (rand() % i) + 1;

            while (dirs[option] == false)
            {
                option++;
                if (option == 4)
                {
                    option = 0;
                }
            }
            option++;

            switch (option)
            {
            case 1:
                world->addOrganism(newAnimal(x, y + 1));
                break;
            case 2:
                world->addOrganism(newAnimal(x + 1, y));
                break;
            case 3:
                world->addOrganism(newAnimal(x, y - 1));
                break;
            case 4:
                world->addOrganism(newAnimal(x - 1, y));
                break;
            default:
                break;
            }
        }
    }
    else
    {
        // if (org->getX() == x && org->getY() == y)
        org->fight(this);
    }
}
void Animal::collision(Organism *org)
{
    if (org == nullptr)
        return;
    if (org->getType() == ANIMAL)
    {
        anCollision((Animal *)org);
    }
    else
    {
        communicate = this->getName() + " have eaten " + org->getName();
        org->collision(this);
    }
}

void Animal::returnToPos()
{
    x = prevX;
    y = prevY;
}