// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int val;
//     Node *next;

//     Node()
//     {
//         val = 0;
//         next = NULL;
//     }

//     Node(int val)
//     {
//         this->val = val;
//         next = NULL;
//     }
// };

// class Linkedlist
// {
// public:
//     Node *head;
//     int n;

//     Linkedlist()
//     {
//         head = NULL;
//         n = 0;
//     }

//     void append(int val)
//     {
//         Node *temp = new Node(val);
//         if (n == 0)
//         {
//             head = temp;
//             temp->next = head;
//         }
//         else
//         {
//             Node *curr = head;
//             while (curr->next != head)
//             {
//                 curr = curr->next;
//             }
//             temp->next = curr->next;
//             curr->next = temp;
//         }
//         n++;
//     }

//     void insert(int val, int ele) // Value to be inserted after element
//     {
//         Node *temp = new Node(val);
//         Node *curr = head;

//         while (curr->next != head)
//         {
//             if (curr->val == ele)
//             {
//                 break;
//             }
//             curr = curr->next;
//         }

//         temp->next = curr->next;
//         curr->next = temp;
//         n++;
//     }
//     void pop()
//     {
//         if (n == 0)
//         {
//             return;
//         }
//         else
//         {
//             if (n == 1)
//             {
//                 head = NULL;
//             }
//             else
//             {
//                 Node *curr = head;
//                 while (curr->next->next != head)
//                 {
//                     curr = curr->next;
//                 }

//                 curr->next = head;
//             }
//         }
//         n--;
//         return;
//     }
//     bool contains(int val)
//     {
//         Node *curr = head;

//         while (curr != NULL)
//         {
//             if (curr->val == val)
//             {
//                 return true;
//             }
//             curr = curr->next;
//         }

//         return false;
//     }
//     void remove(int val)
//     {
//         Node *temp = head;
//         if (temp->val == val)
//         {
//             head = head->next;
//             n--;
//             return;
//         }
//         Node *prev = head;
//         while (temp->val != val)
//         {
//             prev = temp;
//             temp = temp->next;
//         }
//         prev->next = temp->next;
//         n--;
//         return;
//     }

//     int len()
//     {
//         return n;
//     }
// };

// void print(Linkedlist a)
// {
//     cout << "[ ";
//     Node *curr = a.head;
//     do
//     {
//         if (curr->next == a.head)
//         {
//             cout << curr->val << " ]\n";
//             return;
//         }
//         cout << curr->val << " , ";

//         curr = curr->next;

//     } while (curr != a.head);
// }

// int main()
// {
//     Linkedlist l;

//     l.append(10);
//     l.append(10);
//     l.append(10);
//     l.append(10);
//     l.append(20);
//     l.remove(20);
//     print(l);
//     return 0;
// }

#include <iostream>
using namespace std;

// Node structure for circular linked list
struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Function to check if the list is empty
    bool isEmpty() {
        return head == nullptr;
    }

    // Function to insert a node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        if (isEmpty()) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
        cout << "Node with value " << value << " inserted at the beginning." << endl;
    }

    // Function to display the linked list
    void display() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }
        Node* temp = head;
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Function to delete the first node
    void deleteFirstNode() {
        if (isEmpty()) {
            cout << "List is empty. No node to delete." << endl;
            return;
        }
        if (head->next == head) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            delete head;
            head = temp->next;
        }
        cout << "First node deleted successfully." << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int choice, value;

    do {
        cout << "\nMenu for Circular Linked List Operations" << endl;
        cout << "1. Insert node at the beginning" << endl;
        cout << "2. Delete first node" << endl;
        cout << "3. Display the list" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert at the beginning: ";
                cin >> value;
                cll.insertAtBeginning(value);
                break;
            case 2:
                cll.deleteFirstNode();
                break;
            case 3:
                cll.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}