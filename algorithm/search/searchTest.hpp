#include "search.hpp"
#include <iostream>
#include <ctime>

void searchTestCustomer(){
    cout << "$ input a number :";
    int len = 100;
    cin >> len;
    cout << "$ input a number(<=" << len <<"):";
    int index = 60;
    cin >> index;

    vector<int> arr(len);
    srand(time(NULL));
    for(int i = 0; i < len; ++i){
        arr[i] = (rand() % (2*len+1)) - len;
    }
    sort(arr.begin(), arr.end());
    cout <<endl;
    clock_t t0 = clock();
    cout <<"[BinarySearch - non_recursion]: " << BinarySearch(arr, arr[index]) << endl;
    clock_t t1 = clock();
    cout << "# spent " << (t1 - t0)/CLOCKS_PER_SEC << " seconds\n";
    cout <<"[BinarySearch - recursion]: " << BinarySearch(arr, arr[index], 0, arr.size()-1) << endl;
    clock_t t2 = clock();
    cout << "# spent " << (t2 - t1)/CLOCKS_PER_SEC << " seconds\n";
    cout <<"[InerpolationSearch]: " << inerpolationSearch(arr, arr[index], 0, arr.size()-1) << endl;
    clock_t t3 = clock();
    cout << "# spent " << (t3 - t2)/CLOCKS_PER_SEC << " seconds\n";
    cout <<"[FibonacciSearch]: " << fibnacciSearch(arr, arr[index]) << endl;
    clock_t t4 = clock();
    cout << "# spent " << (t4 - t3)/CLOCKS_PER_SEC << " seconds\n";
}