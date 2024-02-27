#include <iostream>

using namespace std;

class Node{
    public:
        int val;
        Node* next;

        Node(){
            this->val = 0;
            this->next = NULL;
        }

        Node(int data){
            this->val = data;
            this->next = NULL;

        }
};
class Linkedlist 
{
    public:
        Node* head;
        int n;

        Linkedlist(){
            this->head = NULL;
            n = 0;

        }

        void append(int a){
            Node * temp = new Node(a);
            if(n == 0){
                this->head = temp;
                this->n += 1;
            }
            else{
                Node * temp1 = head;

                while (temp1->next != NULL){
                    temp1 = temp1->next;
                };
                temp1->next = temp;
                this -> n += 1;
            }
        }
        Node* gethead(){
            return head;
        }
        void insert(int index , int val){
            int count = 0;
            if(index == 0){
                Node * temp = (Node*) malloc(sizeof(Node));
                if(n != 0){
                    temp->val = val;
                    temp->next = head;
                    head = temp;
                    n += 1;
                    return;
                }
                else{
                    temp->val = val;
                    temp->next = NULL;
                    head = temp;
                    n += 1;
                    return;
                }
                
            }

            if(index > n){
                index = n;
            }
            Node * curr = head;

            while(curr != NULL){
                if(count == index){
                    Node * temp = (Node * ) malloc(sizeof(Node));
                    temp->val = val;
                    temp->next = curr->next;
                    curr->next = temp;
                    n += 1;

                }
                curr = curr->next;
                count+=1;
            }
            
        }
        int len(){
            return n;
        }

        

};



int main(){

    Linkedlist l;

    l.insert(0,1);

    l.insert(0,2);
    l.append(4);
    Node * temp = l.gethead();

    while (temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next ;
    }


    return 0;
}