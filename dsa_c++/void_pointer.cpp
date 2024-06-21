#include <iostream>
using namespace std;
int main(){
    /*
    void *ptr;
    int a=5;
    ptr= &a;
    cout<<a<<endl;
    cout<<*(int*)ptr<<endl;
    cout<<ptr;*/ 

    //char *ptr;  // character pointer
    void *ptr;
    char c= 'I';
    ptr= &c;
    cout<<c<<endl;
    cout<<ptr; 

    //cout<<ptr<<endl; this wont print the value because it cant be type casted
    // we have to change the char point to void and then type cast it
}