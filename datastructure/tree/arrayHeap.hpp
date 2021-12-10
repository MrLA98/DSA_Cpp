#include <iostream>
#include <string>

using namespace std;

class item{
public:
    int key;
    string name;
    item(int k, string n):key(k), name(n){}
    item():key(0), name(""){}

    void show(){
        cout << "[" << key <<": "<< name <<"]\n";
    }
};

class ArrayHeap{
    int MaxSize;
    item* arr;
    int tail;

    bool empty(){
        return tail == -1;
    }

    bool full(){
        return tail == MaxSize-1;
    }

    void heapify(int i){
        item it = arr[i];
        int left = 2*i+1;
        while(left < len()){
            int large = left + 1 < len() && arr[left+1].key > arr[left].key ?
                left + 1 : left;
            large = arr[large].key > it.key ? large : i;
            if(large == i) break;
            arr[i] = arr[large];
            i = large;
            left = 2*i+1;
        }   
    }

public:
    ArrayHeap(int Max):MaxSize(Max),tail(-1){
        arr = new item[Max];
    }

    int len(){
        return tail+1;
    }
    
    void add(int key, string name){
        if(full()){
            cout << "# full heap!\n";
            return;
        }
        item it(key, name);
        int i = ++tail;
        while(i > 0 && it.key > arr[(i-1)/2].key){
            arr[i] = arr[(i-1)/2];
            i = (i - 1) / 2;
        }
        arr[i] = it;
    }

    void pop(){
        if(empty()){
            cout <<"# empty heap!\n";
            return;
        }
        cout << "# pop out: ";
        arr[0].show();
        arr[0] = arr[tail--];
        heapify(0);
    }

    void show(){
        for(int i = 0; i < len(); ++i){
            arr[i].show();
        }
    }
};