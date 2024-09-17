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
    Complex(int x)
    {
        a = x;
        b = 0;
    }
    Complex()
    {
        a = 0;
        b = 0;
    }
    void printNum()
    {
        cout << "Your Number is " << a << " + " << b << "i" << endl;
    }
};
int main()
{
    Complex C1(4,6);
    C1.printNum();

    Complex C2(5);
    C2.printNum();

    Complex C3;
    C3.printNum();

    return 0;
}