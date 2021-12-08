#include "hash.hpp"

void hCustomerInterface(){
    cout<<"$ input the HashNumber:";
    int HashNum = 0;
    cin >> HashNum;
    HashList *hash = new HashList(HashNum);
    cout<<"[cicle array queue] -- test:"<<endl;
    while(1){
        cout<<endl;
        cout<<"-------------Menu-------------"<<endl;
        cout<<"----a(add)----add an item-----"<<endl;
        cout<<"----d(del)---delete an item---"<<endl;
        cout<<"----c(chan)---change item-----"<<endl;
        cout<<"----s(show)--show the hash----"<<endl;
        cout<<"----e(exit)---exit program----"<<endl;
        cout<<"$ input a char to choose:";
        char ch = ' ';
        cin >> ch;
        switch (ch)
        {
        case 'a':{
            int num = 0, age = 0;
            string name = "";
            cout<<"$ input a number: ";
            cin >> num;
            cout<<"$ input name: ";
            cin >> name;
            cout<<"$ input age: ";
            cin >> age;
            hash->add(num, name, age);
            break;
            }
        case 'd':{
            cout<<"$ input a number:";
            int num = 0;
            cin >> num;
            hash->del(num);
            break;
            }
        case 'c':{
            int num = 0, age = 0;
            string name = "";
            cout<<"$ input a number: ";
            cin >> num;
            cout<<"$ input name: ";
            cin >> name;
            cout<<"$ input age: ";
            cin >> age;
            hash->change(num, name, age);
            break;
            }
        case 's':
            hash->show();
            break;
        case 'e':
            cout << "# exit program" << endl;
            //delete queue;
            return; 
        default:
            break;
        }
    }
}