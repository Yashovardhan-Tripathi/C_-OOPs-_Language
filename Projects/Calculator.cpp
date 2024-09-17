//Basic Calculator
#include <iostream>
using namespace std;

// Function for adding two numbers
inline float add(float num_1, float num_2)
{
    return (num_1 + num_2);
}

// Function for subtracting two numbers
inline float diff(float num_1, float num_2)
{
    return (num_1 - num_2);
}

// Function for multiplying two numbers
inline float multiply(float num_1, float num_2)
{
    return (num_1 * num_2);
}

// Function for divinding two numbers
inline float div(float num_1, float num_2)
{
    return (num_1 / num_2);
}

// Function for getting remainder of two numbers
inline float rem(int num_1, int num_2)
{
    return (num_1 % num_2);
}

// Function for finding power of a number
inline float powe(float num_1, int power)
{
    float z = num_1;
    for (int i = 1; i < power; i++)
    {
        num_1 = z * num_1;
    }
    return num_1;
}

// Function for finding the square root of a number
inline float sqrot(float num_1)
{
    float i;
    for (i = 0.000001; i * i < num_1; i = i + 0.000001)
    {
    }
    return i;
}

// Function for finding factorial of a number
inline int fact(int num_1)
{
    if (num_1 == 1 || num_1 == 0)
    {
        return 1;
    }
    else
    {
        return (num_1 * (fact(num_1 - 1)));
    }
}

// Function for finding Percentage of a number
inline float per(float num_1, float perc)
{
    float percent = (perc / num_1) * 100;
    return percent;
}

// Using switch for creating menu

int main()

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
    int Choice, power;
    float num_1, num_2, perc;
    cout << "Enter your operation from menu " << endl;
    cin >> Choice;
    switch (Choice)
    {
    case 1:
        cout << "Enter your First number for Addition : " << endl;
        cin >> num_1;
        cout << "Enter your Second number for Addition : " << endl;
        cin >> num_2;
        cout << "The Addition of two numbers is : " << add(num_1, num_2) << endl;
        break;
    case 2:
        cout << "Enter your First number for subtraction : " << endl;
        cin >> num_1;
        cout << "Enter your Second number for subtraction : " << endl;
        cin >> num_2;
        cout << "The substraction of two numbers is : " << diff(num_1, num_2) << endl;
        break;
    case 3:
        cout << "Enter your First number for Multiply : " << endl;
        cin >> num_1;
        cout << "Enter your Second number for Multiply : " << endl;
        cin >> num_2;
        cout << "The Multiply of two numbers is :  " << multiply(num_1, num_2) << endl;
        break;
    case 4:
        cout << "Enter your First number for Division : " << endl;
        cin >> num_1;
        cout << "Enter your Second number for Division : " << endl;
        cin >> num_2;
        cout << "The Division of two numbers is : " << div(num_1, num_2) << endl;
        break;
    case 5:
        cout << "Enter your First number for Reminder : " << endl;
        cin >> num_1;
        cout << "Enter your Second number for Reminder : " << endl;
        cin >> num_2;
        cout << "The Reminder of two numbers is : " << rem(num_1, num_2) << endl;
        break;
    case 6:
        cout << "Enter your number for finding power : " << endl;
        cin >> num_1;
        cout << "Enter thr power for number : " << endl;
        cin >> power;
        cout << "The Power of a number is : " << powe(num_1, power) << endl;
        break;
    case 7:
        cout << "Enter your number for finding root : " << endl;
        cin >> num_1;
        cout << "The Root of a number is : " << sqrot(num_1) << endl;
        break;
    case 8:
        cout << "Enter your number for finding Factorial : " << endl;
        cin >> num_1;
        cout << "The Factorial of a number is : " << fact(num_1) << endl;
        break;
    case 9:
        cout << "Enter your number for finding its Percentage : " << endl;
        cin >> num_1;
        cout << "Enter the percent u need : " << endl;
        cin >> perc;
        cout << "The Percentage of a number is : " << per(num_1, perc) << endl;
        break;
    default:
        cout << "Your choice is invalid...Please make a valid choice.....";
        break;
    }

    return 0;
}