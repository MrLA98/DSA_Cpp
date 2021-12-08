#include "linkedlist.hpp"

// 测试常用方法
void lCustomerQuiz();

// 测试数据结构
void lCustomerInterface(int key){
    ListF* list;
    if(key == 0){
        cout << "[single linked list] -- test:"<<endl;
        list = new SingleLinkedList();
    }
    if(key == 1){
        cout << "[single ordered list] -- test:"<<endl;
        list = new SingleOrderedList();
    }
    if(key == 2){
        cout << "[double linked list] -- test:"<<endl;
        list = new DoubleLinkedList();
    }
    if(key == 3){
        cout << "[double ordered list] -- test:"<<endl;
        list = new DoubleOrderedList();
    }
    if(key == 4){
        lCustomerQuiz();
        return;
    }
    if(key == 5){
        cout << "[Joseph Problem] -- test:"<<endl;
        int students, start , steps;
        cout << "input the num of students: ";
        cin >> students;
        CircleList *joseph = new CircleList(students);
        cout << "input the begin number: ";
        cin >> start;
        cout << "inpute the steps: ";
        cin >> steps;
        joseph->Joseph(start, steps);
        return;
    }

    while(1){
        cout<<endl;
        cout<<"-------------Menu-------------"<<endl;
        cout<<"----a(add)-----add a node-----"<<endl;
        cout<<"----d(del)----delete a node---"<<endl;
        cout<<"----l(len)---length of list---"<<endl;
        cout<<"----f(find)----find node------"<<endl;
        cout<<"----s(show)---show the list---"<<endl;
        cout<<"----e(exit)---exit program----"<<endl;
        cout<<"$ input a char to choose:";
        char ch = ' ';
        cin >> ch;
        switch (ch)
        {
        case 'a':
            {cout<<"$ input the number: ";
            int num = 0;
            cin >> num;
            cout<<"$ input the name: ";
            string name = "";
            cin >> name;
            cout<<"$ input the money: ";
            int money = 0;
            cin >> money;
            list->add(num, name, money);
            break;}
        case 'd':
            {cout<<"$ input the number: ";
            int key = 0;
            cin >> key;
            list->del(key);
            break;}
        case 'l':
            cout << "# length of list: " << list->len() << endl;
            break;
        case 'f':
            {cout<<"$ input the number: ";
            int key = 0;
            cin >> key;
            cout<<"# finding...\n";
            try{
                list->find(key)->show();
            }
            catch(runtime_error err){
                cerr << err.what() << endl;
            }
            break;}
        case 's':
            list->show();
            break;
        case 'e':
            cout << "# exit program" << endl;
            //delete list;
            return; 
        default:
            break;
        }
    }
}

// 生成节点链表
SingleNode* generateNodes(){
    cout << "# generate a list with nodes:\n";
    SingleNode *head = new SingleNode(0,"",0), *cur = head;
    while(1){
        // 初始化输入
        int num = 0, money = 0;
        string name = "";
        char a = ' ';
        // 提示用户输入
        cout << "$ input a number: ";
        cin >> num;
        cout << "$ input name: ";
        cin >> name;
        cout << "$ input money: ";
        cin >> money;
        // 链表添加
        cur->next = new SingleNode(num, name, money);
        cur = cur->next;
        // 是否继续
        cout << "stop? [y/n]";
        cin >> a;
        if(a == 'y') break;
    }
    return head->next;
} 

// 给定头节点，返回链表节点的个数 -- 头也是数据
int getNodeNum(SingleNode *head){
    int count = 0;
    SingleNode *cur = head;
    while(cur != nullptr){
        ++count;
        cur = cur->next;
    }
    return count;
}

// 获取链表的倒数第k个节点
void getEndKNode(SingleNode *head, int k){
    SingleNode *cur1 = head, *cur2 = head;
    for(; k > 0; --k){
        if(cur1 == nullptr){
            cout << "# K is bigger than the length of list\n";
            return;
        } 
        cur1 = cur1->next;
    }
    while(cur1 != nullptr){
        cur2 = cur2->next;
        cur1 = cur1->next;
    }
    cout << "# last Kth Node: \n";
    cur2->show();
}

// 反转链表
SingleNode* reverseList(SingleNode *head){
    SingleNode *cur1 = nullptr, *cur2 = nullptr;
    while(head != nullptr){
        cur1 = head;
        head = head->next;
        cur1->next = cur2;
        cur2 = cur1;
    }
    return cur1;
}

// 反转链表 -- 头插法
SingleNode* reverseList2(SingleNode *head){
    SingleNode *node = new SingleNode(0, "", 0), *cur = head;
    while(head != nullptr){
        head = head->next;
        cur->next = node->next;
        node->next = cur;
        cur = head;
    }
    return node->next;
}

// 反转链表 -- 递归
SingleNode* reverseList3(SingleNode *head){
    if(!head || !head->next) return head;
    SingleNode* newHead = reverseList3(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

// 打印链表
void showList(SingleNode *head){
    if(head == nullptr) return;
    head->show();
    showList(head->next);
}

// 测试常用方法
void lCustomerQuiz(){
    cout << "# test some functions : \n";
    SingleNode* listHead = generateNodes();
    cout << " [print the list]: \n";
    showList(listHead);
    int count = getNodeNum(listHead);
    cout << " [length of list]: " << count << endl;
    cout << "$ input a number smaller than " << count << " : ";
    cin >> count;
    cout << " [the last "<< count <<"th node]: \n";
    getEndKNode(listHead, count);
    cout << " [reverse the list]: \n";
    listHead = reverseList(listHead);
    showList(listHead);
    cout << " [reverse again]: \n";
    listHead = reverseList2(listHead);
    showList(listHead);
    cout << " [reverse again]: \n";
    listHead = reverseList3(listHead);
    showList(listHead);
}