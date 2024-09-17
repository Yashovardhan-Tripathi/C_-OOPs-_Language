#include <iostream>
using namespace std;
class Bankdeposite
{
    int principal;
    int years;
    float intrestRate;
    float returnValue;

public:
    Bankdeposite() {}
    Bankdeposite(int p, int y, float r)
    {
        principal = p;
        years = y;
        intrestRate = r;
        returnValue = principal;
        for (int i = 0; i < y; i++)
        {
            returnValue *= (1 + intrestRate);
        }
    }
    Bankdeposite(int p, int y, int r)
    {
        principal = p;
        years = y;
        intrestRate = float(r) / 100;
        returnValue = principal;
        for (int i = 0; i < y; i++)
        {
            returnValue *= (1 + intrestRate);
        }
    }
    void show_value()
    {
        cout << endl
             << "Principal amount was " << principal << ". Return value after " << years << " years is " << returnValue << endl;
    }
};
int main()
{
    Bankdeposite BD1, BD2, BD3;
    int p, y, R;
    float r;
    cout << "Enter the value of p y and r " << endl;
    cin >> p >> y >> r; 
    BD1 = Bankdeposite(p, y, r);
    BD1.show_value();
    cout << "Enter the value of p y and R " << endl;
    cin >> p >> y >> R;
    BD2 = Bankdeposite(p, y, R);
    BD2.show_value();
    return 0;
}