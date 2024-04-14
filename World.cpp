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
    addOrganism(new Grass(5, 5, this));
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
    communicate = "";
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
        if (organisms[i]!=NULL && communicate=="")
        {
            communicate = organisms[i]->getCommunicate();
        }
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
    WINDOW *win = newwin(height+2, witdh+2, 5, 0);
    refresh();
    box(win, 0, 0);
    // mvwprintw(win, 1, 1, "World");
    WINDOW *communicateWin = newwin(5, 50, 0, 0);
    refresh();
    box(communicateWin, 0, 0);
    mvwprintw(communicateWin, 1, 1, communicate.c_str());
    wrefresh(communicateWin);
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
            cout << x << " " << y << " " << strength<<" " << age << " " << species << endl;
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
                // if (file.good())
                // {file >> cooldown;

                // org = new Human(x, y, this, cooldown);}
                // else
                // {
                //     org = new Human(x, y, this);
                // }
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