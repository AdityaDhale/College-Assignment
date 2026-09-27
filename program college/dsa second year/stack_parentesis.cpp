#include <iostream>
#include <string>
using namespace std;

class Stack
{
    char arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(char ch)
    {
        if (top < 99)
        {
            arr[++top] = ch;
        }
    }

    char pop()
    {
        if (top == -1)
        {
            return '\0';
        }

        return arr[top--];
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

bool isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return true;

    if (open == '{' && close == '}')
        return true;

    if (open == '[' && close == ']')
        return true;

    return false;
}

bool checkExpression(string expression)
{
    Stack s;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        // Opening brackets are pushed into stack
        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }

        // Closing brackets are checked with stack top
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            // No opening bracket available
            if (s.isEmpty())
            {
                return false;
            }

            char open = s.pop();

            // Check whether brackets match
            if (!isMatching(open, ch))
            {
                return false;
            }
        }
    }

    // Stack must be empty at the end
    return s.isEmpty();
}

int main()
{
    string expression;

    cout << "Enter an expression: ";
    getline(cin, expression);

    if (checkExpression(expression))
    {
        cout << "Expression is well parenthesized." << endl;
    }
    else
    {
        cout << "Expression is not well parenthesized." << endl;
    }

    return 0;
}