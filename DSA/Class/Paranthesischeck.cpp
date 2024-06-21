#include <iostream>

using namespace std;

class Stack
{
private:
    int top;
    string arr[15];

public:
    Stack()
    {
        top = -1;
    }

    string pop()
    {
        if (top == -1)
        {
            return "";
        }
        string temp = arr[top];
        arr[top] = -1;
        top--;
        return temp;
    }

    string peek()
    {
        if (top == -1)
        {
            return " ";
        }
        return arr[top];
    }

    void push(int a)
    {
        if (top == 14)
        {
            return;
        }
        top++;
        arr[top] = a;
    }
};

void paranthesis(string s)
{
    Stack a;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            a.push(s[i]);
        }
        else
        {

            if ((s[i] == ')' && a.peek() == "(") || (s[i] == ']' && a.peek() == "[") || (s[i] == '}' && a.peek() == "{"))
            {
                a.pop();
            }
        }
    }
    if (a.peek() == " ")
    {
        cout << "VALID";
    }
    else
    {
        cout << "INVALID";
    }
}

int main()
{
    string l;

    cout << "Enter the expression : ";
    cin >> l;

    paranthesis(l);
    return 0;
}