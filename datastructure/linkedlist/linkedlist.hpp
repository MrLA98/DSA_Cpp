#include <string>
#include <iostream>
using namespace std;

// 节点父类
class NodeF{
public:
    int num;
    string name;
    int money;

    void show(){
        cout <<"# Node:[num-"<<num<<", "<<name<<", money="<<money<<"]\n";
    }
};

// 单链表节点
class SingleNode : public NodeF{
public:
    SingleNode* next;

    SingleNode(int num, string name, int money){
        this->num = num;
        this->name = name;
        this->money = money;
        next = nullptr;
    }
};

// 双链表节点
class DoubleNode : public NodeF{
public:
    DoubleNode* next;
    DoubleNode* pre;

    DoubleNode(int num, string name, int money){
        this->num = num;
        this->name = name;
        this->money = money;
        next = nullptr;
        pre = nullptr;
    }
};

// 链表父类
class ListF{
public:
    virtual void add(int num, string name, int money) = 0;
    virtual NodeF* find(int key) = 0;
    virtual void del(int key) = 0;
    virtual int len() = 0;
    virtual void show() = 0;
    virtual ~ListF() = 0;
};
ListF::~ListF(){}

// 单链表
class SingleListF : public ListF{
protected:
    // 两个变量
    SingleNode* head; // 头节点
    int length; // 链表长度

    // 是否为空
    bool isEmpty(){
        return head->next == nullptr;
    }

public:
    // 两个接口
    virtual void add(int num, string name, int money) = 0;
    virtual void del(int key) = 0;

    // 构造器
    SingleListF(){
        head = new SingleNode(0,"",0);
        length = 0;
    }

    // 链表长度
    int len(){
        return length;
    }
    
    // 打印链表
    void show(){
        if(isEmpty()){
            cout << "# empty list!"<<endl;
            return;
        }
        SingleNode* cur = head->next;
        cout << "# show the list:\n";
        while(cur != nullptr){
            cur->show();
            cur = cur->next;
        }
    }

    // 查找节点
    NodeF* find(int key){
        SingleNode* cur = head->next;
        while(cur != nullptr){
            if(cur->num == key){
                return cur;
            }
            cur = cur->next;
        }
        throw runtime_error("# not found!");
    }
        
    // 析构 -- 从头节点开始，依次删除
    ~SingleListF(){
        SingleNode* temp; // 临时指针
        while(head->next != nullptr){
            temp = head->next; // 保存下一个
            delete head; // 删除头
            head = temp; // 头等于下一个
        }
        delete head; // 删除头
    }
};

// 单链表 -- 正常添加
class SingleLinkedList : public SingleListF{
    SingleNode* tail; // 尾部哨兵
public:
    // 构造器
    SingleLinkedList(){
        tail = head;
    }

    // 尾部加节点
    void add(int num, string name, int money){
        tail->next = new SingleNode(num, name, money);
        tail = tail->next;
        // 展示新节点
        cout << "new node :\n";
        tail->show();
        ++length;
    }

    // 删除节点
    void del(int key){
        if(isEmpty()){
            cout<< "# empty list!"<<endl;
            return;
        }
        SingleNode* cur = head;
        while(cur->next != nullptr){
            if(cur->next->num == key){
                // 临时指针，为了delete
                SingleNode* temp = cur->next;
                // 跨过要删除的节点，逻辑删除
                cur->next = temp->next;
                // 删除的如果是尾部节点，更新尾部哨兵
                if(temp == tail) tail = cur;
                // 输出信息
                cout << "# delete Node:\n";
                temp->show();
                // 内存层面删除节点
                delete temp;
                // 长度-1
                --length;
                return; // 不再删除
            }
            // 向后移动
            cur = cur->next;
        }
        // 退出循环说明没有找到
        cout<<"# not fount!"<<endl;
    }
};

// 单链表 -- 顺序添加
class SingleOrderedList : public SingleListF{
public:
    // 按编号加节点
    void add(int num, string name, int money){
        SingleNode* cur = head;
        while(1){
            // 下一个是空，说明新节点的值比已有的都大，添加到尾部
            // 下一个比新节点大，那就说明找到了插入位置
            if(cur->next == nullptr || cur->next->num > num){
                // 新节点
                SingleNode* node = new SingleNode(num, name, money);
                // 新节点连下一个，当前节点下一个是新节点
                node->next = cur->next;
                cur->next = node;
                // 长度+1
                ++length;
                // 展示新节点
                cout << "# new node :\n";
                node->show();
                // 直接退出
                return;
            }else if(cur->next->num == num){
                // 已经存在编号相同的节点了
                cout << "# the node has existed:";
                // 展示相同编号的节点
                cur->next->show();
                return;
            }
            // 往后走
            cur = cur->next;
        }
    }

    // 删除节点
    void del(int key){
        if(isEmpty()){
            cout<< "# empty list!"<<endl;
            return;
        }
        SingleNode* cur = head;
        while(cur->next != nullptr){
            if(cur->next->num == key){
                // 临时指针，为了delete
                SingleNode* temp = cur->next;
                // 跨过要删除的节点，逻辑删除
                cur->next = temp->next;
                // 输出信息
                cout << "# delete Node:\n";
                temp->show();
                // 内存层面删除节点
                delete temp;
                // 长度-1
                --length;
                return; // 不再删除
            }else if(cur->next->num > key) break;
            // 向后移动
            cur = cur->next;
        }
        // 退出循环说明没有找到
        cout<<"# not fount!"<<endl;
    }
};

// 双链表
class DoubleListF : public ListF{
protected:
    DoubleNode* head;
    int length;

    bool isEmpty(){
        return head->next == nullptr;
    }
    
public:
    // 构造器
    DoubleListF(){
        head = new DoubleNode(0, "", 0);
        length = 0;
    }

    // 析构
    ~DoubleListF(){
        DoubleNode* temp;
        while(head->next != nullptr){
            temp = head->next; // 保存下一个
            delete head; // 删除头
            head = temp; // 头等于下一个
        }
        delete head; // 删除头
    }

    // 打印
    void show(){
        if(isEmpty()){
            cout << "# empty list!"<<endl;
            return;
        }
        DoubleNode* cur = head->next;
        cout << "# show the list:\n";
        while(cur != nullptr){
            cur->show();
            cur = cur->next;
        }
    }

    // 查找节点
    NodeF* find(int key){
        DoubleNode* cur = head->next;
        while(cur != nullptr){
            if(cur->num == key){
                return cur;
            }
            cur = cur->next;
        }
        throw runtime_error("# not found!");
    }

    // 链表长度
    int len(){
        return length;
    }
};

// 双链表 -- 正常添加
class DoubleLinkedList : public DoubleListF{
    DoubleNode* tail;
public:
    DoubleLinkedList(){
        tail = head;
    }

    void add(int num, string name, int money){
        tail->next = new DoubleNode(num, name, money);
        tail = tail->next;
        cout<<"# new Node:\n";
        tail->show();
    }

    void del(int key){
        if(isEmpty()){
            cout << "# empty list!\n";
            return;
        }
        DoubleNode* cur = head->next;
        while(cur != nullptr){
            if(cur->num == key){
                cur->pre->next = cur->next;
                if(cur->next != nullptr) cur->next->pre = cur->pre;
                cout <<"# delete Node:\n";
                cur->show();
                delete cur;
                return;
            }
            cur = cur->next;
        }
        cout << "# not fount!\n";
    }
};

// 双链表 -- 顺序添加
class DoubleOrderedList : public DoubleListF{
    void add(int num, string name, int money){
        DoubleNode* cur = head;
        while(1){
            if(cur->next == nullptr || cur->next->num > num){
                DoubleNode* node = new DoubleNode(num, name, money);
                node->next = cur->next;
                cur->next = node;
                node->pre = cur;
                if(node->next != nullptr) node->next->pre = node;
                cout << "# new Node:\n";
                node->show(); 
                return;
            }else if(cur->next->num == num){
                cout << "# the node has existed:\n";
                cur->next->show();
                return;
            }
            cur = cur->next;
        }
    }

    void del(int key){
        if(isEmpty()){
            cout<<"# empty list!"<<endl;
            return;
        }
        DoubleNode* cur = head->next;
        while(cur != nullptr){
            if(cur->num == key){
                cur->pre->next = cur->next;
                if(cur->next != nullptr) cur->next->pre = cur->pre;
                cout<<"# delete Node:\n";
                cur->show();
                delete cur;
                return;
            }else if(cur->num > key) break;
            cur = cur->next;
        }
        cout << "# not found!\n";
    }
};

// 循环链表 -- 单纯为了解决约瑟夫问题
class Cnode{
public:
    int data;
    Cnode* next;
    Cnode(int data){
        this->data = data;
        next = nullptr;
    }
};

class CircleList{
public: 
    Cnode* head;
    int length;
    CircleList(int i){
        length = i;
        head = new Cnode(1);
        Cnode* cur = head;
        for(int j = 2; j <= i; ++j){
            cur->next = new Cnode(j);
            cur = cur->next;
        }
        cur->next = head;
    }

    void show(Cnode* node){
        Cnode* cur = node;
        cout<<"[ ";
        for(int i = 0; i < length; ++i){
            cout << cur->data <<" ";
            cur = cur->next;
        }
        cout<<"]\n";
    }

    void Joseph(int begin, int steps){
        Cnode* cur = head;
        if(begin > length){
            cout << "begin pos is not exist!";
            return;
        }
        while(begin > 1){ // 到达第n个
            cur = cur->next;
            --begin;
        }
        if(steps == 1){
            show(cur);
            return;
        }
        while(length > 1){
            cur = getTarPre(cur, steps);
            Cnode *temp = cur->next;
            cout << " -pop [" << temp->data <<"];\n";
            cur->next = temp->next;
            cur = cur->next;
            delete temp;
            --length;
        }
        cout << " -pop [" << cur->data <<"]\n# finished~\n";
    }

    Cnode* getTarPre(Cnode* beg, int target){
        Cnode* cur = beg;
        while(target > 2){
            cur = cur->next;
            --target;
        }
        return cur;
    }
};