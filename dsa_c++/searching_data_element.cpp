#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    
};

int main() {
    Node* start;
    
    Node* n1 = new Node;
    start = n1;
    n1->data = 30;
    n1->next = NULL;

    Node* n2 = new Node;
    n1->next = n2;
    n2->data = 40;
    n2->next = NULL;

    Node* n3 = new Node;
    n2->next = n3;
    n3->data = 50;
    n3->next = NULL;

    Node* n4 = new Node;
    n3->next = n4;
    n4->data = 60;
    n4->next = NULL;

    Node* current = start;
    int val = 50;
    Node* pos = nullptr;  

    while (current != NULL) {
        if (val == current->data) {
            pos = current;
            break;  
        } else {
            current = current->next;
        }
    }

    if (pos == current) {
        cout << "Element found : " << pos << endl;
    } else {
        cout << "Element not found" << endl;
    }

    return 0;
}