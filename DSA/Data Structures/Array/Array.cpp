#include <iostream>

using namespace std;

class List
{
public:
    int n;        // No. of elements
    int arr[100]; // First byte Address of Array

    List()
    {

        n = 0;
    }

    void append(int val)
    {
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

    void insertbefore(int val, int ele)
    { // Value you want to enter before ele
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

int main()
{
    List l;
    int choice;
start:
    cout << "\n1.Display Array\n2.Insertion\n3.Deletion\n4.Search\n5.Length\n6.Exit\n : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        print(l);
        goto start;
        break;

    case 2:
        int a1;
        cout << "\nInsertion :\n1.Insert at beginning\n2.Insert at end(appending)\n3.Insert before element\n4.Insert after element\n5.Main menu\n : ";
        cin >> a1;
        switch (a1)
        {
        case 1:
            int val1;
            cout << "Enter the value to insert at beginning : ";
            cin >> val1;
            l.insert(0, val1);
            goto start;
            break;
        case 2:
            int val2;
            cout << "Enter the value to append : ";
            cin >> val2;
            l.append(val2);
            goto start;
            break;
        case 3:
            int val3, ele1;
            cout << "Enter the value to insert : ";
            cin >> val3;
            cout << "Enter the element to insert before : ";
            cin >> ele1;
            l.insertbefore(val3, ele1);
            goto start;
            break;
        case 4:
            int val4, ele2;
            cout << "Enter the value to insert : ";
            cin >> val4;
            cout << "Enter the element to insert after : ";
            cin >> ele2;
            l.insertafter(val4, ele2);
            goto start;
            break;
        default:
            goto start;
            break;
        }

    case 3:
        int a2;
        cout << "\nDeletion :\n1.Delete at beginning\n2.Delete at End\n3.Delete before element\n4.Delete after element\n5.Main Menu\n : ";
        cin >> a2;
        switch (a2)
        {
        case 1:
            l.idel(0);
            print(l);
            goto start;
            break;
        case 2:
            l.idel(l.len() - 1);
            print(l);
            goto start;
            break;
        case 3:
            int val5;
            cout << "Enter the element to delete before : ";
            cin >> val5;
            l.delbefore(val5);
            goto start;
            break;
        case 4:

            int val6;
            cout << "Enter the element to delete after : ";
            cin >> val6;
            l.delafter(val6);
            goto start;
            break;
        default:
            goto start;
            break;
        }
        goto start;
        break;
    case 4:
        int a3;
        cout << "Enter the element to search";
        cin >> a3;
        int c;
        c = l.search(a3);
        if (c == -1)
        {
            cout << "Not in Array";
            goto start;
        }
        else
        {
            cout << c << "\n";
            goto start;
        }
        break;
    case 5:
        cout << l.len();
        goto start;
        break;
    case 6:
        return 0;
    default:
        goto start;
        break;
    }

    return 0;
}