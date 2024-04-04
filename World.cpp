#include "World.hpp"
#include "Organism.hpp"

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