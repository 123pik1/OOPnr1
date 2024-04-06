#include "Human.hpp"

Human::Human(int x, int y, World& world) : Animal(x, y, 5, 4, "H", world, HUMAN)
{
}

void Human::action()
{
    if (abilityCooldown > 0)
    {
        abilityRegen();
    }
    else 
    {
        useAbility();
    }
    Animal::action();
    
}

void Human::abilityRegen()
{
    abilityCooldown--;
    strength--;
}

void Human::move()
{
    int direction;
    int dist = 1;
    std::cin >> direction;
    switch (direction)
    {
        case KEY_DOWN:
            moving(dist, 1);
            break;
        case KEY_UP:
            moving(dist, 0);
            break;
        case KEY_LEFT:
            moving(dist, 2);
            break;
        case KEY_RIGHT:
            moving(dist, 3);
            break;
    }
}


void Human::useAbility()
{
    strength=10;
}

