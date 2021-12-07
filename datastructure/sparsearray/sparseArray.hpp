#include <vector>
#include <iostream>
using namespace std;

class Sparse{
private:
    vector<vector<int> > arr;
public:
    Sparse(vector<vector<int> > chessMap){
        arr.resize(1,vector<int>(3));
        arr[0][0] = chessMap.size();
        arr[0][1] = chessMap.front().size();
        arr[0][3] = 0;
        for(int i = 0; i < chessMap.size(); ++i){
            for(int j = 0; j < chessMap[i].size(); ++j){
                if(chessMap[i][j] != 0){
                    arr.push_back({i, j, chessMap[i][j]});
                    ++arr[0][2];
                }
            }
        }
    }

    // 恢复成棋盘
    vector<vector<int>> recover(){
        vector<vector<int>> chessMap(arr[0][0],vector<int>(arr[0][1]));
        for(int i = 1; i < arr.size(); ++i){
            chessMap[arr[i][0]][arr[i][1]] = arr[i][2];
        }
        return chessMap;
    }

    // 展示压缩数组
    void show(){
        for(auto row : arr){
            for(auto item : row){
                cout << item << "\t";
            }
            cout << endl;
        }
    }
};

void showChessMap(vector<vector<int>>& chessMap){
    for(auto row : chessMap){
        for(auto item : row){
            cout << item << " ";
        }
        cout << endl;
    }
}