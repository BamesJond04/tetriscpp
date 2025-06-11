

#include <vector>
#include <iostream>

#include "system.h"

using namespace std;

int main(){
    cout<<"runningGame"<<endl;

    System game(10,10,9.8);

    game.systemRun();

    return 0;
}