#pragma once
#include "Animal.hpp"

class Fox : public Animal
{
    public:
        Fox(int x, int y, World *world);
        Animal* newAnimal(int x, int y);
        void action();
};