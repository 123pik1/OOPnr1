#include "Human.hpp"
using namespace std;
Human::Human(int x, int y, World *world) : Animal(x, y, 5, 4, "H", world, HUMAN, "Human")
{
}

Human::Human(int x, int y, World *world, int cooldown) : Animal(x, y, 5, 4, "H", world, HUMAN, "Human")
{
    abilityCooldown = cooldown;
}

void Human::action()
{
    communicate = "";
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
    WINDOW *win = newwin(2, 40, 3, 0);
    mvwprintw(win, 1, 1, "Human move");
    refresh();
    wrefresh(win);
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
    default:
        break;
    }
    wclear(win);
    wrefresh(win);
    if (abilityCooldown == 0)
    {
        mvwprintw(win, 1, 1, "use ability?");

        if (getch() == 'u')
        {
            communicate = "Human used ability";
            useAbility();
        }
    }
    delwin(win);
}

void Human::anCollision(Animal *org)
{
    if (org->getStrength() > strength)
    {
        this->die();
    }
    else
    {
        communicate = name + " killed " + org->getName();
        org->die();
    }
}

void Human::collision(Organism *org)
{
    if (org->getType() == ANIMAL)
    {
        anCollision((Animal *)org);
    }
    else
    {
        communicate = name + " ate " + org->getName();
        org->collision(this);
        org->die();
    }
}
void Human::useAbility()
{
    strength = 10;
    abilityCooldown = 5;
}

Animal *Human::newAnimal(int x, int y)
{
    return new Human(x, y, world);
}

string Human::getSaveString()
{
    saveString = to_string(x) + " " + to_string(y) + " " + to_string(strength) + " " + to_string(age) + " " + string(1, anSpecies) + string(1, plSpecies) + " " + to_string(abilityCooldown);
    return saveString;
}