#include <iostream>
#include <string>

using namespace std;

// 节点
class HNode{
public:
    int key;
    string name;
    int age;
    HNode* next;

    HNode(int key, string name, int age){
        this->key = key;
        this->name = name;
        this->age = age;
        next = nullptr;
    }

    void show(){
        cout << "[key:" << key << ", " << name <<", age="<<age<<"]";
    }
};

// 链表
class Hlist{
public:
    HNode* head;
    int length;

    Hlist(){
        head = new HNode(0, "", 0);
        length = 0;
    }

    bool isEmpty(){
        return head->next == nullptr;
    }

    void show(){
        HNode* cur = head->next;
        while(cur){
            cur->show();
            cout<<"->";
            cur = cur->next; 
        }
    }

    void add(int val, string name, int age){
        HNode* cur = head;
        while(1){
            if(cur->next == nullptr || cur->next->key > val){
                HNode* node = new HNode(val, name, age);
                node->next = cur->next;
                cur->next = node;
                cout<<"# new node: ";
                node->show();
                cout << endl;
                ++length;
                return;
            }else if(cur->next->key == val){
                cout<<"# node has exited: ";
                cur->next->show();
                cout << endl;
                return;
            }
            cur = cur->next;
        }
    }

    void del(int val){
        HNode* cur = head;
        while(cur->next){
            if(cur->next->key == val){
                HNode* temp = cur->next;
                cur->next = temp->next;
                cout<<"# delete node: ";
                temp->show();
                cout << endl;
                delete temp;
                --length;
                return;
            }else if(cur->next->key > val) break;
        }
        cout << "# not found\n";
    }

    HNode* find(int val){
        HNode* cur = head->next;
        while(cur){
            if(cur->key == val){
                return cur;
            }else if(cur->key > val) break;
        }
        return nullptr;
    }

    ~Hlist(){
        HNode* temp;
        while(head){
            temp = head->next;
            delete head;
            head = temp;
        }
        delete head;
    }
};

// 哈希表
class HashList{
    int Hash; // 数组长度
    Hlist** arr;

public:
    HashList(int Size){
        Hash = Size;
        arr = new Hlist*[Hash];
        for(int i = 0; i < Hash; ++i){
            arr[i] = new Hlist();
        }
    }

    Hlist* HashFunc(int val){
        return arr[val % Hash];
    }

    void add(int val, string name, int age){
        Hlist* list = HashFunc(val);
        list->add(val, name, age);
    }

    void del(int val){
        Hlist* list = HashFunc(val);
        list->del(val);
    }

    HNode* find(int val){
        Hlist* list = HashFunc(val);
        return list->find(val);
    }

    void change(int val, string name, int age){
        HNode* target = find(val);
        if(target == nullptr){
            cout << "# failed to change node\n";
            return;
        }
        target->name = name;
        target->age = age;
        cout << "# succeed to change node: ";
        target->show();
        cout<<endl;
    }

    void show(){
        cout << "# print HashTable: \n";
        for(int i = 0; i < Hash; ++i){
            cout <<" [list-"<<i<<"]->";
            arr[i]->show();
            cout << endl;
        }
    }
};
