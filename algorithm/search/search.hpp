#include <vector>

using namespace std;

int BinarySearch(vector<int> &arr, int flag){
    int L = 0, R = arr.size()-1;
    while(L <= R){
        int mid = (R + L)>>1;
        if(arr[mid] == flag){
            return mid;
        }else if(arr[mid] < flag){
            L = mid+1;
        }else{
            R = mid-1;
        }
    }
    return -1;
}

int BinarySearch(vector<int> &arr, int flag, int L, int R){
    if(L > R) return -1;
    int mid = (R + L)>>1;
    if(arr[mid] == flag) return mid;
    else if(arr[mid] < flag) return BinarySearch(arr, flag, mid+1, R);
    else return BinarySearch(arr, flag, L, mid-1);
}

