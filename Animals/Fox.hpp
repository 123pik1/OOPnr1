#pragma once
#include "Animal.hpp"

class Fox : public Animal
{
    public:
        Fox(int x, int y, World *world);
        Fox(int x, int y, int strength, World *world, int age);
        Animal* newAnimal(int x, int y);
        void action();
};