#include "system.h"

using namespace std;

System::System(int width, int height, double gravity){
    this->width = width;
    this->height = height;
    this->gravity = gravity;

    vector<char> row(width, '0');

    this->systemArray = vector<vector<char> > (height,row);

    this->alive = true;
}


void System::systemOut(){
    for (const vector<char>& row : systemArray){
        for (const char& column: row){
            cout<<column<<" ";
        }
        cout<<"\n";
    }
}

void System::systemRun(){
    for (int i; i < 100; i ++){
        systemOut();
    }
}