/*Write C++ program to accept a student's five subject marks and compute
His/her result. Student is passing if he/she scores marks equal to and above 40
in each course. If student scores aggregate greater than 75%, then the grade
is a distinction. If aggregate is 60>= and <75 then the grade of first division. If
aggregate is 50>= and <60, then the grade is second division. If aggregate is
40>= and <50, then the grade is third division
*/

#include<iostream>
using namespace std;
int main()
{
    int maths, science, comp, english, hindi;
    int sum , per;

    cout<<"enter the marks of maths:";
    cin>> maths;
    
    cout<<"enter the marks of comp:";
    cin>> comp;
    
    cout<<"enter the marks of english:";
    cin>> english;
    
    cout<<"enter the marks of science:";
    cin>> science;
    
    cout<<"enter the marks of :";
    cin>> hindi;

    sum = maths + science+english+comp+hindi;
    per = sum/5;

    if(per>75)
        cout<<"Distinction";
    else if(per>=60 && per<75)
        cout<<"First Division ";
    else if(per>=50 && per<60)
        cout<<"Second Division";
    else if(per>=40 && per<50)
        cout<<"Third Division";
    else
        cout<<"Fail";

    return 0;
}