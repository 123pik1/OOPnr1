#pragma once
#include "Animal.hpp"

class Antelope : public Animal
{
    public:
        Antelope(int x, int y, World *world);
        Antelope(int x, int y, int strength, World *world, int age);
        Animal* newAnimal(int x, int y);
        void collision(Organism* org);
        void move();
        void retreat();
};