#include <iostream>
#include <string>
using namespace std;
class student
{
    int rollno;
    string name;

public:
    void get_data();
    void put_data();
};
void student::get_data()
{
    cout << "Enter roll number: ";
    cin >> rollno;
    cout << "Enter name: ";
    cin >> name;
}
void student::put_data()
{
    cout << "Roll Number is: " << rollno << endl;
    cout << "Name is: " << name << endl;
}

int main()
{
    cout << "Name:Yashovardhan Tripathi" << endl;
    cout << "PRN NO:230105231360" << endl;
    cout << "Roll NO:84" << endl;
    cout << "Experiment No:01" << endl;

    student s;
    s.get_data();
    s.put_data();
    return 0;
}