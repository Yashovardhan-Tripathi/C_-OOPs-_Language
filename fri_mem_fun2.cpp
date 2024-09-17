#include <iostream>
using namespace std ;
class Y;
class X
{
    int data;

public:
    void setValue(int value)
    {
        data = value;
    }
    friend void add(X, Y);
};
class Y
{
    int num;

public:
    void setValue(int value)
    {
        num = value;
    }
    friend void add(X, Y);
};

void add(X a1, Y b1)
{
    cout << "Summing data of X and Y object give me " << a1.data + b1.num;
}
int main()
{
    X o1;
    o1.setValue(3);
    Y o2;
    o2.setValue(5);
    add(o1, o2);
    return 0;
}