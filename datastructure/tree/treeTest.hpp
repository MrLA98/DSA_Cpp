#include "arrayHeap.hpp"
#include "avltree.hpp"
#include "huffmanTree.hpp"

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

void avlTreeMenu(){
    AvlTree avlTree;
    while(1){
        cout<<endl;
        cout<<"---------------Menu-------------"<<endl;
        cout<<"----a(add)------add an item-----"<<endl;
        cout<<"----d(del)------delete an item---"<<endl;
        cout<<"----c(change)---change an item---"<<endl;
        cout<<"----s(show)-----show the tree----"<<endl;
        cout<<"----e(exit)-----exit program-----"<<endl;
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
                avlTree.add(num, name);
                break;
            }
            case 'd':{
                cout << "$ input the number: ";
                int num = 0;
                cin >> num;
                avlTree.del(num);
                break;
            }
            case 'c':{
                cout << "$ input the number: ";
                int num = 0;
                cin >> num;
                cout << "$ input the name: ";
                string name;
                cin >> name;
                avlTree.change(num, name);
                break;
            }
            case 's':{
                cout<<endl;
                cout <<"--0--preOrder----\n";
                cout <<"--1--infixOrder--\n";
                cout <<"--2--postOrder---\n";
                cout <<"--3--dfs---------\n";
                cout << "$ input key[0/1/2/3]: ";
                int key = 0;
                cin >> key;
                avlTree.show(key);
                break;
            }
            case 'e':
                return;
            default:
                break;
        }
    }
}

// 字符串转词频数组
deque<fNode*> countWords(string s){
    unordered_map<char,int> bucket;
    for(auto ch : s){
        ++bucket[ch];
    }
    deque<fNode*> res;
    for(auto it : bucket){
        res.push_back(new fNode(it.second, it.first));
    }
    return res;
}

string huffmanZip(string s, unordered_map<char, string> hufftable){
    string res;
    for(auto ch : s){
        res += hufftable[ch];
    }
    return res;
}

string decode(string zipCode, unordered_map<char, string> hufftable){
    unordered_map<string, char> revHufftable;
    int max = 0;
    for(auto it : hufftable){
        revHufftable[it.second] = it.first;
        max = it.second.size() > max ? it.second.size() : max;
    }
    int i = 0, j = 1;
    string origin;
    while(i + j <= zipCode.size()){
        string key = zipCode.substr(i,j);
        if(revHufftable.find(key) != revHufftable.end()){
            origin += revHufftable[key];
            i += j;
            j = 1;
        }else if(j < max){
            ++j;
        }else{
            ++i;
            j = 1;
        }
    }
    return origin;
}

void huffmanTreeTest(){
    while(1){
        string s;
        cout <<"$ input any sentences:\n";
        cin >> s;
        deque<fNode*> countW = countWords(s);
        Huffman hTree(countW);
        unordered_map<char, string> huffmanTable;
        hTree.getHuffTable(huffmanTable);
        string zipCode = huffmanZip(s, huffmanTable);
        cout <<"# huffman zip code :\n ["<<zipCode<<"]\n";
        cout <<"# revocer sentence:\n";
        cout <<" [" << decode(zipCode,huffmanTable) << "]\n";

        cout << "$ stop? [y/n] :";
        char stop = 'y';
        cin >> stop;
        if(stop == 'y') return;
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
        return;
    }
    if(key == 2){
        cout << "[AVL tree] -- test:\n";
        avlTreeMenu();
        return;
    }
    if(key == 3){
        cout << "[Huffman tree] -- test\n";
        huffmanTreeTest();
    }
}