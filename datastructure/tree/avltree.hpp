#include "binaryTree.hpp"

class AvlTree{
    TNode* root;
    int size;

    void destory(TNode* node){
        if(!node) return;
        TNode* lp = node->left;
        TNode* rp = node->right;
        delete node;
        node = nullptr;
        destory(lp);
        destory(rp);
    }   

    TNode* find(TNode* node, int val){
        if(node->val == val) return node;
        else if(node->val < val) return node->left ? find(node->left, val) : nullptr;
        else return node->right ? find(node->right, val) : nullptr;
    }

public:
    AvlTree():root(NULL),size(0){}

    ~AvlTree(){
        destory(root);
    }

    void find(int val){
        TNode* res = find(root, val);
        if(res == nullptr){
            cout << "# not found!\n";
            return;
        }
        cout << "# find node: ";
        res->show();
    }

    
};