#include <iostream>

using namespace std;

class Node
{
public:
    void *val;
    Node *next;

    Node()
    {
        val = malloc(4);
        next = NULL;
    }

    Node(string data)
    {
        val = malloc(sizeof(data));
        next = NULL;
    }
    Node(int data)
    {
        val = malloc(sizeof(data));
        next = NULL;
    }
};

int main()
{
    Node *a = new Node("hey");
    cout << (string *)a->val;
    return 0;
}