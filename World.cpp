#include "World.hpp"
#include "Organism.hpp"

void World::mainloop()
{

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