// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;
// };

// void printNodes(Node* start) {
//     Node* ptr = start;

//     while (ptr != NULL) {
//         cout << ptr->data << " ";
//         ptr = ptr->next;
//     }

//     cout << endl;
// }

// int main() {
//     Node* start;
//     int temp;
//     int num;
//     cout<<"Enter the number you want to delete: ";
//     cin>>num;

//     Node* n1 = new Node;
//     start = n1;
//     n1->data = 30;
//     n1->next = NULL;

//     Node* n2 = new Node;
//     n1->next = n2;
//     n2->data = 40;
//     n2->next = NULL;

//     Node* n3 = new Node;
//     n2->next = n3;
//     n3->data = 50;
//     n3->next = NULL;

//     Node* n4 = new Node;
//     n3->next = n4;
//     n4->data = 60;
//     n4->next = NULL;

//     Node* n5 = new Node;
//     n4->next = n5;
//     n5->data = 70;
//     n5->next = NULL;

//     Node* ptr = start;
//     Node* preptr = ptr;
//     Node*preptr1 = preptr;

//     if (start == NULL)
//     {
//         cout<<"underflow";
//     }
//     ptr = start;
//     preptr = ptr;
//     preptr1=preptr;

//     while (ptr->data !=num)
//     {
//         preptr1=preptr;
//         preptr = ptr;
//         ptr = ptr->next;
//     }

//     preptr1->next = ptr->next;
//     delete preptr;
    
//     cout << "Nodes before deletion: ";
//     printNodes(start);
    
//     return 0;

// }

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
    int temp;
    int n;
    


    Node* n1 = new Node;
    start = n1;
    n1->data = 30;
    n1->next = NULL;

    Node* n2 = new Node;
    n1->next = n2;
    n2->data = 40;
    

    Node* n3 = new Node;
    n2->next = n3;
    n3->data = 50;


    Node* n4 = new Node;
    n3->next = n4;
    

     Node* n5 = new Node;
    n4->next = n5;
    n5->data = 70;
    n5->next = NULL;


    cout<<"enter the value :"<<endl;
    cin>>n;

    Node* ptr = start;
    Node* preptr = ptr;
    Node* preptr1 = preptr;

    if (start == NULL) {
        cout << "overflow";
    }
    ptr = start;
    preptr = ptr;
    preptr1 = preptr;

    while (ptr->next->data != n) {
        preptr = preptr1;
        preptr1 = ptr;
        ptr = ptr->next;
    }
    preptr1->next = ptr->next;
    delete ptr;

    cout << "Nodes after deletion: ";
    printNodes(start);

    return 0;
}