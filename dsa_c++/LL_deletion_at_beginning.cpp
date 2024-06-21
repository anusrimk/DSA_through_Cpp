#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};


void printNodes(Node* start) {
    Node* ptr = start;

    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }

    cout << endl;
}

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
     Node* ptr = start;

    if(start==NULL)
    {
        cout<<"underflow"<<endl;
    
    }
    else{
        ptr = start;
        start = start->next;
        delete ptr; 
    }

    cout << "Nodes before deletion: ";
    printNodes(start);
    cout<<endl;

    return 0;



}