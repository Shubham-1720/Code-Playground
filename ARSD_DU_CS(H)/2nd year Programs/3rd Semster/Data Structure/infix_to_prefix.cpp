#include <iostream>
#include <string>
#include <stack>
using namespace std;

string convert(string str)
{
    string newExpression = "";
    for (int i = (str.length() - 1); i >= 0; i--)
    {
        if (str[i] == '(')
        {
            newExpression += ')';
        }

        else if (str[i] == ')')
        {
            newExpression += '(';
        }

        else
        {
            newExpression += str[i];
        }
    }
    return newExpression;
}

int precedenceChecker(char ch)
{

    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool isoperend(char ch)
{
    if ((ch >= 'a') && (ch <= 'z') || (ch >= 'A') && (ch <= 'Z'))
        return true;
    else
        return false;
}

bool isoperator(char ch)
{
    if ((ch == '^') || (ch == '*') || (ch == '/') || (ch == '+') || (ch == '-'))
        return true;
    else
        return false;
}

string infixToPostfix(string exp)
{
    stack<char> stack;
    string postfixExp;
    char sym;

    for (int i = 0; i < exp.length(); i++)
    {
        sym = exp[i];
        if (isoperend(sym))
        {
            postfixExp += sym;
        }
        else if (sym == '(')
        {
            stack.push(sym);
        }
        else if (sym == ')')
        {
            while (stack.top() != '(')
            {
                postfixExp += stack.top();
                stack.pop();
            }
            stack.pop();
        }

        else if (isoperator(sym))
        {
            while (!stack.empty() && precedenceChecker(sym) < precedenceChecker(stack.top()))
            {
                postfixExp += stack.top();
                stack.pop();
            }
            stack.push(sym);
        }
    }
    while (!stack.empty())
    {
        postfixExp += stack.top();
        stack.pop();
    }

    return postfixExp;
}

int main()
{
    string expression;
    cout << "Enter your expresssion for infix to prefix conversion" << endl;
    cin >> expression;
    cout << "Expression converted into prefix is" << endl;
    cout << convert(infixToPostfix(convert(expression)));
    return 0;
}