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

        int search(int val){
            Node * temp = head;
            int index = 0;

            while (temp != NULL){
                if(temp->val == val){
                    return index;
                }
                temp = temp->next;
                index++;
            }
            return -1;
        }

        void valinsert(int val , int ele){//Value to insert before ele
            int index = search(ele);
            insert(index , val);
            return;
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
                if(count == index-1){
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

        void del(int val)
        {
            Node * temp = head;

            while(temp != NULL){
                if(temp->next->val == val){
                    temp->next = temp->next->next;
                    n-=1;
                }
                temp = temp->next;
            }

        }

        void idel(int index){
            Node * temp = head;
            int a = 0;

            while(temp != NULL){
                if(a == index){
                    temp->next = temp->next->next;
                    n-=1;
                }
                a++;
                temp = temp->next;
            }
            return;
        }

        void pop(){

            Node *curr = head;
            if(n == 1){
                n = 0;
                head = NULL;
            }

            while(curr->next != NULL){
                curr = curr->next;

                if(curr->next == NULL){
                    n -= 1;
                    break;
                }
                
            }
        

        }

        // int &operator[](int i) {
        //     if (i < 0 || i >= n) {
        //         cout << "Index out of bounds." << endl;
        //         exit(EXIT_FAILURE);
        //     }
            
        //     Node*temp = head;
        //     int a = 0;

        //     while(temp->next != NULL){
        //         temp = temp->next;
        //         if(a == i){
        //             return (temp->val);
        //         }
        //         a++;
                
        //     }
        
        //     return a;
        // }

        void rhead(){
            Node * temp = head;

            head = temp->next;
            n-=1;
        }
        int len(){
            return n;
        }

        ~Linkedlist(){
            free(head);
        }
        

};

void print(Linkedlist a){
    Node * temp = a.head;

    cout<<"[";
    while (temp != NULL){
        if(temp->next == NULL){
            cout<<temp->val<<"]";
            break;
        }
        cout<<temp->val<<" , ";
        temp = temp->next;
    }
}



int main(){

    Linkedlist l;
    int choice,val = 0,index = 0,choice2 = 0,ele = 0;

    start:
    cout<<"--------------LINKED LIST-------------------";
    cout<<"\n1.Display Linked list \n2.Insertion\n3.Deletion\n4.Search\n5.Length\n6.Exit\n : ";
    cin>>choice;
    
    switch(choice){
        case 1:
            print(l);
            goto start;
            break;
        case 2:
            cout<<"\n\nInsertion :\n1.Insert at beginning\n2.Insert at end(appending)\n3.Insert before element\n4.Insert after element\n5.Main menu\n : ";
            cin>>choice2;
            switch(choice2){
                case 1:
                    cout<<"Enter the value to insert at start : ";
                    cin>>val;
                    l.insert(0,val);
                    goto start;
                    break;
                case 2:
                    cout<<"Enter the value to insert at end : ";
                    cin>>val;
                    l.append(val);
                    goto start;
                    break;
                case 3:
                    cout<<"Enter the value to insert before element : ";
                    cin>>val;
                    cout<<"Enter the element to insert before : ";
                    cin>>ele;

                    index = l.search(ele);
                    if(index == -1){
                        cout<<"Not in the Linked list ";
                        goto start;
                    }
                    l.insert(index,val);
                    goto start;
                    break;
                case 4:
                    cout<<"Enter the value to insert after element : ";
                    cin>>val;
                    cout<<"Enter the element to insert after : ";
                    cin>>ele;

                    index = l.search(ele);
                    if(index == -1){
                        cout<<"Not in the Linked list ";
                        goto start;
                    }
                    l.insert(index+1,val);
                    goto start;
                    break;
                default:
                    goto start;
                    break;
            }
            break;
        case 3:
            cout<<"\n\nDeletion :\n1.Delete at beginning\n2.Delete at End\n3.Delete before element\n4.Delete after element\n5.Delete the first occurence of val \n6.Main Menu\n : ";
            cin>>choice2;
            switch(choice2){
                case 1:
                    l.rhead();
                    print(l);
                    goto start;
                    break;
                case 2:
                    index = l.len();
                    l.idel(index-1);
                    goto start;
                    break;
                case 3:
                    cout<<"Enter the element to delete before : ";
                    cin>>ele;
                    index = l.search(ele);
                    l.idel(index-1);
                    goto start;
                    break;
                case 4:
                    cout<<"Enter the element to delete after : ";
                    cin>>ele;
                    index = l.search(ele);
                    l.idel(index+1);
                    goto start;
                    break;
                case 5:
                    cout<<"Enter the value to delete : ";
                    cin>>val;
                    l.del(val);
                    goto start;
                    break;
                
                default:
                    goto start;
                    break;
            }

            break;
        case 4:
            cout<<"Enter the value to search : ";
            cin>>val;
            cout<<l.search(val)<<"\n";
            goto start;
            break;
        case 5:
            cout<<l.len();
            goto start;
            break;
        case 6:
            return 0;
            break;
        default:
            goto start;
            break;
    }

    return 0;
}