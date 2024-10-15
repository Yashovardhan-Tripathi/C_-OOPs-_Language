#include <iostream>
using namespace std;

class Power
{
    int N, Choice;
    double N1, N2;

public:
    inline double multi()
    {
        cout << "Multiplication of two numbers " << N1 << " and " << N2 << " are " << N1 * N2;
    }
    inline int cube()
    {
        cout << "Cube of number " << N << " is " << N * N * N;
    }
    inline int get_input()
    {
        cout << "Enter the value for number " << endl;
        cin >> N;
    }
    inline double get_inp()
    {
        cout << "Enter the value for number " << endl;
        cin >> N1 >> N2;
    }
    inline void Option()
    {
        cout << "1.Multiplication of two Numbers " << endl;
        cout << "2.Cube of a Number " << endl;
    }
    int Choose(void)
    {
        cout << "Enter your operation from menu " << endl;
        cin >> Choice;
        return Choice;
    }
};

int main()
{
    cout << "Name:Yashovardhan Tripathi" << endl;
    cout << "PRN No.:230105231360" << endl;
    cout << "Division: D" << endl;
    cout << "Roll No.:14" << endl;
    cout << "Experiment No:08" << endl;

    double N1, N2;
    int N;
    Power number;
    number.Option();
    int Ch = number.Choose();

    switch (Ch)
    {

    case 1:
        number.get_inp();
        number.multi();
        break;
    case 2:
        number.get_input();
        number.cube();
        break;
    default:
        cout << "Invalid Choice !!!!!!";
    }
    return 0;
}