#pragma once
#include "Animal.hpp"

class Turtle : public Animal
{
public:
    Turtle(int x, int y, World *world) : Animal(x, y, 2, 1, "T", world, TURTLE, "Turtle")
    {
    }

    Animal *newAnimal(int x, int y)
    {
        return new Turtle(x, y, world);
    }
    void action()
    {
        int random = rand() % 4;
        if (random == 0)
        {
            Animal::action();
        }
    }

    void collision(Organism *org)
    {
        Animal *anim = (Animal *)org;
        if (org->getStrength() < 5)
        {

            anim->returnToPos();
            communicate="Turtle blocked attack";
        }
        else
        {
            Animal::collision(org);
        }
    }
};