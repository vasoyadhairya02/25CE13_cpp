#include<iostream>
using namespace std;
class student
{
    int roll_no;
    string name;
    float marks_1;
    float marks_2;
    float average;
public:

    student()
    {
        roll_no=1;
        name="xyz";
        marks_1=0;
        marks_2=0;
        calculateAverage();
    }

    student(int r,string n,float m1,float m2)
    {
        roll_no=r;
        name=n;
        marks_1=m1;
        marks_2=m2;
        calculateAverage();
    }
    void calculateAverage()
    {
        average = (marks_1 + marks_2) / 2;
    }
    void display()
    {
        cout << "\nRoll No: " << roll_no;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks_1 << ", "<< marks_2;
        cout << "\nAverage Marks: " << average << endl;
    }

};
int main()
{
    cout<<"Name   : Dhairya Vasoya "<<endl;
    cout<<"ID no. : 25CE135 "<<endl;
    int r,k;
    float m1,m2;
    string n;
    cout<<"Enter the number of student: ";
    cin>>k;
    student s[k];


    for(int i=0; i<k; i++)
    {
        cout<<"Enter the name: ";
        cin>>n;
        cout<<"Enter the roll_no: ";
        cin>>r;
        cout<<"Enter the marks of 1 subject: ";
        cin>>m1;
        cout<<"Enter the marks of 2 subject: ";
        cin>>m2;
        s[i] = student(r, n, m1, m2);
    }


    cout << "\n--- Student Records ---";
    for (int i=0; i < k; i++)
    {
        s[i].display();
    }


    return 0;
}
