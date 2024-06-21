#include <iostream>

using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int val = 0, Node *next = NULL)
    {
        this->val = val;
        this->next = next;
    }
};

class LinkedList
{

public:
    Node *head;
    int n;

    LinkedList()
    {
        this->head = NULL;
        this->n = 0;
    }
};

int main()
{
    LinkedList l;

    return 0;
}