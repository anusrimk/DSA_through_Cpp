#include <iostream>

using namespace std;

class List
{
public:
    int n;    // No. of elements
    int size; // Size of Array
    int *arr; // First byte Address of Array

    List()
    {
        arr = (int *)malloc(sizeof(int));
        size = 1;
        n = 0;
    }

    void append(int val)
    {
        if (size <= n)
        {
            arr = resize(arr, size + 2);
            size += 2;
        }
        arr[n] = val;
        n++;
    }

    int len()
    {
        return n;
    }

    void pop()
    {
        n -= 1;
    }

    int *resize(int *a, int size)
    {
        int *ptr = (int *)realloc(a, size + 2);
        return ptr;
    }

    void insertbefore(int val, int ele)
    { // Value you want to enter before ele
        if (n == size)
        {
            arr = resize(arr, size + 2);
            size += 2;
        }
        int index = search(ele);
        if (index == -1)
        {
            return;
        }
        if (index == 0)
        {
            index = 1;
        }
        insert(index - 1, val);
        n += 1;
        return;
    }

    void insertafter(int val, int ele)
    { // Value you want to enter after ele
        if (n == size)
        {
            arr = resize(arr, size + 2);
            size += 2;
        }
        int index = search(ele);
        if (index == -1)
        {
            return;
        }

        insert(index + 1, val);
        n += 1;
        return;
    }

    void insert(int index, int val)
    {
        if (index > n)
        {
            index = n;
        }
        if (size <= n)
        {
            arr = resize(arr, size + 2);
            size += 2;
        }
        for (int i = n; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[index] = val;
        n++;
        return;
    }

    void del(int val)
    {
        int index = search(val);
        if (index == -1)
        {
            return;
        }
        idel(index);
        return;
    }

    void delbefore(int val)
    {
        int index = search(val);
        if (index == -1)
        {
            return;
        }
        if (index == 0)
        {
            return;
        }
        idel(index - 1);
        return;
    }

    void delafter(int val)
    {
        int index = search(val);
        if (index == -1)
        {
            return;
        }
        if (index == n - 1)
        {
            return;
        }
        idel(index + 1);
        return;
    }

    void idel(int index)
    {

        for (int i = index; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        n -= 1;
        return;
    }

    void idelafter(int index)
    {
        if (index <= 0)
        {
            if (n == 0)
            {
                return;
            }
            index = 0;
        }
        if (index == n - 1)
        {
            return;
        }
        idel(index + 1);

        return;
    }

    void idelbefore(int index)
    {
        if (index > n)
        {
            index = n;
        }
        if (index == 0)
        {
            return;
        }
        idel(index - 1);

        return;
    }

    int search(int val)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }

    int &operator[](int i)
    {
        if (i < 0 || i >= n)
        {
            cout << "Index out of bounds." << endl;
            exit(EXIT_FAILURE);
        }
        return arr[i];
    }

    ~List()
    {
        free(arr);
    }
};

void print(List &a)
{
    int length = a.len();

    if (length == 0)
    {
        return;
    }
    cout << "[";
    for (int i = 0; i < length; i++)
    {
        if (i == length - 1)
        {
            cout << a[i];
            break;
        }
        cout << a[i] << ",";
    }
    cout << "]";
    return;
}

class Stack
{
private:
    int top;
    int arr[15];

public:
    Stack()
    {
        top = -1;
    }

    int pop()
    {
        if (top == -1)
        {
            return -1;
        }
        int temp = arr[top];
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

void reverseusingstack(List &a)
{
    Stack s;
    for (int i = 0; i < a.n; i++)
    {
        s.push(a[i]);
    }

    for (int i = 0; i < a.n; i++)
    {
        a[i] = s.pop();
    }
}

int main()
{
    List l;
    l.append(10);
    l.append(20);
    l.append(30);
    l.append(40);
    l.append(50);
    reverseusingstack(l);
    print(l);

    return 0;
}