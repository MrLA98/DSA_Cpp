#include <iostream>

using namespace std;

void hannoiTowerSolution(int num, char start, char help, char end){
    if(num == 1){
        cout << "move plate [1] from [" << start << "] to [" << end <<"]\n";
        return;
    }
    hannoiTowerSolution(num-1, start, end, help);
    cout << "move plate ["<< num <<"] from [" << start << "] to [" << end <<"]\n";
    hannoiTowerSolution(num-1, help, start, end);
}