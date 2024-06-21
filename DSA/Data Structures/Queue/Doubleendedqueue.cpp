#include <iostream>
using namespace std;

class Queue
{
public:
    int front;
    int rear;
    int n;
    int *arr;

    Queue()
    {
        n = 15;
        front = -1;
        rear = -1;
        arr = (int *)calloc(n, sizeof(int));
    }
    Queue(int n)
    {
        this->n = n;
        arr = (int *)calloc(n, sizeof(int));
        front = -1;
        rear = -1;
    }
};

int main()
{

    return 0;
}