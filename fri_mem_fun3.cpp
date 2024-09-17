#include <iostream>
using namespace std;
class C2;

class C1
{
    int val1;
    friend void exchange(C1 &X, C2 &Y);

public:
    void indata(int a)
    {
        val1 = a;
    }
    void display(void)
    {
        cout << val1 << endl;
    }
};

class C2
{
    int val2;
    friend void exchange(C1 &X, C2 &Y);

public:
    void indata(int b)
    {
        val2 = b;
    }
    void display(void)
    {
        cout << val2 << endl;
    }
};
void exchange(C1 &X, C2 &Y)
{
    int temp = X.val1;
    X.val1 = Y.val2;
    Y.val2 = temp;
}

int main()
{
    C1 oc1;
    C2 oc2;
    oc1.indata(55);
    oc2.indata(34);
    exchange(oc1, oc2);
    cout << "The Value of C1 after exchange becomes : ";
    oc1.display();
    cout << "The Value of C2 after exchange becomes : ";
    oc2.display();

    return 0;
}