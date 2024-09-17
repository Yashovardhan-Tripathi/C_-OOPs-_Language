#include <iostream>
using namespace std;

class Complex
{
    int a, b;

public:
    Complex();
    void printNumber()
    {
        cout << "Your Number is " << a << " + " << b << "i" << endl;
    }
};
Complex::Complex()
{
    a = 10;
    b = 20;
}

int main()
{
    Complex C1,C2;
    C1.printNumber();
    C2.printNumber();

    return 0;
}