#include<iostream>
using namespace std;
int main()
{
    int a, money;
    int bal=10000;

    
    do
    {
        cout<<"= Bank System ="<<endl;
        cout<<"1] Deposit"<<endl<<"2] Withdrawal "<<endl<<"3] Account Status"<<endl<<"4]Exit";
        cout<<"enter choice: "; cin>>a;
        if(a==1)
        {
            cout<<"Enter the money to Deposit :"; cin>>money;
            if(money>100)
            {
                bal+=money;
                cout<<"Successfully Monet Deposited"<<endl;
            }
            else
            {
                cout<<"Amount must be more than 100 "<<endl;
            }
        }

        else if(a==2)
        {
            cout<<"Enter the amount to Withdraw :"; cin>>money;
            if(money < 100)
            {
                cout<<"Enter the amount withdraw more than 100"<<endl;
            }
            else if(money > bal)
            {
                cout<<"Insufficient Bank Balance"<<endl;
            }
            else
            {
                cout<<"Successfully money withdraw"<<endl;
                bal-=money;
            }
        }

        else if(a==3)
        {
            cout<<"Account Balance : "<<bal<<endl;
            if(bal>=20000)
            {cout<<"Good Balance"<<endl;}
            else if(bal>=10000)
            {cout<<"Average Balance"<<endl;}
            else if(bal>=1000)
            {cout<<"bad Balance"<<endl;}
            else if ( bal == 0)
            {cout<<"No balance"<<endl;}
            else
            {cout<<"less balance that 1000"<<endl;}
            
        }


    }while(a!=4);

    cout<<"Exited ......"<<endl;

    return 0;
}