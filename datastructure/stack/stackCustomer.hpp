#include "stack.hpp"
#include <vector>
#include <stack>

// 中缀表达式计算器
void stackCalculator();

void sCustomerInterface(int key){
    StackF *stack;
    if(key == 1){
        cout<<"[linked list stack] -- test:"<<endl;
        stack = new ListStack();
    }
    if(key == 0){
        cout<<"$ input the maxSize:";
        int maxSize = 0;
        cin >> maxSize;
        if(key == 0) {
            stack = new ArrayStack(maxSize);
            cout<<"[linear array stack] -- test:"<<endl;
        }
    }
    if(key == 2){
        stackCalculator();
        return;
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

bool isSimbol(char ch){
    return ch == '(' || ch == ')' || 
            ch == '+' || ch == '-' || 
            ch == '*' || ch == '/';
}

// 字符串 -> 字符数组
vector<string> getChar(string s){
    vector<string> exp;
    string temp = "";
    for(auto it : s){
        if(it != '_' && !isSimbol(it)){
            temp += it;
        }
        else{ // it是字符或空格
            if(temp.size()!=0){ // 此时将数字加入到表达式
                exp.push_back(temp);
            }
            if(it != '_'){ // 不是空格，说明是符号，符号插入表达式
                exp.push_back(string(1,it));
            }
            temp = ""; // temp置空
        }
    }
    if(!temp.empty())
        exp.push_back(temp);
    return exp;
}

// 中缀表达式转后缀表达式
vector<string> mid2infix(vector<string>& mid){
    vector<string> infix = mid;

    return infix;
}

// 计算二元表达式
double calculate(double num1, double num2, char ch){
    switch(ch){
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
    }
    throw runtime_error("invalid operator");
}

// 计算后缀表达式
double calculate(vector<string>& exp){
    stack<double> digit;
    for(auto it : exp){
        if(it.size() == 1 && isSimbol(it[0])){
            double num1 = digit.top();
            digit.pop();
            double num2 = digit.top();
            digit.pop();
            digit.push(calculate(num2,num1,it[0]));
        }else digit.push(stod(it));
    }
    return digit.top();
}

// 前缀表达式计算器
void stackCalculator(){
    string input = "";
    while(1){
        // 提示用户输入计算表达式
        cout << "$ input the expression: ";
        cin >> input;
        // 表达式字符串转字符数组
        vector<string> exp = getChar(input);
        // 中缀表达式转后缀表达式
        exp = mid2infix(exp);
        // 计算后缀表达式
        cout<< "# result:\n";
        cout<< " [" << input<<"] = "<<calculate(exp)<<endl;
        cout << "stop? [y/n] ";
        char stop = ' ';
        cin >> stop;
        if(stop == 'y') break;
    }
    cout << "shut down calculator, bye~\n";
}

