#include <iostream>
using namespace std;

void subjectwise_result(float student_marks[][100], int subjects, int students) {

    for (int i = 0; i < subjects; i++) {
        int topper_index = 0;
        int passing_count = 0;

        for (int j = 0; j < students; j++) {

            if (student_marks[i][j] > student_marks[i][topper_index]) {
                topper_index = j;
            }

            if (student_marks[i][j] >= 40) {
                passing_count++;
            }
        }

        float passing_percentage = (static_cast<float>(passing_count) / students) * 100;
        float failing_percentage = 100 - passing_percentage;

        cout << "Subject " << i + 1 << ":\n";
        cout << "Subject Topper (Student " << topper_index + 1 << "): " << student_marks[i][topper_index] << "\n";
        cout << "Passing Percentage: " << passing_percentage << "\n";
        cout << "Failing Percentage: " << failing_percentage << "\n\n";
    }
}

void studentwise_result(float student_marks[][100], int subjects, int students) {

    for (int i = 0; i < students; i++) {
        float total_marks = 0;

        for (int j = 0; j < subjects; j++) {
            total_marks += student_marks[j][i];
        }

        cout << "Student " << i + 1 << ":\n";
        cout << "Total Marks: " << total_marks << "\n";
        cout << "Percentage: " << (total_marks / subjects) << "\n\n";
    }
}

int main() {
    int subjects, students;

    cout << "Enter number of Subjects: ";
    cin >> subjects;
    cout << "Enter number of Students: ";
    cin >> students;

    float student_marks[subjects][100];

    for (int i = 0; i < subjects; i++) {
        for (int j = 0; j < students; j++) {
            cout << "Enter the marks for Subject " << i + 1 << " and Student " << j + 1 << ": ";
            cin >> student_marks[i][j];
        }
    }

    int option;
    cout << "Choose an option:\n";
    cout << "1. Subject-wise Result\n";
    cout << "2. Student-wise Result\n";
    cin >> option;

    switch (option) {
        case 1:
            subjectwise_result(student_marks, subjects, students);
            break;
        case 2:
            studentwise_result(student_marks, subjects, students);
            break;
        default:
            cout << "Invalid option\n";
            break;        
    }
    return 0;
}


    // Node *current = Start;
    // while (current != nullptr) {
    //     cout << current->data << " ";
    //     current = current->next;
