// Program for Prime Number in Range
#include <bits/stdc++.h>
using namespace std;
// Finding the square root of number
inline float sqrot(float num)
{
    float i;
    for (i = 0.001; i * i < num; i = i + 0.001)
    {
    }
    return i;
}

int main()
{
    int num1, num2, i, count = 0;
    cout << "Enter the Starting Number " << endl;
    cin >> num1;
    cout << "Enter the Ending Number " << endl;
    cin >> num2;

    // When the entered number are equal
    if (num1 == num2)
    {
        if (num1 == 0 || num1 == 1)
            cout << "The entered number is either 1 or 0 " << endl;
        float num = sqrot(num1);
        for (i = 2; i <= num; i++)
            if (num1 % i == 0)
            {
                count++;
                break;
            }
        if (count == 0)
        {
            cout << "The number is prime number " << num1;
        }
    }

    // When the Number_1 is greater than Number_2
    else if (num1 < num2)
    {
        if (num1 == 0 || num1 == 1)
            cout << "The entered number is either 1 or 0 " << endl;
        cout << "The Prime Number are : ";
        for (num1; num1 <= num2; num1++)
        {
            count = 0;
            if (num1 > 1)
            {
                float num = sqrot(num1);
                for (i = 2; i <= num; i++)
                    if (num1 % i == 0)
                    {
                        count++;
                        break;
                    }
                if (count == 0)
                {
                    cout << num1 << " ";
                }
            }
        }
    }

    // When the Number_2 is greater than Number_1
    else
    {
        if (num2 == 0 || num2 == 1)
            cout << "The entered number is either 1 or 0 " << endl;
        cout << "The Prime Number are : ";
        for (num2; num2 <= num1; num2++)
        {
            if (num2 > 1)
            {
                count = 0;
                float num = sqrot(num2);
                for (i = 2; i <= num; i++)
                    if (num2 % i == 0)
                    {
                        count++;
                        break;
                    }
                if (count == 0)
                {
                    cout << num2 << " ";
                }
            }
        }
    }

    return 0;
}