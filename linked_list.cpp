#include <iostream>
using namespace std;

class Node  
{  
public: 
    int data;  
    Node *next;  
};  

int main() {

    Node *n1 = new Node;
    n1->data = 1;
    n1->next = nullptr;

    Node *n2 = new Node;
    n2->data = 2;
    n2->next = nullptr;
    
    Node *n3 = new Node;
    n3->data = 3;
    n3->next = nullptr;
    n1->next = n2;
    n2->next = n3;

    Node *Start = n1;
    cout<<n1<<endl;


    delete n1;
    delete n2;
    delete n3;
    return 0;
}
 
//wap to calculate and display the sum and product of diagonal elements if 2d arra