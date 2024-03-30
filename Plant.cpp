#include "Plant.hpp"

Plant::Plant(int x, int y, int strength, char* symbol, World& world) : Organism(x, y, strength, 0, symbol, world)
{
    
}

void Plant::action()
{
    int option = rand() % 10;
    if (option < 3)
    {
        
    }
}