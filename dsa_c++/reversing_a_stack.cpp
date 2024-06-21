//REVERSE AN ARRAY STACK IN C++ USING 2 ARRAYS

// #include <iostream>
// using namespace std;

// class RevArrayStack {
// private:
//     int top;
//     int capacity;
//     int* array;

// public:
//     RevArrayStack(unsigned cap) {
//         capacity = cap;
//         top = -1;
//         array = new int[capacity];
//     }

//     bool isFull() {
//         return top == capacity - 1;
//     }

//     bool isEmpty() {
//         return top == -1;
//     }

//     void push(int item) {
//         if (isFull()) {
//             cout << "Stack Overflow\n";
//             return;
//         }
//         else{
//         array[++top] = item;
//         }
//     }

//     int pop() {
//         if (isEmpty()) {
//             cout << "Underflow\n";
//             return -1;
//         }
//         return array[top--];
//     }
    
//     void reverseArray(int arr[], int n) {
//         for (int i = 0; i < n; i++) {
//             push(arr[i]);
//         }

//         for (int i = 0; i < n; i++) {
//             arr[i] = pop();
//         }
//     }
// };

// int main() {
//     int N;
//     cout<<"Enter the size of array:";
//     cin>>N;
//     int arr[N];
//    // int N = sizeof(arr) / sizeof(arr[0]);
//     for (int i=0;i<N;i++)
//     {
//             cout<<"Enter the value of ("<<i<<"): ";
//             cin>>arr[i];
//     }
//     RevArrayStack revStack(N);
//     revStack.reverseArray(arr, N);

//     for (int i = 0; i < N; i++) {
//         cout << arr[i] << " ";
//     }

//     return 0;
// }

//REVERSE A STACK USING LINKED LIST


#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class RevLinkedListStack {
private:
    Node* top;

public:
    RevLinkedListStack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int item) {
        Node* newNode = new Node(item);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Underflow\n";
            return -1; 
        }

        Node* temp = top;
        int poppedItem = temp->data;
        top = top->next;
        delete temp;

        return poppedItem;
    }

    void reverseStack() {
        Node* prev = nullptr;
        Node* current = top;
        Node* nextNode = nullptr;

        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        top = prev;
    }
};

int main() {
    RevLinkedListStack revStack;

    int numValues;
    cout << "Enter the number of values for the stack: ";
    cin >> numValues;

    cout << "Enter the values for the stack:\n";
    for (int i = 0; i < numValues; ++i) {
        int value;
        cin >> value;
        revStack.push(value);
    }

    revStack.reverseStack();

    cout << "Reversed Stack Values:\n";
    while (!revStack.isEmpty()) {
        cout << revStack.pop() << " ";
    }

    return 0;
}
