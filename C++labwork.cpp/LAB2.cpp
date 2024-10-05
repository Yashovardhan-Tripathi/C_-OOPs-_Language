#include <iostream>
using namespace std;
class Demo
{
    static int x;

public:
    static void fun()
    {
        cout << "Value of X: " << x << endl;
    }
};
int Demo::x = 34;
int main()
{
    cout << "Name:Yashovardhan Tripathi" << endl;
    cout << "PRN No.:230105231360" << endl;
    cout << "Division: D" << endl;
    cout << "Roll No.:14" << endl;
    cout << "Experiment No:02" << endl;

    Demo x;
    x.fun();
    return 0;
}