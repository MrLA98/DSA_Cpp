#include "linkedlist.hpp"

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