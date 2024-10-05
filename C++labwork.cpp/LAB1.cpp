#include <iostream>
#include <string>

using namespace std;
class Student
{
private:
    int rollNo;
    string name;

public:
    void get_data()
    {
        cout << "Enter Roll No: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
    }

    void put_data() const
    {
        cout << "Roll No: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
};

int main()
{

    cout << "Name:Yashovardhan Tripathi" << endl;
    cout << "PRN No.:230105231360" << endl;
    cout << "Division: D" << endl;
    cout << "Roll No.: 14" << endl;
    cout << "Experiment No:01" << endl
         << endl;

    Student student;
    student.get_data();
    cout << endl;
    cout << endl;
    student.put_data();

    return 0;
}
