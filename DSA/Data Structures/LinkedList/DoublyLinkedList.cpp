#include <iostream>

using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node()
    {
        val = 0;
        prev = NULL;
        next = NULL;
    }

    Node(int val)
    {
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;
    int n;

    LinkedList()
    {
        head = NULL;
        n = 0;
        tail = NULL;
    }

    void append(int val)
    {
        Node *temp = new Node(val);
        if (n == 0)
        {
            head = temp;
        }
        else
        {
            Node *curr = head;

            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            temp->prev = curr;
            curr->next = temp;
            tail = temp;
        }
        n++;
    }
    bool contains(int val)
    {
        Node *curr = head;

        while (curr)
        {
            if (curr->val == val)
            {
                return true;
            }
            curr = curr->next;
        }

        return false;
    }

    void insert(int val, int ele)
    {
        Node *curr = head;
        Node *temp = new Node(val);
        while (curr->val != ele)
        {
            curr = curr->next;
        }
        Node *ahead = curr->next;

        if (ahead != NULL)
        {
            ahead->prev = temp;
        }

        temp->next = curr->next;
        curr->next = temp;
        if (temp->next == NULL)
        {
            tail = temp;
        }
        n++;
        return;
    }
    void pop()
    {
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        n--;
        Node *pr = curr->prev;
        pr->next = NULL;
        tail = pr;
        delete curr;
    }

    void remove(int val)
    {
        Node *curr = head;
        if (curr->val == val)
        {
            head = head->next;
            return;
        }
        while (curr->val != val)
        {
            curr = curr->next;
        }

        Node *pr = curr->prev;
        pr->next = curr->next;
        pr->next->prev = pr;
        delete curr;
        n--;
    }
};

void print(LinkedList a)
{
    cout << "[ ";
    for (Node *temp = a.head; temp != NULL; temp = temp->next)
    {
        if (temp->next == NULL)
        {
            cout << temp->val << " ]\n";
            return;
        }
        cout << temp->val << " , ";
    }
}
int main()
{
    LinkedList l;
    l.append(10);
    l.append(20);
    l.append(10);
    l.append(20);
    l.append(30);
    l.insert(10, 30);
    print(l);

    return 0;
}