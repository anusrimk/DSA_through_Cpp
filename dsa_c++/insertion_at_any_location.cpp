//to insert value at any location

#include<iostream>
using namespace std;
void insertion_at_any_location(int pos,int n,int arr[],int value)
{   
    for(int i = n-1;i>=pos;i--)
    {
        arr[i+1] = arr[i];
    }
    n=n+1;
    arr[pos] = value;
    for(int i=0; i<n;i++)
    {
        cout<<arr[i]<<",";
    }
   
}
int main()
{
    int arr[6];
    int n,position,value;
    cout<<"Enter the no of elements: ";
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    cout<<"Enter the index: ";
    cin>>position;
    cout<<"Enter the value: ";
    cin>>value; 
    insertion_at_any_location(position,n,arr,value);
return 0;
}

// insertion at two values above