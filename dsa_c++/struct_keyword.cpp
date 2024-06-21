#include <iostream>
using namespace std;

struct Student{

        float sem1,sem2,sem3,sem4,sem5;
        float average;
        string name ;
        int roll_no;

        void getdata (){
            cout<< "Name : \n";
            cin>> name;
            
            cout<<"Roll No : \n";
            cin>>roll_no;

            cout << " Semester - 1 Marks -   \n";
            cin >>sem1;

            cout<< " Semester - 2 Marks -   \n";
            cin >>sem2;

            cout<< " Semester - 3 Marks -   \n";
            cin >>sem3;

            cout<< " Semester - 4 Marks -   \n";
            cin >>sem4;

            cout<< " Semester - 5 Marks -   \n";
            cin >>sem5;

            average =(sem1+sem2+sem3+sem4+sem5)/5.0;
        }

        bool eligiblitycheck(){
            if (average>=70.00 && sem1 >= 60.00 && sem2 >= 60.00 && sem3 >= 60.00 && sem4 >= 60.00 && sem5 >= 60.00){
                return true;
            }
            else{
                return false;
            }
        }
        void displaydata(){
            cout<<"\nName    : " << name <<"\n";
            cout<<"Roll No : "<<roll_no<<"\n";
            cout<<"Average : " << average <<"\n";
            cout<<"---------------------------\n";
        }
};

int main(){
    int n , search;
    char a;

    cout<<"How many Data you want to enter : ";
    cin>>n;
    Student stud[n];

    for(int i = 0 ; i<n ; i++){
        stud[i].getdata();
    }
    
    for(int i = 0 ; i<n ; i++){

        stud[i].displaydata();
        stud[i].eligiblitycheck();
    }
    
    cout<<"Do you want to Check some student's eligiblity \n";
    cin>>a;

    if (a == 'y' || a == 'Y'){
        cout<<"Write the Roll No. you want to look for \n";
        cin>>search;

        for (int i = 0 ; i < n ; i ++){
            if (search == stud[i].roll_no){
                 if (stud[i].eligiblitycheck() == true){
                    stud[i].displaydata();
                    cout<<"\n"<<stud[i].name<<" IS ELIGIBLE FOR THE NEXT SEMESTER"<<"\n";
                    }
                else {
                    stud[i].displaydata();
                    cout<<"\n"<<stud[i].name<<" IS NOT ELIGIBLE FOR THE NEXT SEMESTER"<<"\n";
                }
            }
            else{
                continue;
            }
        }
    }
      return 0;
}