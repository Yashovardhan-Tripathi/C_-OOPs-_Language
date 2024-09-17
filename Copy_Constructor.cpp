#include <iostream>
using namespace std;
class Number
{
    int a;

public:
    Number() { a = 0; }
    Number(int x)
    {
        a = x;
    }
    Number(Number &obj)
    {
        cout << "Copy Constructor called !!! " << endl;
        a = obj.a;
    }
    void display()
    {
        cout << "The number for this object is " << a << endl;
    }
};
int main()
{
    Number x, y, z(45), z2;
    x.display();
    y.display();
    z.display();
    Number z1(z); // ----> Copy Constructor invoked
    z1.display();
    z2 = z; // ---->Copy Constructor Not called
    z2.display();
    Number z3 = z; // ----> Copy Constructor invoked
    z2.display();
    return 0;
}