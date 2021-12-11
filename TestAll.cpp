// 数据结构测试
#include "datastructure/sparsearray/sparseArray.hpp" // 1.1 稀疏数组测试
#include "datastructure/queue/qCustomer.hpp" // 1.2 队列测试
#include "datastructure/linkedlist/listCustomer.hpp" // 1.3 链表测试
#include "datastructure/stack/stackCustomer.hpp" // 1.4 栈测试
#include "datastructure/hash/hashCustomer.hpp" // 1.5 哈希表测试
#include "datastructure/tree/treeTest.hpp" // 1.6 树测试
#include "datastructure/graph/graphTest.hpp" // 1.7 图测试

// 算法测试案例
#include "algorithm/sort/sortChecker.hpp" // 2.1 排序算法测试
#include "algorithm/recursion/NQueens.hpp" // 2.3.1 N皇后算法
#include "algorithm/special/kmp/kmp.hpp" // 2.5.1 kmp算法
#include "algorithm/special/divideconquer/hannoiTower.hpp" // 2.5.2 汉诺塔

using namespace std;

void sparseTest();
void queueTest();
void listTest();
void stackTest();
void hashTest();
void treeTest();
void graphTest();

void sortTest();
void NQueensTest();
void kmpTest();
void hannoiTowerTest();

int main(){
    // TODO: testfunction
    graphTest();
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
    cout<<"----4--list function test----"<<endl;
    cout<<"----5--Joseph problem test---"<<endl;
    cout<<"$ input number[0/1/2/3/4/5] to test: ";
    cin >> key;
    lCustomerInterface(key);
}

// 1.4 队列测试
void stackTest(){
    int key = 0;
    cout<<"-------------Menu------------"<<endl;
    cout<<"----0---linear array stack---"<<endl;
    cout<<"----1---linked list stack----"<<endl;
    cout<<"----2---stack calculator-----"<<endl;
    cout<<"$ input number[0/1/2] to test:";
    cin >> key;
    sCustomerInterface(key);
}

// 1.5 哈希表测试
void hashTest(){
    hCustomerInterface();
}

// 1.6 树测试
void treeTest(){
    int key = 0;
    cout<<"-------------Menu------------"<<endl;
    cout<<"----0------binary tree-------"<<endl;
    cout<<"----1------array heap--------"<<endl;
    cout<<"----2-------AVL tree---------"<<endl;
    cout<<"----3-----Huffman tree-------"<<endl;
    cout<<"$ input number[0/1/2/3] to test: ";
    cin >> key;
    tCustomerInterface(key);
}

// 1.7 图测试
void graphTest(){
    GraphInterface();
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

// 2.5.1 kmp算法测试
void kmpTest(){
    string sentence, word;
    cout << "$ input a sentence :\n";
    cin >> sentence;
    cout << "$ input a word you want to find :\n";
    cin >> word;
    cout << "finding...\n";
    int pos = kmpFind(sentence, word);
    if(pos == -1){
        cout <<"# not found!\n";
        return;
    }
    cout << "# find in position [" << pos <<"]:\n";
    cout <<"[" << sentence <<"]\n";
    cout <<"["<<string(pos,'_')<<word<<string(sentence.size()-word.size()-pos,'_')<<"]\n";
}

// 2.5.2 汉诺塔算法测试
void hannoiTowerTest(){
    cout << "$ input number of HanniTower: ";
    int num;
    cin >> num;
    cout << "# here is the solution:\n";
    hannoiTowerSolution(num, 'L', 'M', 'R');
}

// 2.3.1 N皇后测试
void NQueensTest(){
    cout << "$ input number of Queens: ";
    int num;
    cin >> num;
    cout << "# here are the solutions:\n";
    NQueensSolution(num);
}

