#include "Animal.hpp"

class Fox : public Animal
{
    public:
        Fox(int x, int y, World &world):Animal(x, y, 3, 3, "F", world, FOX)
        {
        }
        Animal* newAnimal(int x, int y)
        {
            return new Fox(x, y, world);
        }
};