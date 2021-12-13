#include <vector>
#include <cmath>

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

int inerpolationSearch(vector<int> &arr, int flag, int L, int R){
    if(L > R || flag < arr[0] || flag > arr.back()) return -1;
    int mid = L + (R - L) * (flag - arr[L]) / (arr[R] - arr[L]);
    if(arr[mid] == flag) return mid;
    else if(arr[mid] < flag) return inerpolationSearch(arr, flag, mid+1, R);
    else return inerpolationSearch(arr, flag, L, mid-1);
}

int Fibnacci(int n){
    double root5 = sqrt(5);
    double A = (1+root5)/2.0;
    double B = (1-root5)/2.0;
    int res = 0.5 + (pow(A, n+1) - pow(B, n+1)) / root5;
    return res;
}

int fibnacciSearch(vector<int> &arr, int flag){
    int L = 0;
    int R = arr.size()-1;
    int k = 0;
    while(R > Fibnacci(k)-1) ++k;
    vector<int> temp(Fibnacci(k));
    for(int i = 0; i < temp.size(); ++i){
        temp[i] = i < R ? arr[i] : arr[R];
    }
    while(L <= R){
        int mid = L + Fibnacci(k-1) - 1;
        if(temp[mid] > flag){
            R = mid - 1;
            --k;
        }else if(temp[mid] < flag){
            L = mid + 1;
            k -= 2;
        }else{
            if(mid < R) return mid;
            else return R;
        }
    }
    return -1;
}
