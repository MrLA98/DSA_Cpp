// 数据结构测试
#include "datastructure/sparsearray/sparseArray.hpp" // 1.1 稀疏数组测试
#include "datastructure/queue/qCustomer.hpp" // 1.2 队列测试
#include "datastructure/linkedlist/listCustomer.hpp" // 1.3 链表测试

// 算法测试案例
#include "algorithm/sort/sortChecker.hpp" // 2.1 排序算法测试

using namespace std;

void sparseTest();
void queueTest();
void listTest();

void sortTest();

int main(){
    // TODO: testfunction
    listTest();
    return 0;
}

// 1.1 稀疏数组测试
void sparseTest(){
    vector<vector<int> > chessArray(12, vector<int>(11));
    // 在矩阵[2,3]和[3,4]处分别有一个黑棋子和一个白棋子
    chessArray[1][2] = 1;
    chessArray[2][3] = 2;
    chessArray[4][5] = 2;
    showChessMap(chessArray);
    Sparse sparseArray(chessArray);
    sparseArray.show();
    vector<vector<int> > recover = sparseArray.recover();
    showChessMap(recover);
}

// 1.2 队列测试
void queueTest(){
    int key = 0;
    cout<<"-------------Menu------------"<<endl;
    cout<<"----0--linear array queue----"<<endl;
    cout<<"----1--circle array queue----"<<endl;
    cout<<"----2---linked list queue----"<<endl;
    cout<<"$ input number[0/1/2] to test:";
    cin >> key;
    qCustomerInterface(key);
}

// 1.3 链表测试
void listTest(){
    int key = 0;
    cout<<"-------------Menu------------"<<endl;
    cout<<"----0--single linked list----"<<endl;
    cout<<"----1--single ordered list---"<<endl;
    cout<<"----2--double linked list----"<<endl;
    cout<<"----3--double ordered list---"<<endl;
    cout<<"$ input number[0/1/2/3] to test:";
    cin >> key;
    lCustomerInterface(key);
}

// 2.1 排序算法测试
void sortTest(){
    char func[] = {'s', 'B', 'b', 'I', 'i', 'L', 'l', 'Q', 'M', 'R', 'H'};
    for(int i = 0; i < 11; ++i){
        sortChecker checker(func[i]);
        // 最大值，数组长度，测试次数
        checker.checkTest(400, 800, 10000);
    }
}