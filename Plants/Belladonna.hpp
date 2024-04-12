#pragma once
#include "Plant.hpp"

class Belladonna : public Plant //wilcza jagoda
{
public:
    Belladonna(int x, int y, World* world);
    Plant* newPlant(int x, int y);
    void collision(Organism* org);
    void action();
};