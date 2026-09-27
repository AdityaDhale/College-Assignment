/*Write C++ program to calculate the salary of an employee given his basic
pay (taken as input from the user). Calculate salary of an employee. Let
HRA be 10 % of basic pay and TA be 5% of basic pay. Let employees pay
professional tax as 2% of total salary. Calculate salary payable after
Deductions.
*/

#include<iostream>
using namespace std;
int main()
{
    int salary, hra, ta, tax;

    cout<<"enter the basic pay of employee :";
    cin>>salary;
    
    salary +=0.1*salary;
    salary +=0.05*salary;

    cout<<"Salary Before Tax :"<<"Rs "<<salary<<"/-"<<endl;

    salary -= 0.02*salary;
    cout<<"Salary After Tax :"<<"Rs "<<salary<<"/-"<<endl;
    
    return 0;


}