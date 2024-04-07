#pragma once
#include "Animal.hpp"

class Antelope : public Animal
{
    public:
        Antelope(int x, int y, World &world);
        void action();
        Animal* newAnimal(int x, int y);
        void collision(Organism* org);
};