// #include<iostream>
// using namespace std;
// int main ()
// {
//     int n, i, j, x,max;
    // cout << "Enter size of array : ";
    // cin >> n;
    // int arr[n];
    // cout << "Enter element of array : ";
    // for (i = 0; i < n; i++)
    //     cin >> arr[i];    
//     {
//         // for largest number
//         for(int i = 0;i<n;i++){
//             for(int j = 0;j<n;j++){
//                 if(arr[i]>arr[j]){
//                     max = arr[i];
//                 }
//             }
//         }
//         // for second largest
//         for (j = i + 1; j < n; j++){
//             if (arr[i] < arr[j]){
//                 x = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = x;
//             }
//         }
//         if(arr[1]==max){
//             arr[1]=arr[n-1];
//     }
    
//     }
//     cout << "Second largest number : " << arr[1]<<"\n";
//     cout<<"Largest number : " << max;
//     return 0;
// }

#include <iostream>
using namespace std;


int main() {
    int n,i;
    cout << "Enter size of array : ";
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }
    int largest = -1, second_max = -1;

    for (int i = 0; i < n; ++i) {
        if  (arr[i] > largest) {
            second_max = largest;
            largest = arr[i];
        } else if  (arr[i] > second_max && arr[i] < largest) {
            second_max = arr[i];
        }
    }
    cout << "Largest no is: " << largest << endl;
    cout << "2nd largest is: " << second_max << endl;
    return 0;
}