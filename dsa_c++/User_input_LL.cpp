#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to enqueue (insert) an element into the queue
    void enqueue(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to dequeue (delete) an element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Unable to dequeue." << endl;
        } else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Function to display the elements of the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            Node* current = front;
            cout << "Queue elements: ";
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    // Function to sort the elements of the queue (Bubble Sort)
    void sort() {
        if (isEmpty() || front->next == nullptr) {
            return; // Queue has 0 or 1 element, no sorting needed
        }

        Node* current;
        Node* nextNode;
        int temp;

        for (current = front; current != nullptr; current = current->next) {
            for (nextNode = current->next; nextNode != nullptr; nextNode = nextNode->next) {
                if (current->data > nextNode->data) {
                    temp = current->data;
                    current->data = nextNode->data;
                    nextNode->data = temp;
                }
            }
        }
    }
};

int main() {
    Queue q;
    int num_elements;

    cout << "Enter the number of elements: ";
    cin >> num_elements;

    for (int i = 0; i < num_elements; ++i) {
        int element;
        cout << "Enter element " << i+1 << ": ";
        cin >> element;
        q.enqueue(element);
    }

    cout << "Original queue:" << endl;
    q.display();

    q.sort();
    cout << "Sorted queue:" << endl;
    q.display();

    return 0;
}
