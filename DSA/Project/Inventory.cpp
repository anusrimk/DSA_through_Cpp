// Array:
//  Inventory Management System:
//    - Design an inventory management system for a any small business. Use
//      an array to store the quantity of different products in stock. Implement
//      functionalities to add products (quantity of product), update quantities,
//      display the current inventory.
//    - Perform inventory management functionalities and alert when a product
//      is running low on stock.
// Note:
//    - Each element in the array represents a different product.
//    - Allow the addition and removal of products dynamically.


#include <iostream>

using namespace std;

struct Details{
    string prodname;
    int qty;
};

class Inventory{
    public:
        Details * arr;
        int size;
        int n;

        Inventory(){
            arr = (Details *) malloc(sizeof(Details));
            size = 1;
            n = 0;
        }

        void resize(){
            size += 2; 
            Details* newArr = (Details*)realloc(arr, size * sizeof(Details)); 
            arr = newArr; 
        }

        void add(string name , int qty){
            if(n >= size){
                resize();
            }
            arr[n].prodname = name;
            arr[n].qty = qty;
            n++;
        }

        void update(int index){
            --index;
            cout<<"Enter the product qty : ";
            cin>>arr[index].qty;
            return;
        }

        void remove(int index){
            --index;
            for(int i = index ; i < n ; i++){
                arr[index] = arr[index+1];
            }
            n--;

        }

        void insert(int index , string name , int qty){
            if(index > n){
                index = n;
            }

            if(n >= size){
                resize();
            }

            for (int i = n ; i > index ; i--){
                arr[i] = arr[i-1];
            }

            arr[index].prodname = name;
            arr[index].qty = qty;
            n++;

            
        }

        void pop(){
            n--;
        }

        Details &operator[](int i) {
            if (i < 0 || i >= n) {
                cout << "Index out of bounds." << endl;
                exit(EXIT_FAILURE);
            }
            return arr[i];
        }

};

void print(Inventory a){
    for(int i = 0 ; i < a.n ; i++){
        cout<<"\n"<<i+1<<" > \n";
        cout<<"    Name : "<<a.arr[i].prodname;
        cout<<"\n    Qty : "<<a.arr[i].qty;

    }
    cout<<"\n\n";
}
int main(){

    Inventory n;

    

    print(n);

    
    return 0;
}