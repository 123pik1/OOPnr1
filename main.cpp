#include "World.hpp"

int main()
{
    srand(time(NULL));
    initscr();
    keypad(stdscr, TRUE);
    noecho();
    curs_set(0);
    World world(20, 20);
    world.mainloop();
    endwin();
    return 0;
}