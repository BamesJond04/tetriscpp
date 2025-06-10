#include <iostream>
#include <vector>

using namespace std;

class System {
    public:
        System(int width, int height, double gravity);

        //values/variables
        double gravity;\
        int width, height;
        bool alive;
        

        vector<vector<char> > systemArray;

        //functions
        void systemOut();
        void systemRun();



    private:
};