#include <iostream>

using namespace std;

class Node{
    public:
        string name;
        string author;
        Node* next;

        Node(){
            name = "";
            author = "";
            next = NULL;
        }
        Node(string n , string a){
            name = n;
            author = a;
            next = NULL;
        }
};


class Library{
    public:
        Node* head; 
        int n;


        Library(){
            head = NULL;
            n = 0;
        }

        void add(string name , string author){
            Node * temp = new Node();

            temp->author = author;
            temp->name = name;

            if(n == 0){
                head = temp;

            }
            else{
                Node * curr = head;
                while(curr->next != NULL){
                    curr = curr->next;
                }

                curr->next = temp;
            }
            n++;
        }

        void remove(int index){
            int i = 1;
            Node * prev = head;
            for(Node * curr = head ; curr != NULL; curr=curr->next){
                if(i == index){
                    prev->next = curr->next;
                    delete curr;
                    n--;
                    break;
                }
                else{
                    prev = curr;
                    i++;
                }
            }
        }

        void search(string name){
            for(Node * curr = head ; curr != NULL; curr=curr->next){
                if(curr->name == name){
                    cout<<"    Name : "<<curr->name;
                    cout<<"\n    Author : "<<curr->author;
                    break;
                }

            }

           

            
        }


        void list(string author){
            cout<<"All the books' written by "<<author<<" : ";
            int i = 1;
            for(Node * curr = head ; curr != NULL; curr=curr->next){
                if(curr->author == author){
                    cout<<"\n"<<i++<<" > \n";
                    cout<<"    Name : "<<curr->name;
                    cout<<"\n    Author : "<<curr->author;
                }
            }
        }


};




void print(Library l){
    int i = 1;
    for(Node * curr = l.head ; curr != NULL; curr=curr->next){
        cout<<"\n"<<i++<<" > \n";
        cout<<"    Name : "<<curr->name;
        cout<<"\n    Author : "<<curr->author;
    }
    cout<<"\n\n";
}

int main(){

    cout<<"---------------LIBRARY CATALOG---------------";

    Library l ;

    




    return 0;
}