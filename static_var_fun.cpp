#include <iostream>
using namespace std;

class Employee
{
private:
    int id;
    static int count;

public:
    void setData(void)
    {
        cout << "Enter the Id " << endl;
        cin >> id;
        count++;
    }
    void getData(void)
    {
        cout << "The ID of this employee is " << id << " and this is employee number " << count  << endl;
    }

    static void getCount(void)
    {
        cout << "The value of count is " << count << endl;
    }
};
int Employee::count;

int main()
{
    Employee yash, manya;
    yash.setData();
    yash.getData();
    Employee ::getCount();

    manya.setData();
    manya.getData();
    Employee ::getCount();
    return 0;
}