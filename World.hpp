#pragma once
#include <ncurses.h>
// #include <nlohmann/json.hpp>
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <algorithm>
// using json = nlohmann::json;


class Organism;

class World
{
private:
    int witdh;
    int height;
    std::vector<Organism*> organisms;
    bool* map ;
    void drawWorld();
    bool actTurn();
    void saveWorld();
    void loadWorld();
    std::string communicate;
    void openWorld();
    void readWorld(std::fstream &file);

public:
    World();
    World(int witdh, int height);
    void mainloop();
    void addOrganism(Organism* organism);
    bool isOccupied(int x, int y);
    void removeOrganism(Organism* organism);
    bool setFalse(int x, int y);
    bool setTrue(int x, int y);
   
    Organism* getOrganism(int x, int y);
    int getWidth() {return witdh;}
    int getHeight() {return height;}
    ~World();
};