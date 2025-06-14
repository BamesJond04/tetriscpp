#ifndef SYSTEM_H
#define SYSTEM_H


#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <ncurses.h>
#include <string>

#include "block.h"

using namespace std;

class System {
    public:
        System(int width, int height, double gravity);

        //values/variables
        double gravity;
        int width, height;
        bool alive, blockInPlay;

        string flatArray;


        
        vector<Block> blocks;

        vector<vector<char> > systemArray;

        //functions
        void systemOut();
        void systemRun(char input);

        bool checkCollisions(vector<int> currentBlock);




        void giveSpacedArray();


    private:
};

#endif