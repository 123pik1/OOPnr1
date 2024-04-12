#pragma once
#include "Plant.hpp"

class Grass : public Plant
{
public:
    Grass(int x, int y, World *world):Plant(x, y, 0, "G", GRASS, world)
    {
    }
    Plant *newPlant(int x, int y) { return new Grass(x, y, world); }
};