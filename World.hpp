#pragma once
#include <ncurses.h>
// #include <nlohmann/json.hpp>
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
// using json = nlohmann::json;

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
    void removeOrganism(Organism* organism);
    Organism* getOrganism(int x, int y);
    void readMap();
    void readWorld();
    ~World();
};