#include <iostream>
using namespace std;

void largest_smallest(int arr[], int n) {
    int largestIndex = 0, smallestIndex = 0;
    
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[largestIndex]) {
            largestIndex = i;
        }
        else if (arr[i] < arr[smallestIndex]) {
            smallestIndex = i;
        }
    }

    cout << "Original Array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int temp = arr[largestIndex];
    arr[largestIndex] = arr[smallestIndex];
    arr[smallestIndex] = temp;

    cout << "Modified Array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    largest_smallest(arr, n);

    return 0;
}

