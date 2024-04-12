#pragma once
#include "Plant.hpp"

class Grass : public Plant
{
    public:
        Grass(int x, int y, World* world);
        Plant* newPlant(int x, int y);
};