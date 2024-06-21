// #include <iostream>
// using namespace std;

// void InsertionAtBeg(){
//     int array_size,no_of_elements,i;
//     int total_array[array_size];
//     for (i=1;i<=no_of_elements;i++){
//         total_array[i+1]=total_array[i];
//     }
//     int element;
//     cout<<"Enter the element you want to add: ";
//     total_array[0]=element;
//     cout<<total_array;
// }
// int main(){
//     int array_size,no_of_elements,i;
//     cout<<"Enter the total length of array: ";
//     cin>>array_size;
//     int total_array[array_size];
//     cout<<"Enter the elements you want to enter: ";
//     cin>>no_of_elements;
//     for (i=0;i<=no_of_elements;i++){
//         cout << "Element " << i + 1 << ": ";
//         cin >> total_array[i];
//     }
//     cout<<total_array;
// }
#include <iostream>
using namespace std;

void InsertionAtBeg(int total_array[], int& no_of_elements) {
    int element;
    for (int i = no_of_elements; i > 0; i--) {
        total_array[i] = total_array[i - 1];
    }

    cout << "Enter the element you want to add: ";
    cin >> element;
    total_array[0] = element;
    no_of_elements++;
}

int main() {
    int array_size, no_of_elements, i;

    cout << "Enter the total length of array: ";
    cin >> array_size;

    int total_array[array_size];

    cout << "Enter the number of elements you want to enter: ";
    cin >> no_of_elements;

    cout << "Enter the elements: ";
    for (i = 0; i < no_of_elements; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> total_array[i];
    }

    InsertionAtBeg(total_array, no_of_elements);

    cout << "Modified array: ";
    for (i = 0; i < no_of_elements; i++) {
        cout << total_array[i] << " ";
    }

    cout << "\nLast element in the modified array: " << total_array[no_of_elements - 1];

    return 0;
}

