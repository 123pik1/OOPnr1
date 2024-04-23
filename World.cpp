#include "World.hpp"
#include "Organism.hpp"
#include "./Animals/Wolf.hpp"
#include "./Animals/Sheep.hpp"
#include "./Animals/Fox.hpp"
#include "./Animals/Turtle.hpp"
#include "./Animals/Antelope.hpp"
#include "./Plants/Grass.hpp"
#include "./Plants/Guarana.hpp"
#include "./Plants/Belladonna.hpp"
#include "./Plants/Sosnowsky.hpp"
#include "./Plants/Sonchus.hpp"
#include "./Animals/Human.hpp"

using namespace std;

World::World(int witdh, int height)
{
    this->witdh = witdh;
    this->height = height;
    map = (bool *)malloc(witdh * height * sizeof(bool));
    for (int i = 0; i < witdh * height; i++)
    {
        map[i] = false;
    }
    openWorld();
    drawWorld();
}

World::World()
{
    openWorld();
    drawWorld();
}
void World::mainloop()
{
    while (actTurn())
        drawWorld();
    endwin();
}
bool World::actTurn()
{
    communicate = "";
    sort(organisms.begin(), organisms.end(), [](Organism *a, Organism *b)
         {
        if (a->getInitiative() == b->getInitiative())
        {
            return a->getAge() > b->getAge();
        }
        return a->getInitiative() > b->getInitiative(); });

    for (int i = 0; i < organisms.size(); i++)
    {
        if (organisms[i]->getAlive())
        {
            organisms[i]->action();
            if (organisms[i] != NULL && communicate == "")
            {
                communicate = organisms[i]->getCommunicate();
            }
        }
    }
    for (int i = 0; i < organisms.size(); i++)
    {
        if (organisms[i]->getAlive() == false)
        {
            removeOrganism(organisms[i]);
            i--;
        }
    }
    WINDOW *win = newwin(2, 40, 3, 0);
    mvwprintw(win, 1, 1, "Press q to quit, s to save, l to load");
    refresh();
    wrefresh(win);
    switch (getch())
    {
    case 'q':
        return false;
        break;
    case 's':
        saveWorld();
        break;
    case 'l':
        loadWorld();
        break;
    default:
        break;
    }
    delwin(win);
    return true;
}

bool World::setFalse(int x, int y)
{
    if (x < 0 || y < 0 || x >= witdh || y >= height)
    {
        return false;
    }
    map[x + y * witdh] = false;
    return true;
}
bool World::setTrue(int x, int y)
{
    if (x < 0 || y < 0 || x >= witdh || y >= height)
    {
        return false;
    }
    map[x + y * witdh] = true;
    return true;
}

void World::drawWorld()
{
    clear();
    WINDOW *win = newwin(height + 2, witdh + 2, 5, 0);
    refresh();
    box(win, 0, 0);
    WINDOW *communicateWin = newwin(3, 40, 0, 0);
    refresh();
    mvprintw(0, 50, "Piotr Kaczorowski 197736");
    box(communicateWin, 0, 0);
    mvwprintw(communicateWin, 1, 1, communicate.c_str());
    wrefresh(communicateWin);
    for (auto org : organisms)
    {
        org->draw(win);
    }
    wrefresh(win);
    wrefresh(communicateWin);
    refresh();
    delwin(win);
    delwin(communicateWin);
}

void World::addOrganism(Organism *organism)
{

    if (organism->getX() >= 0 && organism->getY() >= 0 && organism->getX() < witdh && organism->getY() < height)
    {
        map[organism->getX() + organism->getY() * witdh] = true;
        organisms.push_back(organism);
    }
    else
    {
        delete organism;
    }
}

World::~World()
{
    for (int i = 0; i < organisms.size(); i++)
    {
        delete organisms[i];
    }
    free(map);
}

bool World::isOccupied(int x, int y)
{
    for (auto org : organisms)
    {
        if (org->getX() == x && org->getY() == y)
        {
            return true;
        }
    }
    return false;
}

void World::removeOrganism(Organism *organism)
{
    for (int i = 0; i < organisms.size(); i++)
    {
        if (organisms[i] == organism)
        {
            organisms.erase(organisms.begin() + i);
            map[organism->getX() + organism->getY() * witdh] = false;
            delete organism;

            break;
        }
    }
}

Organism *World::getOrganism(int x, int y)
{
    for (int i = 0; i < organisms.size(); i++)
    {
        if (organisms[i]->getX() == x && organisms[i]->getY() == y)
        {
            return organisms[i];
        }
    }
    return NULL;
}
void World::openWorld()
{
    fstream file("world.txt", ios::in);
    if (file.is_open())
    {
        readWorld(file);
    }
    else
    {
        cout << "Error while opening file" << endl;
    }
}
void World::loadWorld()
{
    fstream file("save.txt", ios::in);
    if (file.is_open())
    {
        for (int i = 0; i < organisms.size(); i++)
        {
            delete organisms[i];
        }
        organisms.clear();
        readWorld(file);
    }
    else
    {
        cout << "Error while opening file" << endl;
    }
}
void World::readWorld(fstream &file)
{
    int x, y, strength;
    string species;
    int cooldown;
    int age;
    Organism *org;
    if (file.is_open())
    {
        file >> witdh >> height;

        map = (bool *)malloc(witdh * height * sizeof(bool));

        for (int i = 0; i < witdh * height; i++)
        {
            map[i] = false;
        }

        while (!file.eof())
        {

            file >> x >> y >> strength >> age >> species;
            cout << "File opened" << endl;
            cout << x << " " << y << " " << strength << " " << age << " " << species << endl;
            if (species == "W")
            {
                org = new Wolf(x, y, this);
            }
            else if (species == "S")
            {
                org = new Sheep(x, y, this);
            }
            else if (species == "F")
            {
                org = new Fox(x, y, this);
            }
            else if (species == "T")
            {
                org = new Turtle(x, y, this);
            }
            else if (species == "A")
            {
                org = new Antelope(x, y, this);
            }
            else if (species == "G")
            {
                org = new Grass(x, y, this);
            }
            else if (species == "U")
            {
                org = new Guarana(x, y, this);
            }
            else if (species == "B")
            {
                org = new Belladonna(x, y, this);
            }
            else if (species == "O")
            {
                org = new Sosnowsky(x, y, this);
            }
            else if (species == "M")
            {
                org = new Sonchus(x, y, this);
            }
            else if (species == "H")
            {
                file >> cooldown;
                org = new Human(x, y, this, cooldown);
            }
            org->setAge(age);
            org->setStrength(strength);
            addOrganism(org);
        }
    }
    else
    {
        cout << "Error while opening file" << endl;
    }
}

void World::saveWorld()
{
    fstream file("save.txt", ios::out);
    if (file.is_open())
    {
        file << witdh << " " << height << endl;
        for (int i = 0; i < organisms.size(); i++)
        {
            file << organisms[i]->getSaveString() << endl;
        }
    }
    else
    {
        cout << "Error while opening file" << endl;
    }
}