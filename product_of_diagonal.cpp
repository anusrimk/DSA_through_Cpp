#include <iostream>
using namespace std;
 
int main()
{
    int size;
    int matrix[size][size];
    int sum_left =0, sum_right = 0;
    cout << "Enter elements into the matrix \n";

    for(int i=0; i<size ; i++){
        for(int j=0; j<size; j++){
        cin >> matrix[i][j];
        if(i==j)
            sum_left += matrix[i][j];
        if((i+j) == size-1)
            sum_right += matrix[i][j];
        }
    }

  cout << "Sum of Left Diagonal: "<< sum_left << endl;
  cout << "Sum of Right Diagonal: "<< sum_right << endl;

  return 0;
}