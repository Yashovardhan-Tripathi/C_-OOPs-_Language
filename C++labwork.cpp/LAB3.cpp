#include <iostream>
using namespace std;
class employees
{
public:
    int age;
    string name;
    employees()
    {
        age = 0;
        name = "";
    }
};

int main()
{
    cout << "Name:Yashovardhan Tripathi" << endl;
    cout << "PRN No.:230105231360" << endl;
    cout << "Division: D" << endl;
    cout << "Roll No.:14" << endl;
    cout << "Experiment No:03" << endl;;
    employees emp[5];
    cout << "Enter details of 5 employees:" << endl;
    employees t;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter Name and Age of " << i + 1 << " Employee: " << endl;
        cin >> t.name >> t.age;
        emp[i] = t;
    }
    cout << "The details are as follows: " << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << "The Name and Age of Employee No. " << i + 1 << " is: " << emp[i].name << ", " << emp[i].age << endl;
    }

    return 0;
}