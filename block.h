#ifndef BLOCK_H
#define BLOCK_H


#include <iostream>
#include <vector>

#include "block.h"

using namespace std;

class Block {
    public: 
        Block(vector<int> startPosition);

        //currently block will be a single character (point)
        vector<int> position;

        vector<int> nextPosition(vector<int> currentPosition);
        void updatePosition();
        
    private:
}
;
#endif