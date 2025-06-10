

#include <vector>
#include <iostream>

#include "system.h"
#include "block.h"

using namespace std;

int main(){

    System game(5,5,9.8);

    game.systemRun();

    return 0;
}