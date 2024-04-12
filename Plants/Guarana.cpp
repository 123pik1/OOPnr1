#include "Guarana.hpp"

Guarana::Guarana(int x, int y, World* world) : Plant(x, y, 0, "G", GUARANA, world)
{

}

void Guarana::collision(Organism* org)
{
    org->setStrength(org->getStrength() + 3);
    this->die();
}
void Guarana::action()
{
    Plant::action();
}
Plant* Guarana::newPlant(int x, int y)
{
    return new Guarana(x, y, world);
}