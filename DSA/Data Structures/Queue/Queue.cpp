// #include <iostream>

// using namespace std;

// class Queue
// {
// public:
//     int front;
//     int rear;
//     int *arr;
//     int n;

//     Queue()
//     {
//         n = 15;
//         front = -1;
//         rear = -1;
//         arr = (int *)calloc(n, sizeof(int));
//     }
//     Queue(int n)
//     {
//         this->n = n;
//         arr = (int *)calloc(n, sizeof(int));
//         front = -1;
//         rear = -1;
//     }

//     int peek()
//     {
//         return arr[front];
//     }

//     int dequeue()
//     {

//         front++;
//         return arr[front - 1];
//     }
//     void enqueue(int val)
//     {
//         if (rear == n - 1)
//         {
//             cout << "OVERFLOW";
//         }
//         rear++;
//         arr[rear] = val;
//     }
// };

// int main()
// {
//     Queue q;

//     q.enqueue(10);
//     q.enqueue(20);
//     q.enqueue(30);
//     q.enqueue(40);
//     q.dequeue();
//     cout << q.peek();

//     return 0;
// }
#include <iostream>
using namespace std;

class manas {
private:
    static const int MAX_SIZE = 100;
    int front, rear;
    int arr[MAX_SIZE];
public:
    manas() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }
        if (isEmpty())
            front = rear = 0;
        else
            rear++;
        arr[rear] = value;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        else if (front == rear)
            front = rear = -1;
        else
            front++;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No element to peek.\n";
            return -1;
        }
        return arr[front];
    }
};

int main() {
    manas q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Front element: " << q.peek() << endl;
    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl;
    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl;
    q.enqueue(10);
    cout << "Front element after enqueue: " << q.peek() << endl;
    q.dequeue();
    cout << "Front element after dequeue: " << q.peek() << endl;
    return 0;
}