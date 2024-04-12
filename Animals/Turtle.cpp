#include "Turtle.hpp"  

Turtle::Turtle(int x, int y, World *world):Animal(x, y, 2, 1, "T", world, TURTLE)
{
}

Animal* Turtle::newAnimal(int x, int y)
{
    return new Turtle(x, y, world);
}

void Turtle::action()
{
    int random = rand() % 4;
    if (random == 0)
    {
        Animal::action();
    }
}

void Turtle::collision(Organism* org)
{
    Animal* anim = (Animal*)org;
    if (org->getStrength() < 5)
    {
        
        anim->returnToPos();
    }
    else
    {
        Animal::collision(org);
    }
}

