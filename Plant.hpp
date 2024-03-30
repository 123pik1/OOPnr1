#include "Organism.hpp"

class Plant : public Organism
{

    public:
        Plant(int x, int y, int strength, char* symbol, World& world);

};