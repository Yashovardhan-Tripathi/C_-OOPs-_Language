#include<iostream>
using namespace std;

class Complex
{
    int a,b;
    friend Complex sumComplex(Complex o1, Complex o2);
    public:
    void setNumber(int n1, int n2)
    {
        a=n1;
        b=n2;
    }
    void printNumber(void)
    {
        cout<<"Your number is "<<a<<" + "<<b<<"i"<<endl;
    }
};
Complex sumComplex(Complex o1,Complex o2)
{
    Complex o3;
    o3.setNumber((o1.a + o2.a) ,(o1.b + o2.b));
    return o3;
}

int main()
{
    Complex C1,C2,sum;
    C1.setNumber(1,4);
    C1.printNumber();

    C2.setNumber(5,2);
    C2.printNumber();

    sum=sumComplex(C1,C2);
    sum.printNumber();
return 0;
}