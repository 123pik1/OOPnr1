#pragma once
#include <ncurses.h>
#include <bits/stdc++.h>

using namespace std;

class Organism;

class World
{
private:
    int witdh;
    int height;
    vector<Organism*> organisms;
    bool* map ;
    void drawWorld();
    bool actTurn();
public:
    World() {}
    World(int witdh, int height);
    void mainloop();
    void addOrganism(Organism* organism);
    bool isOccupied(int x, int y);
    ~World();
};