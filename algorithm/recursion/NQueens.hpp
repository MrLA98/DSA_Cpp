#include <vector>
#include <iostream>

using namespace std;

int Queens;
vector<int> chess;
int Count = 0;
int Compare = 0;

void printChess(){
    cout << " [ ";
    for(auto it : chess){
        cout << it << " ";
    }
    cout << "]\n";
}

bool isVaild(int index, int n){
    for(int i = 0; i < n; ++i){
        cout << "check for ["<<++Compare << "] times\n";
        if(chess[i] == index || abs(i-n) == abs(chess[i]-index)){
            return false;
        }
    }
    return true;
}

void check(int n){
    if(n == Queens){
        ++Count;
        //cout << "# solution ["<<Count<<"]: ";
        printChess();
        return;
    }
    for(int i = 0; i < Queens; ++i){
        if(isVaild(i, n)){
            chess[n] = i;
            check(n+1);
        }
    }
}

void NQueensSolution(int q){
    Queens = q;
    chess.resize(q);
    check(0);
}
