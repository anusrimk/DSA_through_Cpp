#include <iostream>
using namespace std;

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int a[n];

    for (int i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> a[i];
    }

    bubble_sort(a, n);

    cout << "Sorted array in ascending order: ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    return 0;
}
