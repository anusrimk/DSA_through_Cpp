//enrollment for examination
//marks entry
// regualr exam re exam
//regular exams ke liye passed subjects
//failed exams ke liye

#include <iostream>
using namespace std;

struct Student{

        

    public:
        float sub1 , sub2 , sub3 , sub4 , sub5  ;
        float *python=&sub1;
        float *cpp=&sub2;
        float *dsa=&sub3;
        float *maths=&sub4;
        float *english=&sub5;

        float total_average;
        string name ;
        int roll_no;
 
        void getdata (){
            cout<< "Name : \n";
            cin>> name;
            
            cout<<"Roll No : \n";
            cin>>roll_no;

            cout << " Python marks  -   \n";
            cin >>sub1;

            cout<< " C++ marks  -   \n";
            cin >>sub2;

            cout<<" DSA marks  -   \n";
            cin >>sub3;

            cout<< " Maths marks  -   \n";
            cin >>sub4;

            cout<< " English  marks  -   \n";
            cin >>sub5;

            total_average =(sub1+sub2+sub3+sub4+sub5)/5.0;
        }

        bool total_eligiblitycheck(){

            if (total_average>=70.00 && sub1 > 40.00 && sub2 > 60.00 && sub3 > 40.00 && sub4 > 40.00 && sub5 > 40.00){
                return true;
            }
            else{
                return false;
            }
        }

        void per_subject_eligibility(){
            int failed_subjects[5];
            int n;
            for (int i=0;i<=n; i++){
                if (sub1 <= 40.00){
                
                    cout<<"Subject Failed in: Python";
                }
                else if (sub2 <= 40.00){
                    
                    cout<<"Subject Failed in: C++";
                }
                else if (sub3 <= 40.00){
                   
                    cout<<"Subject Failed in: DSA";
                }
                else if (sub3 <= 40.00){
                
                    cout<<"Subject Failed in: Maths";
                }
                else if (sub3 <= 40.00){
                    cout<<"Subject Failed in: English";
                }
                else{
                    cout<<"The students have failed in NO SUBJECTS!";
                }
                cout<<"\n-------------------------------------------";
                }
            }
        void re_enter_marks(){
            if (sub1 <= 40.00){
                    cout<<"Re-enter new marks for Python: ";
                    cin>>*python;
                }
                else if (sub2 <= 40.00){
                    cout<<"Re-enter new marks for C++: ";
                    cin>>*cpp;
                }
                else if (sub3 <= 40.00){
                    cout<<"Re-enter new marks for DSA: ";
                    cin>>*dsa;
                }
                else if (sub3 <= 40.00){
                    cout<<"Re-enter new marks for Maths: ";
                    cin>>*maths;
                }
                else if (sub3 <= 40.00){
                    cout<<"Re-enter new marks for English: ";
                    cin>>*english;
                }
                else{
                    cout<<"The students have failed in NO SUBJECTS!";
                }
                cout<<"\n-------------------------------------------";
                }
            
        

        //Displaying data of the object
        void displaydata_passed(){
           
            cout<<"\nName    : " << name <<"\n";
            cout<<"Roll No : "<<roll_no<<"\n";
            cout<<"Average : " << total_average <<"\n";
            if (sub1 >= 40.00){
                    cout<<"Python: "<<sub1;
                }
                else if (sub2 > 40.00){
                    cout<<"C++: "<<sub2;
                }
                else if (sub3 > 40.00){
                    cout<<"DSA: "<<sub3;
                }
                else if (sub3 > 40.00){
                    cout<<"Maths: "<<sub4;
                }
                else if (sub3 > 40.00){
                    cout<<"English: "<<sub5;
                }
                else{
                    cout<<"Invalid output";
                }
                cout<<"\n-------------------------------------------";
        
                }
        void displaydata_failed(){
           
            cout<<"\nName    : " << name <<"\n";
            cout<<"Roll No : "<<roll_no<<"\n";
            cout<<"Average : " << total_average <<"\n";
            if (sub1 <= 40.00){
                    cout<<"Python: "<<sub1;
                }
                else if (sub2 <= 40.00){
                    cout<<"C++: "<<sub2;
                }
                else if (sub3 <= 40.00){
                    cout<<"DSA: "<<sub3;
                }
                else if (sub3 <= 40.00){
                    cout<<"Maths: "<<sub4;
                }
                else if (sub3 <= 40.00){
                    cout<<"English: "<<sub5;
                }
                else{
                    cout<<"Invalid output";
                }
                cout<<"\n-------------------------------------------";
        
                }


};


int main(){

    int n , search;
    char a;

    cout<<"How many Data you want to enter : ";
    cin>>n;
    Student stud[n];
    int main_choice;
    int passed_main;
    int failed_main;
    char cont;
    int i;

    for(int i = 0 ; i<n ; i++){

        stud[i].getdata();
    }
    cout<<"What do you want to choose\n1. Display Data \n2. Marks Entry:\n"; 
    cin>>main_choice;
    if (main_choice==1){
        cout<<"What do you want to choose\n1. For Passed Subjects \n2. Failed Subjects:\n";
        cin>>passed_main;
        if (passed_main==1){
            if (stud[i].total_eligiblitycheck() == true)
                for(int i = 0 ; i<n ; i++){
                    stud[i].displaydata_passed();
        }
        }
        else{
            for(int i = 0 ; i<n ; i++){
                stud[i].displaydata_failed();
        }
        }
        stud[i].total_eligiblitycheck();
    }
    else{
    cout<<"Do you want to Check some student's eligiblity \n";
    cin>>a;

    if (a == 'y' || a == 'Y'){
        cout<<"Write the Roll No. you want to look for \n";
        cin>>search;

        for (int i = 0 ; i < n ; i ++){
            if (search == stud[i].roll_no){
                 if (stud[i].total_eligiblitycheck() == true){
                    stud[i].displaydata_passed();
                    cout<<"\n"<<stud[i].name<<" IS ELIGIBLE FOR THE NEXT SEMESTER"<<"\n";
                    }
                else {
                    cout<<"\n"<<stud[i].name<<" IS NOT ELIGIBLE FOR THE NEXT SEMESTER"<<"\n";
                    stud[i].per_subject_eligibility();
                    //stud[i].displaydata_failed();
                    cout<<"Do you want to re-enter marks: ";
                    cin>>cont;
                    if (cont=='Y' or cont=='y'){
                        stud[i].re_enter_marks();
                        stud[i].displaydata_passed();
                    }
                }
            }
            else{
                continue;
            }
        }
    }
    }
      return 0;
}