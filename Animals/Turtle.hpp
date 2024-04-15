#pragma once
#include "Animal.hpp"
using namespace std;
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

    
    void fight(Organism *org)
    {
        Animal *anim = (Animal *)org;
        if (anim->getStrength() < 5)
        {
            anim->returnToPos();
            communicate="Turtle blocked attack";
        }
        else
        {
            Animal::fight(org);
        }
    }
    
};