#pragma once
#include "Plant.hpp"

class Sonchus : public Plant //mlecz
{
public:
    Sonchus(int x, int y,  World* world);
    Plant* newPlant(int x, int y);
    void collision(Organism* org);
    void action();
};