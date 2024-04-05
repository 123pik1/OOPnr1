#include "World.hpp"

int main()
{
    World world(20, 20);
    world.readMap();
    world.mainloop();

    return 0;
}