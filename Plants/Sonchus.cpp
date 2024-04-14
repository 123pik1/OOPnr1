#include "Sonchus.hpp"

Sonchus::Sonchus(int x, int y,  World* world) : Plant(x, y, 0, "O", SONCHUS, world, "Sonchus")
{
}



Plant* Sonchus::newPlant(int x, int y)
{
    return new Sonchus(x, y,  world);
}

void Sonchus::action()
{
    for(int i = 0; i < 3; i++)
    {
        Plant::action();
    }
}