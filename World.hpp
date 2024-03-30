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

public:
    World() {}
    World(int witdh, int height): witdh(witdh), height(height) {}
    void addOrganism(Organism* organism);
};