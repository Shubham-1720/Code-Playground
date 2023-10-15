#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

bool isoperator(char ch)
{
    if ((ch == '$') || (ch == '*') || (ch == '/') || (ch == '+') || (ch == '-'))
        return true;
    else
        return false;
}

int evaluation(string str)
{
    stack<int> stack;

    for (int i = 0; i < str.length(); i++)
    {

        if (isoperator(str[i]))
        {

            int op2 = stack.top();
            stack.pop();
            int op1 = stack.top();
            stack.pop();
            if (str[i] == '+')
            {
                stack.push(op1 + op2);
            }
            if (str[i] == '-')
            {
                stack.push(op1 - op2);
            }
            if (str[i] == '*')
            {
                stack.push(op1 * op2);
            }
            if (str[i] == '/')
            {
                stack.push(op1 / op2);
            }
            if (str[i] == '$')
            {
                stack.push(pow(op1, op2));
            }
        }
        else
        {
            stack.push(int(str[i]) - 48);
        }
    }
    return stack.top();
}

main()
{
    cout << "Enter postfix expression to evalute " << endl;
    string exp;
    cin >> exp;
    cout << "Evaluted expression is " << endl;
    cout << evaluation(exp);
    return 0;
}