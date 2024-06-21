#include <iostream>
#include<algorithm>

using namespace std;

void insert(int arr[] , int index , int e ){
    int n = 0;

    while(arr[n] != -1){
        n += 1;
    }
    //Making sure the inserting index remains under range (if more than size it will insert at last index)
    if(index>n)
    {
        index = n;
    }
    //Shifting array
    for (int i = n  ; i >= index+1 ; i--)
    {
        arr[i] = arr[i-1];
    }
    //Changing the element to the required element
    arr[index] = e;
}

int search(int arr[] , int e ){
    int n = 0;

    while(arr[n] != -1){
        n += 1;
    }

    for (int i = 0 ; i < n ; i++){
        if(arr[i] == e){
            return i;
        }
    }
    return -1;
}

void inserte(int arr[],int e , int element){
    int i = search(arr , e);

    insert(arr , i+1 , element);
}

void delete_i(int arr[], int i){
    int n = 0;

    while(arr[n] != -1){
        n += 1;
    }
    if(i > n){
        cout<<"Error Index out of range";
        return;
    }
    for(int x = i ; x < n ; x++){
        arr[x] = arr[x+1];
    }
}

void delete_e(int arr[], int e){
    int n = 0;

    while(arr[n] != -1){
        n += 1;
    }
    int i = search(arr , e);
    if(i > n){
        cout<<"Error Index out of range";
        return;
    }
    for(int x = i ; x < n ; x++){
        arr[x] = arr[x+1];
    }
}



int lengthof(int arr[]){
    int n = 0;

    while(arr[n] != -1){
        n += 1;
    }
    return n;
}

int main(){
    
    int n , a , e , element;

    //Asking for size
    cout<<"Enter the number of element you want to enter : ";
    cin>>n;

    //Initializing array for more than one size (as we have to insert one element)
    int arr[100] = {};
    fill_n(arr,100,-1);

    //Getting data for array (Upto n elements)
    for (int i = 0 ; i < n ; i++){
        cout<<"Enter "<<i+1<<" element : ";
        cin>>arr[i];
    }

    //Displaying entered array
    for (int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }


    int choice , element , index;
    cout<<"Enter the Function to perform :\n1.Insert (using index)]\n2.Insert (After element)\n3.Search (using element)\n4.Deletion (using element)\n5. Deletion (using index)\n6.No. of elements in array\n";
    cin>>choice;
    switch(choice){
        case 1:
            cout<<"Enter the element to insert : ";
            cin>>element;
            cout<<"Enter the index to enter after : ";
            cin>>index;

            break;
        default:
            break;
            
    }
    cout<<"\nEnter the element you want to add next to : ";
    cin>>e;
    cout<<"Enter the element you want to add : ";
    cin>>element;

    inserte(arr,e,element);

    for (int i = 0 ; i < lengthof(arr) ; i++){
        cout<<arr[i]<<" ";
    }
    
    

    return 0;
}