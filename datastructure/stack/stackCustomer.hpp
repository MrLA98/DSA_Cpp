#include "stack.hpp"

void sCustomerInterface(int key){
    StackF *stack;
    if(key == 1){
        cout<<"[linked list stack] -- test:"<<endl;
        stack = new ListStack();
    }else{
        cout<<"$ input the maxSize:";
        int maxSize = 0;
        cin >> maxSize;
        if(key == 0) {
            stack = new ArrayStack(maxSize);
            cout<<"[linear array stack] -- test:"<<endl;
        }
    }
    while(1){
        cout<<endl;
        cout<<"-------------Menu-------------"<<endl;
        cout<<"----a(add)----add a number----"<<endl;
        cout<<"----p(pop)----pop a number----"<<endl;
        cout<<"----l(len)---length of stack--"<<endl;
        cout<<"----t(top)----top of stack----"<<endl;
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
            stack->push(num);
            break;}
        case 'p':
            try{
                int num = stack->pop();
                cout << "# pop a number: "<< num << endl;
            }
            catch(const runtime_error err){
                cerr << err.what() << endl;
            }
            break;
        case 'l':
            cout << "# length of stack: " << stack->size() << endl;
            break;
        case 't':
            try{
                int num = stack->peek();
                cout << "# top number: "<< num << endl;
            }
            catch(const runtime_error err){
                cerr << err.what() << endl;
            }
            break;
        case 's':
            stack->show();
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