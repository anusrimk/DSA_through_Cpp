// #include<iostream>
// using namespace std;
// void del_at_any_position(int size, int position, int arr[])
// {
//     for(int i=position; i<=size-1;i++)
//     {
//         arr[i] = arr[i+1];
//     }
//     for(int i=0; i<size-1;i++)
//     {
//         cout<<arr[i]<<" ";
//     }

// }
// int main()
// {
//     int choice;
//     cout<<"Enter your choice:\n 1)At any location\n 2)At the beginning\n 3)At the end\n";
//     cin>>choice;
//     switch(choice){
//         case 1:
//             int n,position;
//             cout<<"Enter the no of elements: ";
//             cin>>n;
//             int arr[n];
//             fill_n(arr,n+1,-1);
//             for (int i = 0; i < n; ++i) {
//                 cout << "Element " << i + 1 << ": ";
//                 cin >> arr[i];
//             }
//             cout<<"Enter the index: ";
//             cin>>position;
//             del_at_any_position(n,position,arr);
//         case 2:
            
//     }
    
// return 0;
// }
#include<iostream>
using namespace std;

void del_at_any_position(int size, int position, int arr[])
{
    for(int i=position; i<size-1; i++)
    {
        arr[i] = arr[i+1];
    }
    for(int i=0; i<size-1; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void del_at_beginning(int size, int arr[])
{
    for(int i=0; i<size-1; i++)
    {
        arr[i] = arr[i+1];
    }
    for(int i=0; i<size-1; i++)
    {
        cout<<arr[i]<<" ";
    }
}

void del_at_end(int size, int arr[])
{
    for(int i=0; i<size-1; i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int choice;
    cout<<"Enter your choice:\n 1)At any location\n 2)At the beginning\n 3)At the end\n";
    cin>>choice;

    switch(choice)
    {
        case 1:
            int n, position;
            cout<<"Enter the no of elements: ";
            cin>>n;
            int arr[n];
            fill_n(arr, n+1, -1);
            for (int i = 0; i < n; ++i) 
            {
                cout << "Element " << i + 1 << ": ";
                cin >> arr[i];
            }
            cout<<"Enter the index: ";
            cin>>position;
            del_at_any_position(n, position, arr);
            break;

        case 2:
            int m;
            cout<<"Enter the no of elements: ";
            cin>>m;
            int arr2[m];
            fill_n(arr2, m+1, -1);
            for (int i = 0; i < m; ++i) 
            {
                cout << "Element " << i + 1 << ": ";
                cin >> arr2[i];
            }
            del_at_beginning(m, arr2);
            break;

        case 3:
            int k;
            cout<<"Enter the no of elements: ";
            cin>>k;
            int arr3[k];
            fill_n(arr3, k+1, -1);
            for (int i = 0; i < k; ++i) 
            {
                cout << "Element " << i + 1 << ": ";
                cin >> arr3[i];
            }
            del_at_end(k, arr3);
            break;

        default:
            cout << "Invalid choice";
    }

    return 0;
}
