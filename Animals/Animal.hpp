#pragma once
#include "../Organism.hpp"

class Animal : public Organism
{
    protected:
        int prevX;
        int prevY;
    public:
        Animal(int x, int y, int strength, int initiative, char *symbol, World *world, animalTypes anSpecies, std::string name);
        virtual void action();
        virtual void collision(Organism *org);
        virtual void move();
        virtual void returnToPos();
        virtual void fight(Organism *org);
        virtual void anCollision(Animal *org);
        virtual void moving(int dist, int direction);
        virtual Animal* newAnimal(int x, int y)=0;
        int getPrevX(){return prevX;}
        int getPrevY(){return prevY;}
};