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
    cout << "PRN NO:230105231360" << endl;
    cout << "Roll NO:84" << endl;
    cout << "Experiment No:02" << endl;

    Demo x;
    x.fun();
    return 0;
}