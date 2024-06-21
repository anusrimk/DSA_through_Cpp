#include <iostream>
using namespace std;

class Stack
{
private:
    int top;
    char arr[15];

public:
    Stack()
    {
        top = -1;
    }

    char pop()
    {
        if (top == -1)
        {
            return ':';
        }
        char temp = arr[top];
        arr[top] = '0';
        top--;
        return temp;
    }

    char peek()
    {
        return arr[top];
    }

    void push(char a)
    {
        if (top == 14)
        {
            return;
        }
        top++;
        arr[top] = a;
    }
};
class IntStack
{
public:
    int top;
    int arr[15];

    IntStack()
    {
        top = -1;
    }

    int pop()
    {
        if (top == -1)
        {
            return 0;
        }
        char temp = arr[top];
        arr[top] = -1;
        top--;
        return temp;
    }

    int peek()
    {
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

void print(IntStack a)
{
    for (int i = 0; i <= a.top; i++)
    {
        cout << a.arr[i] << " ";
    }
}

int calculate(string infix)
{

    // Operators (+,-,*,/,%)
    // Coversion to postfix

    infix = "(" + infix + ")";
    string postfix = "";
    Stack operators;

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '*' || infix[i] == '/' || infix[i] == '%')
        {
            while (operators.peek() == '*' || operators.peek() == '/' || operators.peek() == '%')
            {
                postfix += operators.pop();
            }
            operators.push(infix[i]);
        }
        else if (infix[i] == '+' || infix[i] == '-')
        {
            while (operators.peek() == '*' || operators.peek() == '/' || operators.peek() == '%' || operators.peek() == '+' || operators.peek() == '-')
            {
                postfix += operators.pop();
            }
            operators.push(infix[i]);
        }
        else if (infix[i] == '(')
        {
            operators.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (operators.peek() != '(')
            {
                postfix += operators.pop();
            }
            operators.pop(); // Pop the '('
        }
        else
        {
            postfix += infix[i];
        }
    }

    IntStack b;

    for (int i = 0; i < postfix.length(); i++)
    {
        int C, A;
        if (isdigit(postfix[i]))
        {
            b.push(int(postfix[i]) - 48);
        }
        else if (postfix[i] == '*')
        {
            C = b.pop();
            A = b.pop();
            b.push(A * C);
        }
        else if (postfix[i] == '-')
        {
            C = b.pop();
            A = b.pop();

            b.push((A - C));
        }
        else if (postfix[i] == '+')
        {
            C = b.pop();
            A = b.pop();

            b.push((A + C));
        }
        else if (postfix[i] == '/')
        {
            C = b.pop();
            A = b.pop();
            b.push((A / C));
        }
        else if (postfix[i] == '%')
        {
            C = b.pop();
            A = b.pop();
            b.push((A % C));
        }
        else
        {
            continue;
        }
    }

    return b.peek();
}

int main()
{
    cout << calculate("((9-((3*4)+8)/4))") << "\n";
    return 0;
}