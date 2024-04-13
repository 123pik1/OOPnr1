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
    readWorld();
    drawWorld();
   
}


World::World()
{
    readWorld();

    
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
    sort(organisms.begin(), organisms.end(), [](Organism *a, Organism *b)
         {
        if (a->getInitiative() == b->getInitiative())
        {
            return a->getAge() > b->getAge();
        }
        return a->getInitiative() > b->getInitiative(); });
    if (getch() == 'q')
        return false;

    for (int i = 0; i < organisms.size(); i++)
    {
        organisms[i]->action();
    }
    return true;
}

void World::setFalse(int x, int y)
{
    map[x + y * witdh] = false;
}
void World::setTrue(int x, int y)
{
    map[x + y * witdh] = true;
}

void World::drawWorld()
{
    clear();
    WINDOW *win = newwin(height+2, witdh+2, 0, 0);
    refresh();
    box(win, 0, 0);
    // mvwprintw(win, 1, 1, "World");
    for (auto org : organisms)
    {
        org->draw(win);
    }
    wrefresh(win);
    refresh();
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
    if (x < 0 || y < 0 || x >= witdh || y >= height)
    {
        return false;
    }
    return map[x + y * witdh];
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



void World::readWorld()
{
    fstream file("world.txt");
    int x, y, strength;
    string species;
    int cooldown;
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
            file >> x >> y >> strength >> species;
            if (species == "W")
            {
                addOrganism(new Wolf(x, y, this));
            }
            else if (species == "S")
            {
                addOrganism(new Sheep(x, y, this));
            }
            else if (species == "F")
            {
                addOrganism(new Fox(x, y, this));
            }
            else if (species == "T")
            {
                addOrganism(new Turtle(x, y, this));
            }
            else if (species == "A")
            {
                addOrganism(new Antelope(x, y, this));
            }
            else if (species == "G")
            {
                addOrganism(new Grass(x, y, this));
            }
            else if (species == "U")
            {
                addOrganism(new Guarana(x, y, this));
            }
            else if (species == "B")
            {
                addOrganism(new Belladonna(x, y, this));
            }
            else if (species == "S")
            {
                addOrganism(new Sosnowsky(x, y, this));
            }
            else if (species == "M")
            {
                addOrganism(new Sonchus(x, y, this));
            }
            else if (species == "H")
            {
                file >> cooldown;
                addOrganism(new Human(x, y, this, cooldown));
            }
        }
    }
}