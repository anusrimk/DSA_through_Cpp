#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

struct Student
{
    char regular;
    int id,enroll;
    
    string dob,name;
    string chosen[5];
    int subject[5] = {};
};



void func(int* ptr , string subject){
    cout<<subject<<" : ";
    cin>>*ptr;
}

int main(){
    int id , enroll;

    cout<<"Enter your Roll No. (eg : \"1\" for Romil)";
    cin>>id;


    Student arr[100];

    arr[0].id = 1;
    arr[0].name = "Romil Pandey";
    arr[0].dob = "12 August 2005";

    Student temp;
    for (int i = 0 ; i < 100 ; i++){
        if(arr[i].id == id){
            cout<<"\n\nHey Welcome back "<<arr[i].name;
            temp = arr[i];
            break;
        }
        else{
            cout<<"\n\nRegistering the user : ";
            arr[i].id = id;
            cout<<"\nEnter name";
            cin>>arr[i].name;
            cin.ignore();
            cout<<"\nEnter Dob";
            getline(cin,arr[i].dob);
            temp = arr[i];
            break;
        }

    }

    rerun:
    cout<<"\n\nEnter the type of Task : \n1. Enrollment for exam\n2. Enter the marks for the exam\n3. Exit";
    cin>>enroll;

    switch(enroll)
    {
        case 1:
        if(toupper(temp.regular) == 'Y' || toupper(temp.regular) == 'N' ){
            cout<<"Already Enrolled for ";
            if(toupper(temp.regular) == 'Y'){
                cout<<"Regular"<<endl;
            }
            else{
                cout<<"Re-Exam"<<endl;
            }
        }
        int c;
        cout<<"\n\nEnter the exam you want to enroll for :\n1.Regular\n2.Re-exam ";
        cin>>c;

        if(c == 1){
            temp.regular = 'Y';
            srand(time(0)); 
            temp.enroll = rand()%1000;
            cout<<"You enrolled for the following exam on regular basis:\n1.C++\n2.Python\n3.Maths\n4.SRS(Software Requirement Skill)\n5.Computer Fundamentals\n"<<temp.enroll<<" is your Enrollment id please remember it\n";
        }
        else if(c == 2){

            if(temp.subject[0] <= 0 || temp.subject[0] > 100 ){
                cout<<"\nYou have not given any exam to be enrolled for Re-exam";
                goto rerun;
            }
            else{
                cout<<"\nYou are enrolled for re-exam go to section to check for available exams";
                srand(time(0)); 
                temp.enroll = rand()%1000;
                cout<<temp.enroll<<"is your Enrollment id please remember it\n";

                temp.regular = 'N';
            }

        }
        else{
            cout<<"\nWrong input"<<"\n\n";
            goto rerun;
        }
        goto rerun;
        break;
        case 2:
            if(toupper(temp.regular) == 'Y' || toupper(temp.regular) == 'N'){
                if(toupper(temp.regular) == 'Y')
                {
                    int password;
                    pass:
                        cout<<"\n\nPlease enter the enrollment id : ";
                        cin>>password;
                        if(!(password == temp.enroll)){
                            int y;
                            cout<<"\n\nIf you forgot press(0) or any other key to exit";
                            cin>>y;
                        }
                    cout<<"\n\nYou have to enter the marks as you enrolled for the following exam on regular basis:\n1.C++\n2.Python\n3.Maths\n4.SRS(Software Requirement Skill)\n5.Computer Fundamentals";
                    temp.chosen[0] = "C++";
                    temp.chosen[1] = "Python";
                    temp.chosen[2] = "Maths";
                    temp.chosen[3] = "SRS";
                    temp.chosen[4] = "Computer Fundamentals";
                    cout<<"\n\nEnter the marks for the following subs : ";
                    for(int i = 0 ; i < 5 ; i++){
                        func(&(temp.subject[i]),temp.chosen[i]);
                    }
                    temp.regular = 'x';
                    goto rerun;
                }
                else{
                    int a = sizeof(temp.chosen)/sizeof(temp.chosen[0]);
                    if( a > 0){
                        cout<<"\n\nYou were enrolled for regular and here is your marks \n";
                        int markscheck[a];
                        for(int i = 0 ; i < a ; i++){
                            cout<<temp.chosen[i]<<" : "<<temp.subject[i]<<endl;
                            markscheck[i] = temp.subject[i];
                        }
                        cout<<"\n\nFailed for these ones - : ";
                        for (int i = 0 ;i < a ; i++){
                            if(markscheck[i] < 40){
                                cout<<temp.chosen[i]<<endl;
                            }
                        }

                        cout<<"\n\nEnter the marks for that ones ";
                        for (int i = 0 ;i < a ; i++){
                            if(markscheck[i] < 40){
                                cout<<temp.chosen[i]<<" : ";
                                cin>>temp.subject[i];
                            }
                        }
                        temp.regular = 'x';
                        goto rerun;

                    }
                    else{
                        cout<<"\n\nYou are not enrolled in any";
                        goto rerun;
                    }

                }

            }
            else{
                cout<<"\n\nCurrently Not enrolled for any of the exam Please enroll ";
                goto rerun;
            }
            goto rerun;
        case 3:
            return 0;
        default:
            goto rerun;

    }




    return 0;
}