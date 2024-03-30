#include "World.hpp"
#include "Organism.hpp"

void World::mainloop()
{
    while (actTurn());
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