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
    map = (bool *)calloc(witdh * height, sizeof(bool));
    for (int i = 0; i < witdh * height; i++)
    {
        map[i] = false;
    }
    readWorld();
    drawWorld();
    addOrganism(new Wolf(5, 5, this));
    addOrganism(new Wolf(5, 7, this));
    addOrganism(new Wolf(5, 9, this));
    addOrganism(new Wolf(5, 11, this));
    addOrganism(new Wolf(5, 8, this));
    addOrganism(new Wolf(5, 7, this));
    addOrganism(new Wolf(5, 2, this));
    addOrganism(new Wolf(5, 19, this));
    addOrganism(new Grass(5, 6, this));

}

void World::mainloop()
{
    while (actTurn())
        drawWorld();
    endwin();
}
bool World::actTurn()
{
    sort(organisms.begin(), organisms.end(), [](Organism *a, Organism *b) {
        if (a->getInitiative() == b->getInitiative())
        {
            return a->getAge() > b->getAge();
        }
        return a->getInitiative() > b->getInitiative();
    });
    if (getch() == 'q')
        return false;
    for (auto org : organisms)
    {
        org->action();
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
    // WINDOW *win = newwin(15, 20, 10, 15);
    // box(win, 1, 1);
    // mvwprintw(win, 1, 1, "World");
    for (auto org : organisms)
    {
        org->draw();
    }
    refresh();
}

void World::addOrganism(Organism *organism)
{
    organisms.push_back(organism);
    map[organism->getX() + organism->getY() * witdh] = true;
}

World::~World()
{
    for (int i = 0; i < organisms.size(); i++)
    {
        delete organisms[i];
    }
    // free(map);
}

bool World::isOccupied(int x, int y)
{
    return map[x + y * witdh];
}

void World::removeOrganism(Organism *organism)
{
    for (int i = 0; i < organisms.size(); i++)
    {
        if (organisms[i] == organism)
        {
            
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

void World::readMap()
{
}

void World::readWorld()
{
    fstream file("world.txt");
    int x, y, strength;
    string species;
    int nmbOfOrganisms;
    if (file.is_open())
    {
        file >> nmbOfOrganisms;
        for (int i = 0; i < nmbOfOrganisms; i++)
        {
            file >> x >> y >> strength >> species;
            if (species == "Wolf")
            {
                addOrganism(new Wolf(x, y, this));
            }
            else if (species == "Sheep")
            {
                addOrganism(new Sheep(x, y, this));
            }
            else if (species == "Fox")
            {
                addOrganism(new Fox(x, y, this));
            }
            else if (species == "Turtle")
            {
                addOrganism(new Turtle(x, y, this));
            }
            else if (species == "Antelope")
            {
                addOrganism(new Antelope(x, y, this));
            }
            else if (species == "Grass")
            {
                addOrganism(new Grass(x, y, this));
            }
            else if (species == "Guarana")
            {
                addOrganism(new Guarana(x, y, this));
            }
            else if (species == "Belladonna")
            {
                addOrganism(new Belladonna(x, y, this));
            }
            else if (species == "Sosnowsky")
            {
                addOrganism(new Sosnowsky(x, y, this));
            }
            else if (species == "Sonchus")
            {
                addOrganism(new Sonchus(x, y, this));
            }
        }
    }
}