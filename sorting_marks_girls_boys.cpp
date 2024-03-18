// #include <iostream>
// using namespace std;

// int main() {
//     int boys, girls;
//     cout << "Enter number of boys: ";
//     cin >> boys;
//     int boysGrades[boys];
//     cout << "Enter boy's grades: ";
//     for (int i = 0; i < boys; i++) {
//         cin >> boysGrades[i];
//     }

//     cout << "Enter number of girls: ";
//     cin >> girls;
//     int girlsGrades[girls];
//     cout << "Enter girl's grade: ";
//     for (int i = 0; i < girls; i++) {
//         cin >> girlsGrades[i];
//     }

//     int classGrades[boys + girls];
//     int length = boys + girls;
//     int boyPointer = 0, girlPointer = 0;

//     for (int i = 0; i < length; i++) {
//         // Handle equal grades
//         if (boyPointer < boys && girlPointer < girls) {
//             if (boysGrades[boyPointer] == girlsGrades[girlPointer]) {
//                 classGrades[i] = girlsGrades[girlPointer];
//                 i++;
//                 classGrades[i] = boysGrades[boyPointer];
//                 girlPointer++;
//                 boyPointer++;
//             } 
//             else if (boysGrades[boyPointer] < girlsGrades[girlPointer]) {
//                 classGrades[i] = boysGrades[boyPointer];
//                 boyPointer++;
//             } 
//             else {
//                 classGrades[i] = girlsGrades[girlPointer];
//                 girlPointer++;
//             }
//         } 
//         else if (boyPointer < boys) {
//             classGrades[i] = boysGrades[boyPointer];
//             boyPointer++;
//         } 
//         else if (girlPointer < girls) {
//             classGrades[i] = girlsGrades[girlPointer];
//             girlPointer++;
//         }
//     }

//     // Print the result
//     for (int i = 0; i < length; i++) {
//         cout << classGrades[i] << " ";
//     }
//     cout << endl;

//     return 0;
// }

#include <iostream>
using namespace std;

int main() {
    int boys, girls;
    cout << "Enter number of boys: ";
    cin >> boys;
    int boysGrades[boys];
    cout << "Enter boy's grades: ";
    for (int i = 0; i < boys; i++) {
        cin >> boysGrades[i];
    }

    cout << "Enter number of girls: ";
    cin >> girls;
    int girlsGrades[girls];
    cout << "Enter girl's grade: ";
    for (int i = 0; i < girls; i++) {
        cin >> girlsGrades[i];
    }

    int classGrades[boys + girls];
    int length = boys + girls;
    int boyPointer = 0, girlPointer = 0;

    for (int i = 0; i < length; i++) {
        if (boyPointer < boys && girlPointer < girls) {
            if (boysGrades[boyPointer] == girlsGrades[girlPointer]) {
                classGrades[i] = girlsGrades[girlPointer];
                girlPointer++;
            } else if (boysGrades[boyPointer] < girlsGrades[girlPointer]) {
                classGrades[i] = boysGrades[boyPointer];
                boyPointer++;
            } else {
                classGrades[i] = girlsGrades[girlPointer];
                girlPointer++;
            }
        } else if (boyPointer < boys) {
            classGrades[i] = boysGrades[boyPointer];
            boyPointer++;
        } else if (girlPointer < girls) {
            classGrades[i] = girlsGrades[girlPointer];
            girlPointer++;
        }
    }
    for (int i = 0; i < length; i++) {
        cout << classGrades[i] << " ";
    }
    cout << endl;

    return 0;
}
