#include "World.hpp"

int main()
{
    srand(time(NULL));
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    World world;
    world.mainloop();
    endwin();
    return 0;
}