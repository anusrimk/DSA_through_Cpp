#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node()
    {
        val = 0;
        next = NULL;
    }

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

class Queue
{
public:
    Node *head;
    Node *tail;

    void enqueue(int val)
    {
        Node *temp = new Node(val);

        tail->next = temp;
        tail = temp;
    }

    int dequeue()
    {
        int a = head->val;
        head = head->next;
        return a;
    }

    int peek()
    {
        return head->val;
    }
};

int main()
{

    return 0;
}