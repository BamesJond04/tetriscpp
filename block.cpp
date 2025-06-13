#include "block.h"


Block::Block(vector<int> startPosition, int width){
    this->position = startPosition;
    this->width =width;
}


vector<int> Block::nextPosition(vector<int> currentPosition){
    int y = currentPosition[0];
    int x = currentPosition[1];

    int xCorrect = checkBoundaries(x);

    vector<int> out = {y,x};

    //if (moveChar == 'a'){
        //out = {y,x-1+xCorrect};
    //} else if (moveChar == 'd'){
        //out = {y,x+1 + xCorrect};
    //} else if (moveChar == 'w'){
        ////add rotation of blocks
    //} else if (moveChar == 's'){
        //out = {y+1,x};
    //}
    
    switch (moveChar) {
        case 'a':
            out[1] += -1 + xCorrect;
            break;
        case 'd':
            out[1] += 1 + xCorrect;
            break;
        case 's':
            out[0] += 1+ xCorrect;
            break;
    }

    out[0] += 1;
    return out;
}

void Block::updatePosition(){
    vector<int> next = nextPosition(position);
    position = next;
}

signed int Block::checkBoundaries(int x){
    if (x > width-1){
        return -1;
    } else if (x<=0){
        return +1;
    } else {
        return 0;
    }
}