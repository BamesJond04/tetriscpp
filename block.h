#ifndef BLOCK_H
#define BLOCK_H


#include <iostream>
#include <vector>

#include "block.h"

using namespace std;

class Block {
    public: 
        Block(vector<int> startPosition,int width);

        //currently block will be a single character (point)
        vector<int> position;

        int width;

        char moveChar;

        vector<int> nextPosition(vector<int> currentPosition);
        void updatePosition();

        signed int checkBoundaries(int x);
        
    private:
}
;
#endif