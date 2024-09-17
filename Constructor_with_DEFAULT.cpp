#include <iostream>
using namespace std;

class Simple
{
    int Data_1, Data_2, Data_3;

public:
    Simple(int a, int b = 9, int c = 8)
    {
        Data_1 = a;
        Data_2 = b;
        Data_3 = c;
    }
    void printData()
    {
        cout << "The value of Data_1 , Data_2 and Data_3 is " << Data_1 << " , " << Data_2 << " and " << Data_3 << endl;
    }
};

int main()
{
    Simple S1(12, 13, 14);
    S1.printData();

    Simple S2(21);
    S2.printData();

    Simple S3(12,5);
    S3.printData();

    return 0;
}