#include <iostream>
#include <math.h>
using namespace std;

class complex
{
    int real, img;

public:
    complex() : real(0), img(0) {}
    complex(int r, int i) : real(r), img(i) {}

    void read();
    void display() const;

    complex operator+(const complex &c2);
    complex operator-(const complex &c2);
    complex operator*(const complex &c2);
    complex operator/(const complex &c2);

    complex operator~();
};

void complex::read()
{
    cout << "Enter Real Part of Complex No.: ";
    cin >> real;
    cout << "Enter Imaginary Part of Complex No.: ";
    cin >> img;
}

void complex::display() const
{
    if (img >= 0)
        cout << real << " + " << img << "i" << endl;
    else
        cout << real << " - " << -img << "i" << endl;
}

complex complex::operator+(const complex &c2)
{
    complex sum;
    sum.real = real + c2.real;
    sum.img = img + c2.img;
    return sum;
}

complex complex::operator-(const complex &c2)
{
    complex diff;
    diff.real = real - c2.real;
    diff.img = img - c2.img;
    return diff;
}

complex complex::operator*(const complex &c2)
{
    complex product;
    product.real = real * c2.real - img * c2.img;
    product.img = real * c2.img + img * c2.real;
    return product;
}

complex complex::operator/(const complex &c2)
{
    float div = pow(c2.real, 2) + pow(c2.img, 2);
    complex c3, result;
    c3.real = c2.real;
    c3.img = -c2.img;
    result = (*this) * c3;
    result.real = result.real / div;
    result.img = result.img / div;
    return result;
}

complex complex::operator~()
{
    return complex(real, -img);
}

int main()
{
    cout << "Name:Yashovardhan Tripathi" << endl;
    cout << "PRN No.:230105231360" << endl;
    cout << "Division: D" << endl;
    cout << "Roll No.:14" << endl;
    cout << "Experiment No:09" << endl
         << endl;

    complex c1, c2, result;
    int choice;
    bool continueProgram = true;

    cout << "Enter first complex number:" << endl;
    c1.read();
    cout << "Enter second complex number:" << endl;
    c2.read();

    while (continueProgram)
    {
        cout << endl;
        cout << "Choose the operation you want to perform:" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Conjugate of first complex number" << endl;
        cout << "6. Conjugate of second complex number" << endl;
        cout << "7. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            result = c1 + c2;
            cout << "ADDITION IS = ";
            result.display();
            break;
        case 2:
            result = c1 - c2;
            cout << "SUBTRACTION IS = ";
            result.display();
            break;
        case 3:
            result = c1 * c2;
            cout << "MULTIPLICATION IS = ";
            result.display();
            break;
        case 4:
            result = c1 / c2;
            cout << "DIVISION IS = ";
            result.display();
            break;
        case 5:
            result = ~c1;
            cout << "CONJUGATE OF FIRST COMPLEX NUMBER IS = ";
            result.display();
            break;
        case 6:
            result = ~c2;
            cout << "CONJUGATE OF SECOND COMPLEX NUMBER IS = ";
            result.display();
            break;
        case 7:
            continueProgram = false;
            break;
        default:
            cout << "Invalid choice, please try again!" << endl;
        }
    }

    return 0;
}
