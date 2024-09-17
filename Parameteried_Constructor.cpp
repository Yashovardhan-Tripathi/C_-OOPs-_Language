#include <iostream>
using namespace std;

class Point
{
    int x, y;

public:
    Point(int a, int b)
    {
        x = a;
        y = b;
    }
    void displayNum()
    {
        cout << "The Point is (" << x << "," << y << ")" << endl;
    }
};

int main()
{
    Point P(1,2);
    P.displayNum();

    Point S(5,7);
    S.displayNum();

    return 0;
}