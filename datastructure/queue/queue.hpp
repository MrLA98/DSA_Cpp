#include <iostream>
using namespace std;

class QueueF{
public: 
    virtual void push(int val) = 0;
    virtual int pop() = 0;
    virtual int length() = 0;
    virtual void show() = 0;
};

// 数组队列 -- 一次性的
class QueueArray : public QueueF{
public:
    // 构造器
    QueueArray(int maxSize){
        this->maxSize = maxSize;
        arr = new int[maxSize];
        rear = front = -1;
    }

    // 析构器
    ~QueueArray(){
        delete[] arr;
    }

    // 加入
    void push(int val){
        if(isFull()){
            cout << "# full queue"<<endl;
            return;
        }
        arr[++rear] = val;
    }
    
    // 弹出
    int pop(){
        if(isEmpty()){
            throw runtime_error("# empty queue!");
        }
        return arr[++front];
    }

    // 长度
    int length(){
        return rear - front;
    }

    // 打印队列
    void show(){
        for(int i = front + 1; i <= rear; ++i){
            cout << arr[i] << "\t";
        }
        cout << endl;
    }

private:
    int maxSize; // 数组尺寸
    int *arr; // 维护一个数组
    int rear; // 尾部位置
    int front; // 头部的前一个位置

    bool isFull(){
        return rear == maxSize-1;
    }

    bool isEmpty(){
        return rear == front;
    }
};

// 循环数组队列
class QueueCircle : public QueueF{
public:
    // 构造器
    QueueCircle(int maxSize){
        this->maxSize = maxSize;
        arr = new int[maxSize];
        front = rear = 0;
    }

    // 析构
    ~QueueCircle(){
        delete[] arr;
    }

    // 元素个数
    int length(){
        return (rear + maxSize - front) % maxSize;
    }

    // 添加
    void push(int val){
        if(isFull()){
            cout<<"# full queue"<<endl;
            return;
        }
        arr[rear] = val;
        rear = (rear + 1) % maxSize;
    }

    // 弹出
    int pop(){
        if(isEmpty()){
            throw runtime_error("# empty queue");
        }
        int val = arr[front];
        front = (front + 1) % maxSize;
        return val;
    }

    void show(){
        cout << "[ ";
        for(int i = front; i < front + length(); ++i){
            cout << arr[i%maxSize] << " ";
        }
        cout << ']' << endl;
    }

private:
    int* arr; // 管理一个数组
    int maxSize; // 数组大小
    int front; // 队列头部
    int rear; // 队列尾部的后一个位置

    bool isFull(){
        return (rear + 1) % maxSize == front;
    }

    bool isEmpty(){
        return rear == front;
    }
};

// 节点
class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }

    Node(Node &node){
        data = node.data;
        next = node.next;
    }
};

// 链表队列
class QueueList : public QueueF{
public:
    // 构造器
    QueueList(){
        head = new Node(0);
        tail = head;
        len = 0;
    }

    // 析构 -- 从头节点开始，依次删除
    ~QueueList(){
        Node* temp; // 临时指针
        while(head->next != nullptr){
            temp = head->next; // 保存下一个
            delete head; // 删除头
            head = temp; // 头等于下一个
        }
        delete head; // 删除头
    }

    // 添加
    void push(int val){
        tail->next = new Node(val); // 尾部哨兵直连下一个
        tail = tail->next; // 尾部哨兵保持为最后一个有效位置
        len++;
    }

    // 删除
    int pop(){
        if(isEmpty()){
            throw runtime_error("# empty queue");
        }
        Node* temp = head->next; // 保存头的下一个
        int val = temp->data; // 保存这个值
        head->next = temp->next; // 跨过节点
        if(tail == temp) // 如果该节点是尾部哨兵，说明删完了
            tail = head; // 尾部哨兵回到头节点
        delete temp; // 在内存中删除该节点内存
        --len;
        return val;
    }

    void show(){
        Node* cur = head->next;
        cout<<"{ ";
        while(cur != nullptr){
            cout << cur->data<<" ";
            cur = cur->next;
        }
        cout<<"}"<<endl;
    }

    int length(){
        return len;
    }

private:
    Node* head; // 头节点 -- 不保存数据
    Node* tail; // 尾部哨兵
    int len;

    bool isEmpty(){
        return head->next == nullptr;
    }
};