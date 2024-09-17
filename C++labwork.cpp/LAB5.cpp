#include <bits/stdc++.h>
using namespace std;
class Line
{
public:
    ~Line();
    Line(void);
    double get_Length();
    Line(double len);

public:
    double lenght;
};
Line ::Line(double len)
{
    lenght = len;
}
double Line ::get_Length(void)
{
    return lenght;
}
Line ::Line(void)
{
    cout << "Object is being created" << endl;
}

Line ::~Line()
{
    cout << "Object is being distructed" << endl;
}

int main()
{
    cout << "Name:Yashovardhan Tripathi" << endl;
    cout << "PRN NO:230105231360" << endl;
    cout << "Roll NO:84" << endl;
    cout << "Experiment No:05" << endl;
    Line line1;
    Line line = Line(3.54);
    cout << "Lenght of Line : " << line.get_Length() << endl;
    return 0;
}