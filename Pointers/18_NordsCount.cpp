#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
int main()
{

    Node *start;
    Node *n1 =(Node *)malloc(sizeof(Node));
    start = n1;
    n1->data = 19;
    n1->next = NULL;

    Node *n2=new Node();
    n1->next=n2;
    n2->data=23;
    n2->next=NULL;


    Node *n3=new Node();
    n2->next=n3;
    n3->data=38;
    n3->next=NULL;

    // cout<<n1->data<<" "<<n2->data<<" "<<n3->data;
    
    //Traversing  the linkedlist throught loop..

    int count = 0;
    Node *ptr=start;

    int i=0;
    while(ptr!=NULL)
    {
        count++;
        cout<<ptr->data<<endl;
        ptr=ptr->next;
        i++;
    }
    
    cout<<"Total Nodes are: "<<count;
}