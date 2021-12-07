#include "sortAlgorithm.hpp"
#include <string>
#include <iostream>
#include <algorithm>
#include <ctime>

class sortChecker{
public:
    // 构造器，创建函数指针
    sortChecker(){
        func = Insertion::Sort2;
        name = "insertion sort -move";
    }
    // 有参构造
    sortChecker(char ch){
        switch(ch){
            case 's':
                func = Selection::Sort;
                name = "selection sort";
                break;
            case 'B':
                func = Bubble::Sort;
                name = "bubble sort";
                break;
            case 'b':
                func = Bubble::Sort2;
                name = "bubble sort v2";
                break;
            case 'I':
                func = Insertion::Sort;
                name = "insertion sort -swap";
                break;
            case 'i':
                func = Insertion::Sort2;
                name = "insertion sort -move";
                break;
            case 'L':
                func = Shell::Sort;
                name = "shell sort -swap";
                break;
            case 'l':
                func = Shell::Sort2;
                name = "shell sort -move";
                break;
            case 'Q':
                func = Quick::Sort;
                name = "quick sort";
                break;
            case 'M':
                func = Merge::Sort;
                name = "merge sort";
                break;
            case 'R':
                func = Radix::Sort;
                name = "radix sort";
                break;
            case 'H':
                func = Heap::Sort;
                name = "heap sort";
                break;
            default:
                func = Insertion::Sort2;
                name = "insertion sort -move";
                break;
        }
    }

    // 对外接口
    void checkTest(int max, int len, int time){
        srand(::time(NULL));
        cout << "[" << name << "] Test begin:" << endl;
        clock_t start = clock();
        for(int i = 0; i < time; ++i){
            vector<int> arr1, arr2;
            // 创建一个数组
            randomArr(arr1, -max, max, len);
            // 拷贝一份数组
            arr2 = arr1;
            // 官方排序
            sort(arr2.begin(), arr2.end());
            // 我的排序
            func(arr1);
            // 比较
            if(arr1 != arr2){
                show(arr1);
                show(arr2);
                cout<<"Fxxk!"<<endl;
                return;
            }
        }
        clock_t end = clock();
        cout << "Nice! it spent " << (double)(end-start)/CLOCKS_PER_SEC << " s" << endl << endl;
    }
private:
    // 函数指针
    void (*func)(vector<int>&);
    // 名称
    string name;

    // 显示函数
    void show(vector<int> &arr){
        cout << '[';
        for(auto it : arr){
            cout << it << "\t";
        }
        cout << ']' <<endl;
    }

    // 生成随机数数组
    void randomArr(vector<int>& arr, int min, int max, int len){
        if(name == "radix sort") min = 0;
        arr.resize(len);
        for(int i = 0; i < len; ++i){
            arr[i] = (rand() % (max-min+1)) + min;
        }
    }
};