#pragma once
#include "Organism.hpp"

class Plant : public Organism
{

    public:
        Plant(int x, int y, int strength, char* symbol,plantTypes type, World& world);
        virtual void action();
        virtual Plant* newPlant(int x, int y)=0;
        void collision(Organism* org);
};