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
        else if(node->val > val) return node->left ? find(node->left, val) : nullptr;
        else return node->right ? find(node->right, val) : nullptr;
    }

    TNode* getRmin(TNode* node){
        TNode* cur = node->right;
        while(cur->left){
            cur = cur->left;
        }
        return cur;
    }

    TNode* getFather(TNode* node, int val){
        if(node->left && node->left->val == val 
            || node->right && node->right->val == val) return node;
        if(node->left && node->val > val) return getFather(node->left, val);
        else if(node ->right && node->val < val) return getFather(node->right, val);
        else return nullptr;
    }

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

    void bfs(){
        deque<TNode*> queue;
        TNode* cur = root;
        queue.push_back(cur);
        while(!queue.empty()){
            cur = queue.front();
            cur->show();
            queue.pop_front();
            if(cur->left) queue.push_back(cur->left);
            if(cur->right) queue.push_back(cur->right);
        }
    }

    int getHight(TNode* node){
        int L = node->left ? getHight(node->left) : 0;
        int R = node->right ? getHight(node->right) : 0;
        return max(L,R) + 1;
    }

    int getLeftH(TNode* node){
        return node->left ? getHight(node->left) : 0;
    }

    int getRightH(TNode* node){
        return node->right ? getHight(node->right) : 0;
    }

    void leftRotate(TNode* node){
        // 新的节点，复制头节点数据
        TNode* newLeft = new TNode(node->val, node->name);
        // 新左=头左，新右=头右左
        newLeft->left = node->left;
        newLeft->right = node->right->left;
        // 临时变量保存即将删除的[头右]节点
        TNode* temp = node->right;
        // 头节点复制[头右]节点的数据
        node->val = temp->val;
        node->name = temp->name;
        // 头左=新，头右=[头右]右
        node->right = temp->right;
        node->left = newLeft;
        delete temp;
    }

    void rightRotate(TNode* node){
        // 新节点，复制头节点的数据
        TNode* newRight = new TNode(node->val, node->name);
        // 新节点右=头节点右，左=头节点左右
        newRight->right = node->right;
        newRight->left = node->left->right;
        // 修改头节点数据
        TNode* temp = node->left;
        node->val = temp->val;
        node->name = temp->name;
        node->left = temp->left;
        node->right = newRight;
        delete temp;
    }

    void selfBalance(){
        int L = getLeftH(root);
        int R = getRightH(root);
        if(L > R && L - R > 1){
            if(getRightH(root->left) > getLeftH(root->left)){
                leftRotate(root->left);
            }
            rightRotate(root);
        }
        else if(R > L && R - L > 1){
            if(getLeftH(root->right) > getRightH(root->right)){
                rightRotate(root->right);
            }
            leftRotate(root);
        }
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

    void show(int key){
        switch (key)
        {
        case 0:
            cout << "# preOrder:\n";
            preOrder(root);
            break;
        case 1:
            cout << "# infixOrder:\n";
            infixOrder(root);
            break;
        case 2:
            cout << "# postOrder:\n";
            postOrder(root);
            break;
        case 3:
            cout << "# bfs:\n";
            bfs();
            break;
        default:
            break;
        }
    }

    void add(int val, string name){
        TNode* cur = root;
        TNode* temp = new TNode(val, name);
        if(root == nullptr){
            root = temp;
            cout << "# new node: ";
            temp->show();
            return;
        }
        while(cur){
            if(cur->val == val){
                cout << "# node has existed!\n";
                cur->show();
                return;
            }else if(cur->val > val){
                if(cur->left){
                    cur = cur->left;
                }else{
                    cur->left = temp;
                    break;
                }
            }else{
                if(cur->right){
                    cur = cur->right;
                }else{
                    cur->right = temp;
                    break;
                }
            }
        }
        selfBalance();
        cout << "# new node: ";
        temp->show();
    }

    void del(int val){
        TNode* target = find(root, val);
        // 1. 没找到
        if(target == nullptr){
            cout << "# not found!\n";
            return;
        }
        // 到这里，说明一定找到了
        cout << "# delete node:\n";
        target->show();
        // 2. 找到了 -- 头节点
        if(target == root){
            // 2.1 头节点且没孩子
            if(root->left == nullptr && root->right){
                delete root;
                root = nullptr;
            }
            // 2.2 头节点有两个孩子
            else if(root->left && root->right){
                TNode* temp = getRmin(root);
                int data = temp->val;
                root->name = temp->name;
                del(temp->val);
                root->val = data;
            }
            // 2.3 头节点有一个孩子
            else{
                root = root->left ? root->left : root->right;
                delete target;
            }
            return;
        }
        // 3. 找到了 -- 叶子节点
        if(target->left == nullptr && target->right == nullptr){
            // 找父亲 -- 父亲一定不是null
            TNode* father = getFather(root, val);
            // 不是左就是右
            if(father->left && father->left == target){ // 是父亲的左孩子
                father->left = nullptr;
            }else{ // 是父亲的右孩子
                father->right = nullptr;
            }
            delete target;
        }
        // 4. 找到了 -- 有两个孩子
        else if(target->left && target->right){
            TNode* temp = getRmin(target);
            int data = temp->val;
            target->name = temp->name;
            del(temp->val);
            target->val = data;
        }
        // 5. 找到了 -- 有一个孩子
        else{
            TNode* father = getFather(root, val);
            if(father->left && father->left == target){
                if(target->left){
                    father->left = target->left;
                }else{
                    father->left = target->right;
                }
            }else{
                if(target->left){
                    father->right = target->left;
                }else{
                    father->right = target->right;
                }
            }
            delete target;
        }
    }

    void change(int val, string name){
        TNode* target = find(root, val);
        if(target == nullptr){
            cout << "# not found!\n";
            return;
        }
        target->name = name;
        cout << "# succeed to change :\n";
        target->show();
    }
};