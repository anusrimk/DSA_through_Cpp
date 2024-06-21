#include <iostream>
#include <unordered_map>

using namespace std;
class Node
{
public:
    int val;
    Node *next;

    Node()
    {
        this->val = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

class Linkedlist
{
public:
    Node *head;
    int n;
    unordered_map<int, int &> indexlist;

    Linkedlist()
    {
        this->head = NULL;
        n = 0;
    }

    void append(int a)
    {
        Node *temp = new Node(a);
        if (n == 0)
        {
            this->head = temp;
            indexlist.insert({n, temp->val});
            this->n += 1;
        }
        else
        {
            Node *temp1 = head;

            while (temp1->next != NULL)
            {
                temp1 = temp1->next;
            };
            temp1->next = temp;
            indexlist.insert({n, temp->val});
            this->n += 1;
        }
    }

    Node *gethead()
    {
        return head;
    }

    int search(int val)
    {
        Node *temp = head;
        int index = 0;

        while (temp != NULL)
        {
            if (temp->val == val)
            {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }

    void valinsert(int val, int ele)
    { // Value to insert before ele
        int index = search(ele);
        insert(index, val);
        return;
    }

    void insert(int index, int val)
    {
        int count = 0;
        if (index == 0)
        {
            Node *temp = (Node *)malloc(sizeof(Node));
            if (n != 0)
            {
                temp->val = val;
                temp->next = head;
                head = temp;
                indexlist.insert({n, temp->val});
                n += 1;
                return;
            }
            else
            {
                temp->val = val;
                temp->next = NULL;
                head = temp;
                indexlist.insert({n, temp->val});
                n += 1;
                return;
            }
        }

        if (index > n)
        {
            index = n;
        }
        Node *curr = head;

        while (curr != NULL)
        {
            if (count == index - 1)
            {
                Node *temp = (Node *)malloc(sizeof(Node));
                temp->val = val;
                temp->next = curr->next;
                curr->next = temp;
                indexlist.insert({n, temp->val});
                n += 1;
            }
            curr = curr->next;
            count += 1;
        }
    }

    void del(int val)
    {
        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->next->val == val)
            {
                temp->next = temp->next->next;

                n -= 1;
            }
            temp = temp->next;
        }
    }

    void idel(int index)
    {
        Node *temp = head;
        int a = 0;

        while (temp != NULL)
        {
            if (a == index)
            {
                temp->next = temp->next->next;
                n -= 1;
            }
            a++;
            temp = temp->next;
        }
        return;
    }

    void pop()
    {

        Node *curr = head;
        if (n == 1)
        {
            n = 0;
            head = NULL;
        }

        while (curr->next != NULL)
        {
            curr = curr->next;

            if (curr->next == NULL)
            {
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

    void rhead()
    {
        Node *temp = head;

        head = temp->next;
        n -= 1;
    }
    int len()
    {
        return n;
    }
    int &operator[](int i)
    {
        if (i < 0 || i >= n)
        {
            cout << "Index out of bounds." << endl;
            exit(EXIT_FAILURE);
        }
        return indexlist[i];
    }
    ~Linkedlist()
    {
        free(head);
    }
};

void print(Linkedlist a)
{
    Node *temp = a.head;

    cout << "[";
    while (temp != NULL)
    {
        if (temp->next == NULL)
        {
            cout << temp->val << "]";
            break;
        }
        cout << temp->val << " , ";
        temp = temp->next;
    }
}

int main()
{

    Linkedlist l;

    l.append(10);
    print(l);
    return 0;
}