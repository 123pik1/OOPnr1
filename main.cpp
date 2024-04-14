#include "World.hpp"

int main()
{
    srand(time(NULL));
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    World world(10,10);
    world.mainloop();
    endwin();
    return 0;
}