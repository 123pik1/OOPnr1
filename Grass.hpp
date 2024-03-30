#pragma once
#include "Plant.hpp"

class Grass : public Plant
{
    public:
        Grass(int x, int y, int strength,  World& world);
        Plant* newPlant(int x, int y);
        void collision(Organism* org);
};