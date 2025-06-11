#ifndef SYSTEM_H
#define SYSTEM_H


#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#include "block.h"

using namespace std;

class System {
    public:
        System(int width, int height, double gravity);

        //values/variables
        double gravity;
        int width, height;
        bool alive, blockInPlay;
        
        vector<Block> blocks;

        vector<vector<char> > systemArray;

        //functions
        void systemOut();
        void systemRun();

        bool checkBoundaries(vector<int> currentBlock);
        bool checkCollisions(vector<int> currentBlock);


    private:
};

#endif