#pragma once
#include "Organism.hpp"

class Animal : public Organism
{
    public:
        Animal(int x, int y, int strength, int initiative, char *symbol, World &world, animalTypes anSpecies);
        virtual void action();
        virtual void collision(Organism *org);
        virtual void move(int dist);
        virtual void fight(Organism *org);
        virtual void anCollision(Animal *org);

};