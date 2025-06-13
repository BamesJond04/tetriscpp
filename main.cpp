

#include <vector>
#include <iostream>

#include "system.h"
#include <curses.h>

using namespace std;

int main(int argc, char ** argv){

    char input;
    initscr();

    refresh();
    System game(10,10,9.8);

    halfdelay(1);

    game.systemOut();
    refresh();

    for (int i; i <100; i++){
        input = getch();
        game.systemRun(input);
    }

    return 0;
}