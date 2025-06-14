#include "system.h"

using namespace std;

System::System(int width, int height, double gravity){
    this->width = width;
    this->height = height + 1;
    this->gravity = gravity;

    vector<char> row(width, '0');

    this->systemArray = vector<vector<char> > (height,row);

    this->alive = true;


    for (int i = 0 ; i < 1; i ++){
        Block insertion = Block (vector<int> {0,3}, width);
        blocks.push_back(insertion);
    }

    this->blockInPlay = true;



}



void System::giveSpacedArray(){
    string out = "";
    for (const vector<char>& row : systemArray){
        string s(row.begin(),row.end());
        out += s + "\n";
    }
    flatArray = out;
}

void System::systemOut(){
    systemArray[height-1] = vector<char> (width, ' ');
    giveSpacedArray();
    const char *out = flatArray.c_str();
    printw(out);
}   

void System::systemRun(char input){
    clear();
        for (int i = 0; i < blocks.size(); i++){

            systemArray[blocks[i].position[0]][blocks[i].position[1]]  = '0';
            
            blocks[i].moveChar = input;

            vector<int> nextPos = blocks[i].nextPosition(blocks[i].position);

            bool collision = checkCollisions(nextPos);
 
            if (collision){
                systemArray[blocks[i].position[0]][blocks[i].position[1]] = '#';
                if (systemArray[blocks[i].position[0]+1][blocks[i].position[1]] == '#' || (blocks[i].position[0]+1)>= height-1){
                    blocks[i].position = vector<int> {0,3};
                }
            } else {
                blocks[i].updatePosition();
                systemArray[blocks[i].position[0]][blocks[i].position[1]] = '#';
            }
            
        }

        systemOut();
        refresh();

        napms(300);
}


bool System::checkCollisions(vector<int> currentBlock){
    //returns true if a collision is occuring
    int y = currentBlock[0];
    int x = currentBlock[1];

    char thisPosition = systemArray[y][x];

    bool out = false;

    if (thisPosition == '#' || y >= height-1){
        out = true;
    }

    return out;
}