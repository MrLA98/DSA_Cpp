#include <iostream>

using namespace std;

class StackF{
public:
    virtual void push(int val) = 0;
    virtual int pop() = 0;
    virtual int peek() = 0;
    virtual int size() = 0;
    virtual void show() = 0;
};

// 数组栈
class ArrayStack : public StackF{
    int top; // 顶端位置
    int maxSize;
    int *arr;

    bool isEmpty(){
        return top == 0;
    }

    bool isFull(){
        return top == maxSize-1;
    }

public:
    ArrayStack(int maxSize){
        this->maxSize = maxSize;
        arr = new int[maxSize];
        top = -1;
    }

    void push(int val){
        if(isFull()){
            cout << "# full stack!\n";
            return;
        }
        arr[++top] = val;
    }

    int pop(){
        if(isEmpty()){
            throw runtime_error("# empty stack!");
        }
        return arr[top--];
    }

    int peek(){
        if(isEmpty()){
            throw runtime_error("# empty stack!");
        }
        return arr[top];
    }

    void show(){
        cout <<"[ ";
        for(int i = top; i >= 0; --i){
            cout<<arr[i]<<" ";
        }
        cout<<"]\n";
    }

    int size(){
        return top+1;
    }

    ~ArrayStack(){
        delete[] arr;
    }
};

// 链表节点
class SNode{
public:
    int val;
    SNode* next;

    SNode(int val){
        this->val = val;
        next = nullptr;
    }
};

// 链表栈
class ListStack : public StackF{
    SNode *head;
    int length;
    
    bool isEmpty(){
        return head->next == nullptr;
    }

public:
    ListStack(){
        head = new SNode(0);
        length = 0;
    }

    void push(int val){
        SNode *newNode = new SNode(val);
        newNode->next = head->next;
        head->next = newNode;
        ++length;
    }

    int pop(){
        if(isEmpty()){
            throw runtime_error("# empty stack!");
        }
        SNode *temp = head->next;
        int val = temp->val;
        head->next = temp->next;
        delete temp;
        --length;
        return val;
    }

    int peek(){
        if(isEmpty()){
            throw runtime_error("# empty stack!");
        }
        return head->next->val;
    }

    int size(){
        return length;
    }

    void show(){
        SNode *cur = head->next;
        cout<<"[ ";
        while(cur){
            cout << cur->val<<" ";
            cur = cur->next;
        }
        cout <<"]\n";
    }

    ~ListStack(){
        SNode* temp;
        while(head){
            temp = head->next;
            delete head;
            head = temp;
        }
        delete head;
    }
};