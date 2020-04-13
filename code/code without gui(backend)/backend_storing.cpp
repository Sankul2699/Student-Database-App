/*
* Project Name: Student-Database-App

* File Name:backend_storing.cpp

* Author : Sanchit Kulkarni
*/


#include <iostream>
#define maxim 5 //maximum entries macro

using namespace std;
class stud
{

    char name[30];
    int dob;
    int rollno;
    static int i;


public:
    void enter()
    {
        cin>>name>>dob;
        rollno=++i;        //roll no assigned
    }

    void display()
    {
        cout<<"Name:"<<name<<"\n";
        cout<<"DOB:"<<dob<<"\n";
        cout<<"Rollno:"<<rollno;
    }
};
int stud::i;   // i is static
int main()
{

    int ele,max=0,b;   //ele are no of entries max is a flag which starts from 0 goes till maxim
    stud *p,*q;    //p q two pointer obj of class stud
  here :  cout<<"enter the no of students\n";
        cin>>ele;
        if(ele>maxim)
        {

        cout<<"Error more elements cannot be stored\n";
        goto here;
        }
        p=new stud[ele]; //memory allocated as per the no of inputs given by user
        max=max+ele;
         cout<<"enter the name and dob\n";

         for(int i=0;i<ele;i++)
        {
           p[i].enter();

        }

    while(max<maxim)
    {
        cout<<"enter the no of students\n";
        cin>>ele;
        if((max+ele)>maxim)
        {
        cout<<"Error more elements cannot be stored\n";
        continue;
        }
        q=new stud[max+ele];
        for(int i=0;i<max;i++)
        {
            q[i]=p[i]; //q takes values of p
        }
        cout<<"enter the name and dob\n";
        for(int i=max;i<max+ele;i++)
        {
            q[i].enter();  //remaining memory of q is filled by user

        }
        delete p;
        p=q; //q stores back to p

        max=max+ele;
    }
    cout<<"enter the pos\n";// pos to display
    cin>>b;
    p[b-1].display();

    return 0;
}

