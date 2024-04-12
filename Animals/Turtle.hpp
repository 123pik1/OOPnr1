#pragma once
#include "Animal.hpp"

class Turtle : public Animal
{
    public:
        Turtle(int x, int y, World *world);
        void action();
        Animal* newAnimal(int x, int y);
        void collision(Organism* org);
};