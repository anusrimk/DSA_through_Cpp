#include <iostream>

using namespace std;

class Student{
    private:
    string subname;
    float percent;
    string failed;
    
    public:
    Student(){
        subname = "";
        failed = "False";
    }

    void setval(string nme,float prcent){
        subname = nme;
        percent = prcent;
    }
    
    void getval(){
        cout<<subname<<" :  "<<percent<<"%"<<endl;
    }
};

class check{
    private:
        int id;
        string failed;

    public:
        check(){
            failed = "False";
        }

        void setval(int d){
            failed = "True";
        }

        int getval(){
            int a =(failed == "True")? 1 : 0;
            return a;
            
        }

};  

int main(){
    int numsub , n , no;
    cout<<"Enter the number of subject : ";
    cin>>numsub;
    cout<<"\nEnter the number of students : ";
    cin>>no;
    check record[no];
    Student subject[numsub];
    for (int i = 0 ; i < numsub ; i++){
        int counter = 0;
        string ns;
        float percent;
        cout<<"\nEnter the name of subject : ";
        cin>>ns;
        

        int arr[no];

        cout<<"\n\nEnter the number for each student for "<<ns<<endl;

        for(int i = 0 ; i < no; i++ ){
            cout<<"\n\nEnter number for "<<i+1<<" th student : ";
            cin>>arr[i];
            
            if(arr[i] >=40){
                counter += 1;
            }
            else{
                record[i].setval(i);
            }
        }
        
        percent = (float(counter)/float(no))*100;

        subject[i].setval(ns,percent);


    }

    int another_counter = 0;

    for (int i = 0 ; i < no ; i++){
        if(record[i].getval() == 0){
            another_counter++;
        }
    }
    cout<<"\nThe Data \n";
    for (int i = 0 ; i < numsub ; i++){
        subject[i].getval();
    }
    cout<<"\nTotal number of Students \npassed : "<<another_counter<<"\n Failed : "<<no-another_counter;
    cout<<"\nOverall Data : "<<(float(another_counter)/float(no))*100.00;
    return 0;
}