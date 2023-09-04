#include <iostream>
using namespace std;
const int size = 10;
class Stack
{
private:
    int stack[size];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isfull()
    {
        if (top == size)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isempty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void push()
    {
        if (isfull())
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            cout << "Enter the element to be push" << endl;
            cin >> stack[++top];
            cout << "Element pushed" << endl;
        }
    }

    void pop()
    {
        if (isempty())
        {
            cout << "stack underflow" << endl;
        }
        else
        {
            stack[top--] = 0;
            cout << "Element poped" << endl;
        }
    }

    void peek()
    {
        int element = stack[top];
        cout << "Top most element is: " << element << endl;
    }

    void display()
    {
        cout<<"[";
        for (int i = 0; i <= top; i++)
        {
            cout << stack[i] << " , ";
        }
         cout<<"]"<<endl;
    }
};

int main()
{
    Stack stack1;

    bool ans = true;

    do
    {
        cout << "This is menu for stack operations" << endl;
        cout << "Enter 1 for push operation" << endl;
        cout << "Enter 2 for pop operation" << endl;
        cout << "Enter 3 for peek operation" << endl;
        cout << "Enter 4 for display operation" << endl;
        cout << "Enter the your choice " << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            stack1.push();
            break;

        case 2:
            stack1.pop();
            break;

        case 3:
            stack1.peek();
            break;

        case 4:
            stack1.display();
            break;
        }

        cout << "Enter x to exist from program or any key to continue" << endl;
        char ch;
        cin >> ch;
        if (ch == 'x')
        {
            ans = false;
        }
    } while (ans);

    // stack1.display();
    // stack1.peek();
    // stack1.push();
    // stack1.display();
    // stack1.peek();
    // stack1.pop();
    // stack1.display();
    return 0;
}