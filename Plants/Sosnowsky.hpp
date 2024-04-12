#pragma once
#include "Plant.hpp"

class Sosnowsky : public Plant //barszcz Sosnowskiego
{
public:
    Sosnowsky(int x, int y, World* world);
    void collision(Organism* org);
    void action();
    Plant* newPlant(int x, int y);
};