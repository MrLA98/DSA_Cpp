#include "queue.hpp"
using namespace std;

void qCustomerInterface(int key){
    QueueF *queue;
    if(key == 2){
        cout<<"[linked list queue] -- test:"<<endl;
        queue = new QueueList();
    }else{
        cout<<"$ input the maxSize:";
        int maxSize = 0;
        cin >> maxSize;
        if(key == 0) {
            queue = new QueueArray(maxSize);
            cout<<"[linear array queue] -- test:"<<endl;
        }
        else {
            queue = new QueueCircle(maxSize);
            cout<<"[cicle array queue] -- test:"<<endl;
        }
    }
    while(1){
        cout<<endl;
        cout<<"-------------Menu-------------"<<endl;
        cout<<"----a(add)----add a number----"<<endl;
        cout<<"----p(pop)----pop a number----"<<endl;
        cout<<"----l(len)---length of queue--"<<endl;
        cout<<"----s(show)---show the queue--"<<endl;
        cout<<"----e(exit)---exit program----"<<endl;
        cout<<"$ input a char to choose:";
        char ch = ' ';
        cin >> ch;
        switch (ch)
        {
        case 'a':
            {cout<<"$ input a number:";
            int num = 0;
            cin >> num;
            queue->push(num);
            break;}
        case 'p':
            try{
                int num = queue->pop();
                cout << "# pop a number:"<< num << endl;
            }
            catch(const runtime_error err){
                cerr << err.what() << endl;
            }
            break;
        case 'l':
            cout << "# length of queue: " << queue->length() << endl;
            break;
        case 's':
            queue->show();
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