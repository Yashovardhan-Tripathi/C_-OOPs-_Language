#include <iostream>
using namespace std;
class Complex
{
    int a;
    int b;

public:
    /*void valueUser(void)
   {
       cout<<"Enter the value of a "<<endl;
       cin>>a;
       cout<<"Enter the value of b "<<endl;
       cin>>b;
   }*/

    void setData(int v1, int v2)
    {
        a = v1;
        b = v2;
    }
    void printNumber(void)
    {
        cout << "Your complex number is " << a << " + " << b << "i" << endl;
    }

    void setDataBySum(Complex o1, Complex o2)
    {
        a = o1.a + o2.a;
        b = o1.b + o2.b;
    }
};

int main()
{
    Complex C1, C2, C3;
    // C1.valueUser();
    C1.setData(1, 4);
    C1.printNumber();

    // C2.valueUser();
    C2.setData(4, 1);
    C2.printNumber();

    // cout<<"Result is : "<<endl;
    C3.setDataBySum(C1, C2);
    C3.printNumber();
    return 0;
}