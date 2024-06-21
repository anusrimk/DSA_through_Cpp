#include <iostream>

using namespace std;


class Stack{
    private:
        int top;
        int arr[15];

    public:
        Stack(){
            top = -1;
        }

        int pop(){
            if(top == -1){
                return -1;
            }
            int temp = arr[top];
            arr[top] = -1;
            top--;
            return temp;
        
        }

        int peek(){
            return arr[top];
        }

        void push(int a){
            if(top == 14)
            { 
                return;
            }
            top++;
            arr[top] = a;
        }

};

int main(){
    
    return 0;
}