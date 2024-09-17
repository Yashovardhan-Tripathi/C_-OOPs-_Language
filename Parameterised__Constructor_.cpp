#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    Complex(int x, int y)
    {
        a = x;
        b = y;
    }
    void printNum()
    {
        cout << "Your Number is " << a << " + " << b << "i" << endl;
    }
};

int main()
{
    // Implicit Call
    Complex a(4, 5);
    a.printNum();

    // Explicit Call
    Complex b = Complex(7, 8);
    b.printNum();

    return 0;
}