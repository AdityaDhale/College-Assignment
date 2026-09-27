//Write C++ program to swap two numbers

#include<iostream>
using namespace std;
int main()
{
    int a, b, temp;

    cout<<"enter the first number :";
    cin>>a;
    cout<<"enter the second number : ";
    cin>>b;

    
    temp = a;
    a = b;
    b = temp;
    cout<<"The two number after swap : "<<a<<"  "<<b;

    return 0;


}