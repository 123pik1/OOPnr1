#include "Human.hpp"
using namespace std;
Human::Human(int x, int y, World* world) : Animal(x, y, 5, 4, "H", world, HUMAN)
{
}

Human::Human(int x, int y, World* world, int cooldown) : Animal(x, y, 5, 4, "H", world, HUMAN)
{
    abilityCooldown = cooldown;
}

void Human::action()
{
    prevX = x;
    prevY = y;
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
    
    switch (getch())
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
    abilityCooldown=5;
}

Animal* Human::newAnimal(int x, int y)
{
    return new Human(x, y, world);
}

string Human::getSaveString()
{
    saveString = to_string(x) + " " + to_string(y) + " " + to_string(strength)+" " + to_string(age) + " " + string(1,anSpecies) + string(1,plSpecies) + " " + to_string(abilityCooldown);
    return saveString;
}