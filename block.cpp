#include "block.h"


Block::Block(vector<int> startPosition){
    this->position = startPosition;
}


vector<int> Block::nextPosition(vector<int> currentPosition){
    int y = currentPosition[0];
    int x = currentPosition[1];

    vector<int> out;

    if (moveChar == 'a'){
        out = {y,x-1};
    } else if (moveChar == 'd'){
        out = {y,x+1};
    } else  {
        out = {y+1,x};
    }

    return out;
}

void Block::updatePosition(){
    vector<int> next = nextPosition(position);

    position = next;
    
}