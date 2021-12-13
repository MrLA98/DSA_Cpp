#include "search.hpp"
#include <iostream>

void searchTestCustomer(){
    vector<int> arr(100);
    for(int i = 0; i < 100; ++i){
        arr[i] = (rand() % 201) - 100;
    }
    sort(arr.begin(), arr.end());
    cout << BinarySearch(arr, arr[35]) << endl;
    cout << BinarySearch(arr, arr[35], 0, arr.size()-1) << endl;
}