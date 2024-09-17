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

    // Function for subtracting two numbers
    inline float diff()
    {
        cout << "Diffrence of Two numbers are : " << num_1 - num_2;
    }

    // Function for multiplying two numbers
    inline float multiply()
    {
        cout << "The Multiply of two numbers is : " << num_1 * num_2 << endl;
    }

    // Function for divinding two numbers
    inline float div()
    {
        cout << "The Division of two numbers is : " << num_1 / num_2 << endl;
    }

    // Function for getting remainder of two numbers
    inline float rem()
    {
        cout << "The Reminder of two numbers is : " << static_cast<int>(num_1) % static_cast<int>(num_2) << endl;
    }

    // Function for finding power of a number
    inline float powe()
    {
        float z = num_1;
        for (int i = 1; i < power; i++)
        {
            num_1 = z * num_1;
        }
        cout << "The Power of a number is : " << num_1 << endl;
    }

    // Function for finding the square root of a number
    inline float sqrot()
    {
        float i;
        for (i = 0.000001; i * i < num_1; i = i + 0.000001)
        {
        }
        cout << "The Root of a number is : " << i << endl;
    }

    // Function for finding factorial of a number
    inline int fact()
    {
        int res = 1;
        for (int z = 2; z <= num_1; ++z)
        {
            res = res * z;
        }
        cout << "The Factorial of a number is : " << res << endl;
        return 0;
    }

    // Function for finding Percentage of a number
    inline float per()
    {
        float percent = (perc * num_1) / 100;
        cout << "The Percentage of a number is : " << percent << endl;
        return 0;
    }

    int Choose(void)
    {
        cout << "Enter your operation from menu " << endl;
        cin >> Choice;
        return Choice;
    }

    int get_Num1(void)
    {
        cout << "Enter your First number for Calculation : " << endl;
        cin >> num_1;
    }

    int get_Num2(void)
    {
        cout << "Enter your Second number for Calculation : " << endl;
        cin >> num_2;
    }

    int get_powers(void)
    {
        cout << "Enter your Power number: " << endl;
        cin >> power;
    }
    int get_percent(void)
    {
        cout << "Enter your Percent number: " << endl;
        cin >> perc;
    }

    void menu(void)
    {
        cout << "This is a basic calculator." << endl;
        cout << "Choice present within calculator are." << endl;
        cout << "1-For Adding two numbers" << endl;
        cout << "2-For Subtracting two numbers" << endl;
        cout << "3-For Multiply two numbers" << endl;
        cout << "4-For Divide two numbers" << endl;
        cout << "5-For Remainder of two numbers" << endl;
        cout << "6-For Power of a number" << endl;
        cout << "7-For Squaroot of a number" << endl;
        cout << "8-For Factorial of a number" << endl;
        cout << "9-For Percentage of a number" << endl;
    }
    
};

int main()
{
    float num_1, num_2;
    int power, perc;
    Calsi Calculator;
    Calculator.menu();
    cout << endl;
    int Choice = Calculator.Choose();

    switch (Choice)
    {
        
    case 1:
        Calculator.get_Num1();
        Calculator.get_Num2();
        Calculator.add();
        break;
    case 2:
        Calculator.get_Num1();
        Calculator.get_Num2();
        Calculator.diff();
        break;
    case 3:
        Calculator.get_Num1();
        Calculator.get_Num2();
        Calculator.multiply();
        break;
    case 4:
        Calculator.get_Num1();
        Calculator.get_Num2();
        Calculator.div();
        break;
    case 5:
        Calculator.get_Num1();
        Calculator.get_Num2();
        Calculator.rem();
        break;
    case 6:
        Calculator.get_Num1();
        Calculator.get_powers();
        Calculator.powe();
        break;
    case 7:
        Calculator.get_Num1();
        Calculator.sqrot();
        break;
    case 8:
        Calculator.get_Num1();
        Calculator.fact();
        break;
    case 9:
        Calculator.get_Num1();
        Calculator.get_percent();
        Calculator.per();
        break;
    default:
        cout << "Your choice is invalid...Please make a valid choice.....";
        break;
        
    }

    return 0;
}