#include <deque>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class fNode{
public:
    int val;
    char ch;
    fNode* left;
    fNode* right;
    fNode(int num): val(num), ch(0), left(NULL), right(NULL){}
    fNode(int num, char c): val(num), ch(c), left(NULL), right(NULL){}
};

class Huffman{
    fNode* root;

    void show(fNode* node){
        if(!node) return;
        cout <<" ["<<node->val << ": "<<node->ch<<"]";
        show(node->left);
        show(node->right);
    }

    void getHuffTable(unordered_map<char, string>& huffmanTable, string s, fNode* node){
        if(!node) return;
        if(node->ch == 0){
            getHuffTable(huffmanTable, s+"0", node->left);
            getHuffTable(huffmanTable, s+"1", node->right);
        }else{
            huffmanTable[node->ch] = s;
        }
    }

public:
    Huffman(deque<fNode*> nodes){
        while(nodes.size() > 1){
            sort(nodes.begin(),nodes.end(),[](fNode* n1, fNode* n2){return n1->val < n2->val;});
            fNode* child1 = nodes.front();
            nodes.pop_front();
            fNode* child2 = nodes.front();
            nodes.pop_front();
            fNode* parent = new fNode(child1->val + child2->val);
            parent->left = child1;
            parent->right = child2;
            nodes.push_back(parent);
        }
        root = nodes.front();
    }

    void show(){
        if(!root){
            cout << "# empty tree\n";
            return;
        }
        cout <<"# print tree:\n";
        show(root);
    }

    void getHuffTable(unordered_map<char, string>& huffmanTable){
        getHuffTable(huffmanTable, "", root);
    }
};