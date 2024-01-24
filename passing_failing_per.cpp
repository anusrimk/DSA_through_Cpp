// #include <iostream>
// using namespace  ;

// int main(){
//     int n,i,j;
//     float marks,passed=0.0,failed=0.0;
//     cout<<"Enter the total number of students: ";
//     cin>>n;
//     int student[n];


//     for (i=1;i<=n;i++){
//         cout<<"Enter the marks in DSA: ";
//         cin>>marks;
//         if (marks>40){
//             passed+=1;
//         }
//         else{
//             failed+=1;
//         }
//     }
//     int choice;
//     cout<<"Do you want to see the Percenate of \nPassed(1) or \nFailed(2) Students:";
//     cin>>choice;
//     if (choice==1){
//         float passed_total=((passed/n)*100);
//         cout<<"Passed Percentage: "<<passed_total;
//     }
//     else{
//         float failed_total=((failed/n)*100);
//         cout<<"Failed Percentage: "<<failed_total;
//     }


#include <iostream>
using namespace std;
int main(){
    int n,i,j;
    float marks,passed=0,failed=0;
    cout<<"Enter the total number of students: ";
    cin>>n;
    int student[n];
    int dsa_marks[n];
    int html_marks[n];
    int css_marks[n];


    for (i=1;i<=n;i++){
        cout<<"Enter the marks in DSA: ";
        cin>>dsa_marks[i];
        cout<<"Enter the marks in HTML: ";
        cin>>html_marks[i];
        cout<<"Enter the marks in DSA: ";
        cin>>css_marks[i];
        cout<<"\n----------------------------\n";
        cout<<"\n";
    if ((dsa_marks[i]>40) and (html_marks[i]>40) and (css_marks[i]>40)){
        passed+=1;
    }
    else{
        failed+=1;
    }
        
    } 
    int choice;
    cout<<"Do you want to see the Percenate of \nPassed(1) or \nFailed(2) Students:";
    cin>>choice;
    if (choice==1){
        
        float passed_total=((passed/n)*100);
        cout<<"Passed Percentage: "<<passed_total;
    }
    else{
        if (dsa_marks[i]<=40){
            cout<<"\nSubject Failed in: DSA";
        }
        else if (html_marks[i]<=40){
            cout<<"\nSubject Failed in: HTML";
        }
        else if (css_marks[i]<=40){
            cout<<"\nSubject Failed in: CSS";
        }
        float failed_total=((failed/n)*100);
        cout<<"Failed Percentage: "<<failed_total;
    }

}