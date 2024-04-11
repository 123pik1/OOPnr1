#include "World.hpp"

int main()
{
    initscr();
    noecho();
    World world(20, 20);
    world.mainloop();
    endwin();
    return 0;
}