#pragma once
#include "Animal.hpp"

class Human:public Animal
{
    private:
        int abilityCooldown=0;

    public:
        Human(int x, int y, World* world);
        Human(int x, int y, World* world, int cooldown);
        void action();
        void useAbility();
        void abilityRegen();
        void move();
        std::string getSaveString();
        Animal* newAnimal(int x, int y);
};