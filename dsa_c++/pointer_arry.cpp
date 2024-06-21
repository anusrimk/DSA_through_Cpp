#include <iostream>
using namespace std;

int main() {
    int i, j, sum = 0;
    int arr1[5] = {11, 22, 33, 44, 55};
    int arr2[5] = {1, 2, 3, 4, 5};
    int arr3[5] = {111, 222, 333, 444, 555};

    int *ptrarray[3] = {arr1, arr2, arr3};

    for (i = 0; i < 3; i++) {
        sum = 0; 
        for (j = 0; j < 5; j++) {
            cout << ptrarray[i][j] << ",";
            sum += ptrarray[i][j];
        }
        cout << endl; 
        cout << "Sum of : " << i <<" array: "<< sum << endl;
    }

    return 0;
}
