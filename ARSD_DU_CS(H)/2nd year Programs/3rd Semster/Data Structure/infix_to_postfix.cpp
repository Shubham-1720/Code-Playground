#include <iostream>
#include <stack>

using namespace std;

int precedenceChecker(char ch){

    if(ch=='^'){
        return 3;
    }
    else if(ch=='*' || ch=='/'){
        return 2;
    }
    else if(ch=='+' || ch=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

bool isoperend(char ch){
    if((ch>='a') && (ch<='z') || (ch>='A') && (ch<='Z'))
        return true;
    else
        return false;
}

bool isoperator(char ch){
    if((ch=='^') || (ch=='*') || (ch=='/') || (ch=='+') || (ch=='-'))
        return true;
    else
        return false;
}

void infixToPostfix(string exp){
    stack<char> stack;
    string postfixExp;
    char sym;

    for (int i = 0; i < exp.length(); i++)
    {
        sym = exp[i];
        if(isoperend(sym)){
            postfixExp += sym;
            cout<<postfixExp<<endl;
        }
        else if(sym=='('){
            stack.push(sym);
        }
        else if(sym==')'){
            while(stack.top()!='('){
                postfixExp += stack.top();
                stack.pop();
                cout<<postfixExp<<endl;
           }
           stack.pop();
        }

        else if(isoperator(sym)){
            while(!stack.empty() && precedenceChecker(sym)  <= precedenceChecker(stack.top())){
                postfixExp += stack.top();
                stack.pop();
                cout<<postfixExp<<endl;
            }
            stack.push(sym);
        }

    }
    while(!stack.empty()){
        postfixExp += stack.top();
        stack.pop();
        cout<<postfixExp<<endl;
    }
    
}

main(){
    string expression;
    cout<<"Enter your expresssion for infix to postfix conversion"<<endl;
    cin >>expression;
    infixToPostfix(expression);
    return 0;
}