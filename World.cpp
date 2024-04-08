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


World::World(int witdh, int height)
{
    this->witdh = witdh;
    this->height = height;
    map=(bool*) calloc(witdh*height, sizeof(bool));
    for (int i = 0; i < witdh * height; i++)
    {
        map[i] = false;
    }
}

void World::mainloop()
{
    initscr();
    while (actTurn());
    endwin();
}

bool World::actTurn()
{
    for (int i = 0; i < organisms.size(); i++)
    {
        organisms[i]->action();
    }
    drawWorld();
    return true;
}

void World::drawWorld()
{
    clear();
    WINDOW *win = newwin(height, witdh, 0, 0);
    box(win, 0, 0);
    for (int i = 0; i < organisms.size(); i++)
    {
        organisms[i]->draw();
    }
    refresh();
}



void World::addOrganism(Organism* organism)
{
    organisms.push_back(organism);
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
    return map[x + y * witdh];
}

void World::removeOrganism(Organism* organism)
{
    for (int i = 0; i < organisms.size(); i++)
    {
        if (organisms[i] == organism)
        {
            organisms.erase(organisms.begin() + i);
            break;
        }
    }
}

Organism* World::getOrganism(int x, int y)
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
    int x,y,strength;
    string species;
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> x >> y >> strength >> species;
            if (species == "Wolf")
            {
                addOrganism(new Wolf(x, y, *this));
            }
            else if (species == "Sheep")
            {
                addOrganism(new Sheep(x, y, *this));
            }
            else if (species == "Fox")
            {
                addOrganism(new Fox(x, y, *this));
            }
            else if (species == "Turtle")
            {
                addOrganism(new Turtle(x, y, *this));
            }
            else if (species == "Antelope")
            {
                addOrganism(new Antelope(x, y, *this));
            }
            else if (species == "Grass")
            {
                addOrganism(new Grass(x, y, *this));
            }
            else if (species == "Guarana")
            {
                addOrganism(new Guarana(x, y, *this));
            }
            else if (species == "Belladonna")
            {
                addOrganism(new Belladonna(x, y, *this));
            }
            else if (species == "Sosnowsky")
            {
                addOrganism(new Sosnowsky(x, y, *this));
            }
            else if (species == "Sonchus")
            {
                addOrganism(new Sonchus(x, y, *this));
            }
            
        }
    }



}