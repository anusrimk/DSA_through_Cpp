#include <iostream>
using namespace std;

struct Student {

    // Member variables
    float sub1, sub2, sub3, sub4, sub5;
    float *python = &sub1;
    float *cpp = &sub2;
    float *dsa = &sub3;
    float *maths = &sub4;
    float *english = &sub5;

    float total_average;
    string name;
    int roll_no;

    // Function to get data from the user
    void getdata() {
        cout << "Name: ";
        cin >> name;

        cout << "Roll No: ";
        cin >> roll_no;

        cout << " Python marks: ";
        cin >> sub1;

        cout << " C++ marks: ";
        cin >> sub2;

        cout << " DSA marks: ";
        cin >> sub3;

        cout << " Maths marks: ";
        cin >> sub4;

        cout << " English marks: ";
        cin >> sub5;

        total_average = (sub1 + sub2 + sub3 + sub4 + sub5) / 5.0;
    }

    // Function to check eligibility based on total average and individual subject marks
    bool total_eligibility_check() {
        return (total_average >= 70.0 && sub1 > 40.0 && sub2 > 60.0 && sub3 > 40.0 && sub4 > 40.0 && sub5 > 40.0);
    }

    // Function to display details of passed subjects
    void display_data_passed() {
        cout << "\nName: " << name << "\n";
        cout << "Roll No: " << roll_no << "\n";
        cout << "Average: " << total_average << "\n";

        if (sub1 >= 40.0) cout << "Python: " << sub1 << "\n";
        if (sub2 >= 40.0) cout << "C++: " << sub2 << "\n";
        if (sub3 >= 40.0) cout << "DSA: " << sub3 << "\n";
        if (sub4 >= 40.0) cout << "Maths: " << sub4 << "\n";
        if (sub5 >= 40.0) cout << "English: " << sub5 << "\n";

        cout << "-------------------------------------------\n";
    }

    // Function to display details of failed subjects
    void display_data_failed() {
        cout << "\nName: " << name << "\n";
        cout << "Roll No: " << roll_no << "\n";
        cout << "Average: " << total_average << "\n";

        if (sub1 <= 40.0) cout << "Python: " << sub1 << "\n";
        if (sub2 <= 40.0) cout << "C++: " << sub2 << "\n";
        if (sub3 <= 40.0) cout << "DSA: " << sub3 << "\n";
        if (sub4 <= 40.0) cout << "Maths: " << sub4 << "\n";
        if (sub5 <= 40.0) cout << "English: " << sub5 << "\n";

        cout << "-------------------------------------------\n";
    }

    // Function to re-enter marks for failed subjects
    void re_enter_marks() {
        if (sub1 <= 40.0) {
            cout << "Re-enter new marks for Python: ";
            cin >> *python;
        }
        if (sub2 <= 40.0) {
            cout << "Re-enter new marks for C++: ";
            cin >> *cpp;
        }
        if (sub3 <= 40.0) {
            cout << "Re-enter new marks for DSA: ";
            cin >> *dsa;
        }
        if (sub4 <= 40.0) {
            cout << "Re-enter new marks for Maths: ";
            cin >> *maths;
        }
        if (sub5 <= 40.0) {
            cout << "Re-enter new marks for English: ";
            cin >> *english;
        }
    }
};

int main() {
    int n, search;
    char a;

    cout << "How many Data you want to enter: ";
    cin >> n;
    Student stud[n];

    for (int i = 0; i < n; i++) {
        stud[i].getdata();
    }

    int main_choice;
    cout << "What do you want to choose\n1. Display Data \n2. Marks Entry:\n";
    cin >> main_choice;

    if (main_choice == 1) {
        int passed_main;
        cout << "What do you want to choose\n1. For Passed Subjects \n2. Failed Subjects:\n";
        cin >> passed_main;

        if (passed_main == 1) {
            for (int i = 0; i < n; i++) {
                if (stud[i].total_eligibility_check()) {
                    stud[i].display_data_passed();
                }
            }
        } else {
            for (int i = 0; i < n; i++) {
                stud[i].display_data_failed();
            }
        }
    } else {
        cout << "Do you want to Check some student's eligibility \n";
        cin >> a;

        if (a == 'y' || a == 'Y') {
            cout << "Write the Roll No. you want to look for \n";
            cin >> search;

            for (int i = 0; i < n; i++) {
                if (search == stud[i].roll_no) {
                    if (stud[i].total_eligibility_check()) {
                        stud[i].display_data_passed();
                        cout << stud[i].name << " IS ELIGIBLE FOR THE NEXT SEMESTER" << "\n";
                    } else {
                        cout << stud[i].name << " IS NOT ELIGIBLE FOR THE NEXT SEMESTER" << "\n";
                        stud[i].display_data_failed();
                        cout << "Do you want to re-enter marks: ";
                        char cont;
                        cin >> cont;
                        if (cont == 'Y' or cont == 'y') {
                            stud[i].re_enter_marks();
                            stud[i].display_data_passed();
                        }
                    }
                }
            }
        }
    }
    return 0;
}