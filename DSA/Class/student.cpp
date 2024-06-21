#include <iostream>
#include<algorithm>

using namespace std;


int length(int arr[]){
    int z = 0;
    while(arr[z] != -1){
        z+=1;
    }
    return z;
}

void insert(int arr[], int ele){

    for(int i = 0 ; i < length(arr) ; i++){
        if(arr[i] > ele){
            for (int j = length(arr) ; j > i ; j--){
                arr[j] = arr[j-1];
            }
            arr[i] = ele;
            break;
        }
        else{
            continue;
        }
    }
}
int main(){
    int n , element;

    cout<<"Enter the number of marks : ";
    cin>>n;

    int arr[n+10] ;
    fill_n(arr,n+10,-1);

    for (int i = 0 ; i < n ; i ++){
        cout<<"Enter the marks for "<<i+1<<" : ";
        cin>>arr[i];
    }

    for (int i = 0 ; i < n ;i++){
        for (int j = i+1 ; j < n ; j++){
            if(arr[j] < arr[i]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    for (int i = 0 ; i < n ; i ++){
        cout<<arr[i]<<" ";
    }
    
    cout<<"\nEnter the element to enter in the array ";
    cin>>element;

    insert(arr,element);

    for (int i = 0 ; i < length(arr) ; i ++){
        cout<<arr[i]<<" ";
    }

    return 0;
}