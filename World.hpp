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
    bool* map =(bool*) calloc(witdh*height, sizeof(bool));
    void drawWorld();
    bool actTurn();
public:
    World() {}
    World(int witdh, int height): witdh(witdh), height(height) {}
    void mainloop();
    void addOrganism(Organism* organism);
    bool isOccupied(int x, int y);
    ~World();
};