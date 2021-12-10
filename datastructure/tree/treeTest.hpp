#include "binaryTree.hpp"
#include "arrayHeap.hpp"

void binaryTreeTest(){
    TNode* node1 = new TNode(2, "lh");
    TNode* node2 = new TNode(4, "phk");
    TNode* node3 = new TNode(1, "tyr");
    TNode* node4 = new TNode(3, "yzsz");
    TNode* node5 = new TNode(6, "xky");
    TNode* node6 = new TNode(7, "xy");
    TNode* node7 = new TNode(5, "chx");

    node1->left = node2;
    node2->right = node4;
    node1->right = node6;
    node6->left = node7;
    node2->left = node5;
    node6->right = node3;

    BinaryTree* bt = new BinaryTree(node1);
    bt->show(0);
    bt->show(1);
    bt->show(2);

    bt->search(1);
    bt->del(7);
    bt->show(1);
}

void heapMenu(){
    cout << "# input maxsize: ";
    int maxSize = 0;
    cin >> maxSize;
    ArrayHeap heap(maxSize);
    while(1){
        cout<<endl;
        cout<<"-------------Menu-------------"<<endl;
        cout<<"----a(add)----add an item-----"<<endl;
        cout<<"----p(pop)----pop an item-----"<<endl;
        cout<<"----l(len)---length of heap---"<<endl;
        cout<<"----s(show)---show the heap---"<<endl;
        cout<<"----e(exit)---exit program----"<<endl;
        cout<<"$ input a char to choose:";
        char ch = ' ';
        cin >> ch;
        switch (ch){
            case 'a':{
                cout << "$ input the number: ";
                int num = 0;
                cin >> num;
                cout << "$ input the name: ";
                string name;
                cin >> name;
                heap.add(num, name);
                break;
            }
            case 'p':
                heap.pop();
                break;
            case 'l':
                cout << "# len of heap : "<<heap.len()<<endl;
                break;
            case 's':
                heap.show();
                break;
            case 'e':
                return;
            default:
                break;
        }
    }
}

void tCustomerInterface(int key){
    if(key == 0){
        cout << "[binary tree] -- test:\n";
        binaryTreeTest();
        return;
    }
    if(key == 1){
        cout << "[array heap] -- test:\n";
        heapMenu();
    }
}