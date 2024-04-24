#pragma once
#include "Animal.hpp"

class Sheep : public Animal
{
    public:
        Sheep(int x, int y, World *world):Animal(x, y, 4, 4, "S", world, SHEEP, "Sheep")
        {
        }
        Sheep(int x, int y, int strength, World *world, int age):Animal(x, y, strength, 4, "S", world, SHEEP, "Sheep", age)
        {
        }
        Animal* newAnimal(int x, int y)
        {
            return new Sheep(x, y, world);
        }
};