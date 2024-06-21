#include <iostream>
#include <random>
#include <iomanip>
using namespace std;


class ATM{
private:
    double balanceinAcc;
public:
    ATM(): balanceinAcc(100000.0){}
    
    void Greenpin(){
        int answer;
        long cardno;
        long cifno;
        int max;
        int OTP;
        int newpass;
        int confirmpass;
        int DebitCard;
        int Creditcard;
        cout<< "Do you want to generate a green pin for \n";
        cout<<"1. Credit Card\n ";
        cout<<"2. Debit Card\n ";
        cin>>answer;
        if (answer==1){


            cout<<"Enter your card number: \n";
            cin>> cardno;

            cout<<"Enter you CIF number: \n";
            cin>>cifno;

            max = 1000000; 
            srand(time(0));
            cout << "The GREEN PIN number is: \n"<<rand()%max;
        }
        else{
            cout<<"Enter your card number: \n";
            cin>> cardno;
            if (cardno>10000000000000000.0 && cardno<1000000000000000.0 ){
                cout<<"Enter valid card number: ";
                return;
            }
            else{
                cout<<"Enter you CIF number: \n";
                cin>>cifno;

                max = 1000000; 
                srand(time(0));
                cout << "The GREEN PIN number is: \n"<<rand()%max;
            }
    
        }
    }
    void ChangePin(){
        //int answer;
        int cardno1;
        int cifno1;
        int max1;
        int OTP;
        int OTP1;
        int newpass;
        int confirmpass;
        int random;
        //int DebitCard;
        //int Creditcard;
            cout<<"Enter your card number:\n ";
            cin>> cardno1;

            cout<<"Enter you CIF number: \n";
            cin>>cifno1;

            //max1 = 1000000; 
            srand(time(NULL));
            
            //cout<<random=rand();
            int i,rdno;
            //for(i=1;i<5;++i){
            rdno=(rand()%1000000)+15;
                
            cout << "\nThe OTP number is: \n"<< rdno;
            
           

            cout<<"\nReenter the OTP here to verify: \n";
            cin>>OTP1;

            if(OTP1==rdno){

                cout<<"OTP verified!\n";
                cout<<"  \n";
                cout<<"Enter new password\n";
                cin>>newpass;

                cout<<"  \n";
                cout<<"Confirm new password\n";
                cin>>confirmpass;
                if (newpass==confirmpass){
                    cout<<"NEW PASSWORD SET SUCCESSFULLY!";
                }
                else{
                    cout<<"Re-eneter confirmation password";
                    cin>>confirmpass;
                    cout<<"NEW PASSWORD SET SUCCESSFULLY!";
                    cout<<"  \n";
                    cout<<"  \n";
                }
            }
            else{
                cout<<"Invalid OTP";
                return;
            }
            

        };
    
    

    
    void BalanceInquiry(){
              
        cout<<" \n";
        cout<<"  \n";
        cout<<"\nThe balance in your bank account is "<< balanceinAcc;
        cout<<"  \n";
        cout<<"  \n";
    };

    void DepositinAcc(){
        double amount;
        cout<< "Enter the amount you want to deposit in your account: \n";
        cin>>amount;

        if (amount<0){
            cout<<"The amount is invaild!: \n";
            return;
        }
            balanceinAcc += amount;
            cout<<"\nThe amount "<<fixed<<setprecision(2)<< amount << " Has been succesfully deposited!\n";
            cout<<"\n The total amount now in your account is "<< balanceinAcc<<" \n";
        };
    void Withdraw(){
        double amount;
        cout<<"Enter the amount you want to enter: ";
        cin>> amount;


        if (amount> balanceinAcc || amount<0){
            cout<<"The amount you enter is exceeding the balance (Insufficient amount) \n";
                return;
        }
        balanceinAcc -= amount;
        cout<<fixed<<setprecision(2)<<amount<<" Succesfully withdrawn from your account\n";
        cout<<"\n The total amount now in your account is "<< balanceinAcc<< "  \n";
        };
    };


int main(){
//mainmenu
    ATM atm;
    int options;
    int choice;



    do{
        cout<<"   \n";
        cout<<"----------TEAM 8 ATM-----------\n";
        cout<<"   \n";
        cout<<"---------WELCOMES YOU----------\n";
        cout<<"   \n";
        cout<<"Choose your option\n";
        cout<<"1. Generate Green Pin\n";
        cout<<"2. Change CARD password\n";
        cout<<"3. Account Details\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;


        switch (choice)
        {
        case 1:
            atm.Greenpin();
            break;
        case 2:
            atm.ChangePin();
            break;
        case 3:
             
            do{
                cout<<"1. Check Balance\n";
                cout<<"2. Deposit Amount\n";
                cout<<"3. Withdraw Amout\n";
                cout<<"4.Exit\n";

                cout<<"Enter your choice: ";
                cin>> options;

                switch (options)
                {
                case 1:
                    atm.BalanceInquiry();
                    break;
                case 2:
                    atm.DepositinAcc();
                    break;
                case 3:
                    atm.Withdraw();
                    break;
                case 4:
                    cout<<"Thank You! Visit Again!";
                    break;
                
                default:
                    cout<<"Invalid! Please choose between the above numbers!";
                    break;
                }
            }while (options!=4);

        case 4:
                cout<<"Thank You! Visit Again!";
                return 0;
                break;
        }
    }while(options!=4 );

    return 0;

}