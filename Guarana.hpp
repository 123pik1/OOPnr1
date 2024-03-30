#pragma once
#include "Plant.hpp"

class Guarana : public Plant //guarana
{
public:
    Guarana(int x, int y,  World& world);
    Plant* newPlant(int x, int y);
    void collision(Organism* org);
    
    void action();
};