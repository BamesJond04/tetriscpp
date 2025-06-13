#include "system.h"

using namespace std;

System::System(int width, int height, double gravity){
    this->width = width;
    this->height = height;
    this->gravity = gravity;

    vector<char> row(width, '0');

    this->systemArray = vector<vector<char> > (height,row);

    this->alive = true;


    for (int i = 0 ; i < 1; i ++){
        Block insertion = Block (vector<int> {0,3});
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
    giveSpacedArray();
    const char *out = flatArray.c_str();
    printw(out);
}   

void System::systemRun(char input){
    clear();
        for (int i = 0; i < blocks.size(); i++){

            systemArray[blocks[i].position[0]][blocks[i].position[1]]  = '0';
            blocks[i].moveChar = input;
            blocks[i].updatePosition();
            
            //if (checkBoundaries(blocks[i].position) == true){
                //systemArray[blocks[i].position[0]-1][blocks[i].position[1]]  = '#';
                //blocks[i].position = vector<int> {0,3};
            if (checkCollisions(blocks[i].position)==true){
                systemArray[blocks[i].position[0]-1][blocks[i].position[1]]  = '#';
                blocks[i].position = vector<int> {0,3};}
            else {
                systemArray[blocks[i].position[0]][blocks[i].position[1]] = '#';
            }
        }
        systemOut();
        refresh();
}

bool System::checkBoundaries(vector<int> currentBlock){
    //returns true if outside boundaries
    int y = currentBlock[0];
    int x = currentBlock[1];

    if (y >= height  -1|| y < 0){
        return true;
    } else if (x >= width-1 || x < 0){
        return true;
    } else {
        return false;
    }
}

bool System::checkCollisions(vector<int> currentBlock){
    //returns true if a collision is occuring
    int y = currentBlock[0];
    int x = currentBlock[1];

    if (y >= height){
        return true;
    } else if ( systemArray[y][x] ==  '#'){
        return true;
    } else {
        return false;
    }
}