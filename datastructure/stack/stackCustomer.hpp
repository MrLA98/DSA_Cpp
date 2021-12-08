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

bool isSimbol(string s){
    if(s.size() == 1 && isSimbol(s[0])){
        return true;
    }
    return false;
}

int priority(string s){
    if(s == "*" || s == "/") return 2;
    if(s == "+" || s == "-") return 1;
    return 0;
}

// 字符串 -> 字符数组
vector<string> getChar(string s){
    vector<string> exp;
    string temp = "";
    for(auto it : s){
        if(!isSimbol(it)){ // 数字
            temp += it;
        }
        else{ // it是字符
            if(temp.size()!=0){ // 此时将数字加入到表达式
                exp.push_back(temp);
            }
            // 符号插入表达式
            exp.push_back(string(1,it));
            temp = ""; // temp置空
        }
    }
    if(!temp.empty())
        exp.push_back(temp);
    return exp;
}

// 中缀表达式转后缀表达式
vector<string> mid2infix(vector<string>& mid){
    vector<string> infix; // 结果数组
    stack<string> operStack; // 符号栈
    // 遍历中缀表达式
    for(auto it : mid){
        if(!isSimbol(it)){ // 数字直接输出
            infix.push_back(it);
        }
        // 下面都是对符号的处理
        else if(it == ")"){ // 1.右括号，不停弹栈，直到遇到左括号
            while(operStack.top() != "("){
                infix.push_back(operStack.top());
                operStack.pop();
            }
            operStack.pop(); // 左括号也弹出 -- 左右括号抵消
        }else if(operStack.empty() // 2.栈空
              || it == "(" // 3.左括号
              || operStack.top() == "(" // 4.栈顶是左括号
              || priority(it) > priority(operStack.top()) // 5.新符号比栈顶符号优先
        ) {
            operStack.push(it); // 该符号直接入栈
        } 
        // 6.新符号优先级较低
        else {
            // 只要栈没空 且 栈顶符号优先级更高
            while(!operStack.empty() && priority(it) <= priority(operStack.top())){
                // 不停将栈顶元素弹出到结果数组中
                infix.push_back(operStack.top());
                operStack.pop();
            }
            operStack.push(it); // 再将该符号放入
        }
    }
    // 栈里剩下的依次弹出
    while(!operStack.empty()){
        infix.push_back(operStack.top());
        operStack.pop();
    }
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

