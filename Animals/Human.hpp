#include "Animal.hpp"

class Human:public Animal
{
    private:
        int abilityCooldown=0;

    public:
        Human(int x, int y, World& world);
        void action();
        void useAbility();
        void abilityRegen();
        void move();
};