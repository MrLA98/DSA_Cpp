#include <vector>
#include <cmath>
#include <climits>
using namespace std;

// 选择排序
class Selection{
public:
    // 每轮找最小的，记录下标，然后交换
    static void Sort(vector<int>& arr){
        // 第零位一直到倒数第二位
        for(int i = 0; i < arr.size()-1; ++i){
            int min = i; // 记录本轮最小的下标
            for(int j = i; j < arr.size(); ++j){
                min = arr[j] < arr[min] ? j : min;
            }
            swap(arr[i], arr[min]);
        }
    }
};

// 冒泡排序
class Bubble{
public:
    // 原版冒泡
    static void Sort(vector<int>& arr){
        for(int i = arr.size()-1; i > 0; --i){
            for(int j = 0; j < i; ++j){
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]);
                }
            }
        }
    }

    // 优化冒泡
    static void Sort2(vector<int>& arr){
        for(int i = arr.size()-1; i > 0; --i){
            bool flag = false;
            for(int j = 0; j < i; ++j){
                if(arr[j] > arr[j+1]){
                    swap(arr[j], arr[j+1]);
                    flag = true;
                }
            }
            if(!flag) break;
        }
    } 
};


// 插入排序
class Insertion{
public:
    // 基于交换的
    static void Sort(vector<int>& arr){
        // 从第一个开始取往前插入的数字
        for (int i = 1; i < arr.size(); ++i){
            // 和前一位比较，小就交换
            for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j){
                swap(arr[j], arr[j - 1]);
            }
        }
    }

    // 基于移动的
    static void Sort2(vector<int>& arr){
        for(int i = 1; i < arr.size(); ++i){
            int temp = arr[i], j = i;
            for(; j > 0 && temp < arr[j-1]; --j){
                arr[j] = arr[j-1];
            }
            arr[j] = temp;
        }
    }
};

class Shell{
public:
    // 基于交换
    static void Sort(vector<int>& arr){
        for(int gap = arr.size()/2; gap > 0; gap /= 2){
            for(int i = gap; i < arr.size(); ++i){
                for(int j = i; j >= gap && arr[j] < arr[j-gap]; j -= gap){
                    swap(arr[j], arr[j-gap]);
                }
            }
        }
    }

    // 基于移动
    static void Sort2(vector<int>& arr){
        for(int gap = arr.size()/2; gap > 0; gap /= 2){
            for(int i = gap; i < arr.size(); ++i){
                int temp = arr[i], j = i;
                for(; j >= gap && temp < arr[j-gap]; j -= gap){
                    arr[j] = arr[j-gap];
                }
                arr[j] = temp;
            }
        }
    }
};

class Quick{
public:
    static void Sort(vector<int>& arr){
        divide(arr, 0, arr.size()-1);
    }
private:
    static void divide(vector<int>& arr, int left, int right){
        if(left >= right) return;
        int p = (rand()%(right-left+1))+left;
        swap(arr[right], arr[p]);
        vector<int> mid(2);
        mid = partition(arr, left, right);
        divide(arr, left, mid[0]-1);
        divide(arr, mid[1]+1, right);
    }
    static vector<int> partition(vector<int>& arr, int left, int right){
        int less = left-1;
        int more = right;
        while(left < more){
            if(arr[left] < arr[right]){
                swap(arr[++less], arr[left++]);
            }else if(arr[left] > arr[right]){
                swap(arr[left], arr[--more]);
            }else ++left;
        }
        swap(arr[right],arr[more]);
        return {less+1, more};
    }
};

class Merge{
public:
    static void Sort(vector<int>& arr){
        divide(arr, 0, arr.size()-1);
    }
private:
    static void divide(vector<int>& arr, int left, int right){
        if(left == right) return;
        int mid = (right + left)>>1;
        divide(arr, left, mid);
        divide(arr, mid+1, right);
        merge(arr, left, mid+1, right);
    }
    static void merge(vector<int>& arr, int left, int right, int end){
        vector<int> help(end-left+1);
        int i = left;
        int j = right;
        int k = 0;
        while(i < right && j <= end){
            help[k++] = arr[i] < arr[j] ? arr[i++] : arr[j++];
        }
        while(i < right) help[k++] = arr[i++];
        while(j <= end) help[k++] = arr[j++];
        for(int m = 0; m < help.size(); ++m){
            arr[left+m] = help[m];
        }
    }
};

class Radix{
public:
    static void Sort(vector<int>& arr){
        int Digits = maxDigits(getMax(arr));
        for(int d = 0; d < Digits; ++d){
            int bucket[10] = {};
            vector<int> copy(arr.size());
            for(auto it : arr){
                ++bucket[getDigit(it,d)];
            }
            for(int i = 1; i < 10; ++i){
                bucket[i] += bucket[i-1];
            }
            for(int j = arr.size()-1; j >=0; --j){
                copy[--bucket[getDigit(arr[j],d)]] = arr[j];
            }
            arr = copy;
        }
    }
private:
    static int getMax(vector<int>& arr){
        int max = INT_MIN;
        for(auto it : arr){
            max = it > max ? it : max;
        }
        return max;
    }
    static int maxDigits(int num){
        int count = 0;
        while(num > 0){
            count++;
            num /= 10;
        }
        return count;
    }
    static int getDigit(int num, int i){
        return (num / (int)pow(10,i)) % 10;
    }
};

class Heap{
public:
    static void Sort(vector<int>& arr){
        int len = arr.size();
        for(int i = len / 2 - 1; i >= 0; --i){
            heapify(arr, i, len);
        }
        swap(arr[0], arr[--len]);
        while(len > 1){
            heapify(arr, 0, len);
            swap(arr[0], arr[--len]);
        }
        
    }
private:
    static void heapify(vector<int>& arr, int index, int maxSize){
        int left = 2 * index + 1;
        int temp = arr[index];
        while(left < maxSize){
            int large = left + 1 < maxSize && arr[left+1] > arr[left] ?
                left + 1 : left;
            large = arr[large] > temp ? large : index;
            if(large == index) break;
            arr[index] = arr[large];
            index = large;
            left = 2 * index + 1; 
        }
        arr[index] = temp;
    }
};
