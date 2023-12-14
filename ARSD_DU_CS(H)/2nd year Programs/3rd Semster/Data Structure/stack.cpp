#include <iostream>
#include<cmath>
using namespace std;

const int size = 50;

class stack{
  int Stack[size];
  int top;
  public:
  stack(){
    top = -1;
  }
  bool isFull();
  bool isEmpty();
  void push(int);
  void pop();
  int peek();
  void display();
};

bool stack::isFull(){
  if(top == size-1)
    return true;
  else
    return false;
}

bool stack:: isEmpty(){
  if(top==-1)
    return true;
  else
    return false;
}

void stack::push(int num){
  if(isFull())
    cout<<"Stack is already full"<<endl;

  else{
    
    Stack[++top] = num;
    cout<<"Element pushed"<<endl;
  }
}

void stack::pop(){
  if(isEmpty())
    cout<<"stack is empty"<<endl;
  else{
    Stack[top--] = 0;
    cout<<"Element deleted"<<endl;
  }
}

int stack::peek(){
  return Stack[top];
}
void stack::display(){
  for(int i = 0; i<top+1; i++){
    cout<<Stack[i]<<" ";
    
  }
}

bool isOperator(char ch){
  if((ch == '$')||(ch == '*')||(ch == '+')||(ch == '/')||(ch == '-')){
    return true;
    
  }
  else{
    return false;
  }
}

// int evaluation(string st){
//   stack mystack;

//   for(int i =0; i < st.length(); i++){
//     if(isOperator(st[i])){
//       int num2 = mystack.peek();
//       mystack.pop();
//       int num1 = mystack.peek();
//       mystack.pop();
//       if(st[i] == '+'){
//         mystack.push(num1+num2);
//       }
//       if(st[i] == '-'){
//         mystack.push(num1-num2);
//       }
//       if(st[i] == '*'){
//         mystack.push(num1*num2);
//       }
//       if(st[i] == '/'){
//         mystack.push(num1/num2);
//       }
//       if(st[i] == '$'){
//         mystack.push(pow(num2,num1));
//       }
      
      
//     }
//     else{
//       mystack.push(int(st[i]-48));
//     }
//   }
//   return mystack.peek();
// }
int evaluation(string st){
  stack mystack;

  for(int i = (st.length()-1); i >=0 ; i--){
    
    if(isOperator(st[i])){
      int num2 = mystack.peek();
      mystack.pop();
      int num1 = mystack.peek();
      mystack.pop();
      if(st[i] == '+'){
        mystack.push(num1+num2);
      }
      if(st[i] == '-'){
        mystack.push(num1-num2);
      }
      if(st[i] == '*'){
        mystack.push(num1*num2);
      }
      if(st[i] == '/'){
        mystack.push(num1/num2);
      }
      if(st[i] == '$'){
        mystack.push(pow(num2,num1));
      }


    }
    else{
      mystack.push(int(st[i]-48));
    }
  }
  return mystack.peek();
}

 
int main() {
  // stack mystack;
  // mystack.push(2);
  // mystack.push(5);
  // mystack.push(8);
  // mystack.display();
  // mystack.peek();z
  // mystack.pop();
  // mystack.peek();
  cout<<evaluation("+9*26");

  
}

// #include <iostream>
// #include <stack>
// #include <string>
// #include <cmath>
// using namespace std;

// bool isoperator(char ch)
// {
//     if ((ch == '$') || (ch == '*') || (ch == '/') || (ch == '+') || (ch == '-'))
//         return true;
//     else
//         return false;
// }

// int evaluation(string str)
// {
//     stack<int> stack;

//     for (int i = 0; i < str.length(); i++)
//     {

//         if (isoperator(str[i]))
//         {

//             int op2 = stack.top();
//             stack.pop();
//             int op1 = stack.top();
//             stack.pop();
//             if (str[i] == '+')
//             {
//                 stack.push(op1 + op2);
//             }
//             if (str[i] == '-')
//             {
//                 stack.push(op1 - op2);
//             }
//             if (str[i] == '*')
//             {
//                 stack.push(op1 * op2);
//             }
//             if (str[i] == '/')
//             {
//                 stack.push(op1 / op2);
//             }
//             if (str[i] == '$')
//             {
//                 stack.push(pow(op1, op2));
//             }
//         }
//         else
//         {
//             stack.push(int(str[i]) - 48);
//         }
//     }
//     return stack.top();
// }

// int main()
// {
//     cout << "Enter postfix expression to evalute " << endl;
//     string exp;
//     cin >> exp;
//     cout << "Evaluted expression is " << endl;
//     cout << evaluation(exp);
//     return 0;
// }