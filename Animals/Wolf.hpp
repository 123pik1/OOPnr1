#include "Animal.hpp"

class Wolf : public Animal
{
    public:
        Wolf(int x, int y, World *world):Animal(x, y, 9, 5, "W", world, WOLF, "Wolf")
        {
        }
        Wolf(int x, int y, int strength, World *world, int age):Animal(x, y, strength, 5, "W", world, WOLF, "Wolf", age)
        {
        }
        Animal* newAnimal(int x, int y)
        {
            return new Wolf(x, y, world);
        }
};