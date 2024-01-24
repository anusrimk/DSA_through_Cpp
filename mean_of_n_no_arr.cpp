// to write a c++ program and take user input of n numbers and find the mean of n numbers numbers
#include <iostream>
using namespace std;

int main(){
    int n,sum=0,i;
    cout<<"Enter the number upto which you want the mean: ";
    cin>>n;
    float mean;
    int arr[n];
    for(i=1; i<=n; i++){
        cout<<"Enter element: ";
        cin>>arr[i];
    }
    for(i=0; i<=n; i++){
        sum+=arr[i];
    }
mean=sum/n;
cout<<"Mean: "<<mean;
}
