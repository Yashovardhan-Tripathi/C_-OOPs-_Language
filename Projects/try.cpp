#include <iostream>
using namespace std;

// Creating a Class
class Calsi
{
    int Choice, power;
    float num_1, num_2, perc;

public:
    // Function for adding two numbers
    float add()
    {
        cout << "Sum of Two numbers are : " << num_1 + num_2;
      
    }
     int get_Num1(void)
    {
        cout << "Enter your First number for Addition : " << endl;
        cin >> num_1;
    }

    int get_Num2(void)
    {
        cout << "Enter your Second number for Addition : " << endl;
        cin >> num_2;
    }
};
int main()
{
    float num_1, num_2;
    Calsi Calculator;
    Calculator.get_Num1();
    Calculator.get_Num2();
    Calculator.add();

    return 0;
}