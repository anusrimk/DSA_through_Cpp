#include<iostream>
using namespace std;
int main()
{
    int array[3][3];
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<"Enter the value of ("<<i<<","<<j<<"): ";
            cin>>array[i][j];
        }
    }
    for (int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<array[i][j]<<"\t";//slash t matlab tab space
        }
        cout<<endl;
    }

return 0;
}
void subjectwise_result(float student_marks[][50], int subjects, int students) {

    for (int i = 0; i < subjects; i++) {
        float total_marks = 0;
        int topper_index = 0;


        for (int j = 0; j < students; j++) {
            total_marks += student_marks[i][j];

            if (student_marks[i][j] > student_marks[i][topper_index]) {
                topper_index = j;
            }
        }


        cout << "Subject " << i + 1 << ":\n";
        cout << "Total Marks: " << total_marks << "\n";
        cout << "Subject Topper (Student " << topper_index + 1 << "): " << student_marks[i][topper_index] << "\n\n";
    }
}