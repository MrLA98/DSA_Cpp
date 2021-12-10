#include <iostream>
#include <string>
#include <deque>

using namespace std;

// 树节点 -- 所有树的代码都用它了
class TNode{
public:
    int val;
    string name;
    TNode* left;
    TNode* right;

    TNode(int val, string name){
        this->val = val;
        this->name = name;
        left = right = nullptr;
    }

    void show(){
        cout << "["<<val<<": "<<name<<"]"<<endl;
    }
};

// 二叉树
class BinaryTree{
    TNode* root;

    void preOrder(TNode* node){
        if(!node) return;
        node->show();
        preOrder(node->left);
        preOrder(node->right);
    }

    void infixOrder(TNode* node){
        if(!node) return;
        infixOrder(node->left);
        node->show();
        infixOrder(node->right);
    }

    void postOrder(TNode* node){
        if(!node) return;
        postOrder(node->left);
        postOrder(node->right);
        node->show();
    }

    TNode* search(TNode* node, int key){
        if(node->val == key) return node;
        TNode* temp = nullptr; // 
        if(node->left != nullptr){
            temp = search(node->left, key);
        }
        if(temp == nullptr && node->right != nullptr){
            temp = search(node->right, key);
        }
        return temp;
    }

public:
    BinaryTree(TNode* root){
        this->root = root;
    }

    TNode* getRoot(){
        return root;
    }

    void show(int key){
        cout<<"# print the tree -- ";
        if(key == 0){
            cout <<" [preOrder]:\n";
            preOrder(root);
        }else if(key == 1){
            cout <<" [infixOrder]:\n";
            infixOrder(root);
        }else{
            cout <<" [postOrder]:\n";
            postOrder(root);
        }
    }

    // 前序查找
    TNode* search(int key){
        TNode *res = search(root, key);
        cout << "# finding...\n";
        if(res == nullptr){
            throw runtime_error("# not found!");
        }
        cout <<"# found node :";
        res->show();
        return res;
    }

    void del(int key){
        deque<TNode*> bfs;
        TNode* cur = root;
        bfs.push_back(cur);
        while(!bfs.empty()){
            cur = bfs.front();
            bfs.pop_front();
            if(cur->left) {
                if(cur->left->val == key){
                    TNode* temp = cur->left;
                    cout << "# delete node :";
                    temp->show();
                    cur->left = nullptr;
                    destroy(temp);
                    return;
                }
                bfs.push_back(cur->left);
            }
            if(cur->right) {
                if(cur->right->val == key){
                    TNode* temp = cur->right;
                    cout << "# delete node :";
                    temp->show();
                    cur->right = nullptr;
                    destroy(temp);
                    return;
                }
                bfs.push_back(cur->right);
            }
        }
        cout << "# not found!\n";
    }

    void destroy(TNode* node){
        if(!node) return;
        TNode* lp = node->left;
        TNode* rp = node->right;
        delete node;
        node = nullptr;
        destroy(lp);
        destroy(rp);
    }

    ~BinaryTree(){
        destroy(root);
    }
};

