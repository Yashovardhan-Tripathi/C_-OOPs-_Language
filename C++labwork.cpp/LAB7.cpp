#include <iostream>
#include <math.h>
using namespace std;
class complex
{
    int real, img;

public:
    void read();
    void display();
    void addition(complex c2);
    void multiplication(complex c2);
    void subtraction(complex c2);
    void division(complex c2);
    complex multiplication1(complex c3);
    void conjugate();
};
void complex ::read()
    {
        cout << "Enter Real Part Complex No." << endl;
        cin >> real;
        cout << "Enter Imaginary Par of Complex No." << endl;
        cin >> img;
    }

    void complex::display()
    {
        if (img > 0)
        {
            cout << real << "+" << img << "i" << endl;
        }
        else
        {
            int i = -img;
            cout << "Real" << " - " << img << "i" << endl;
        }
    }

    void complex::addition(complex c2)
    {
        complex sum;
        sum.real = real + c2.real;
        sum.img = img + c2.img;
        cout << "ADDITION IS = ";
        sum.display();
    }
    void complex::subtraction(complex c2)
    {
        complex diff;
        diff.real = real - c2.real;
        diff.img = img - c2.img;
        cout << "SUBTRACTION IS = ";
        diff.display();
    }

    void complex::multiplication(complex c2)
    {
        complex product;
        product.real = real * c2.real - img * c2.img;
        product.img = img * c2.real + real * c2.img;
        cout << "MULTIPLICATION IS = ";
        product.display();
    }

    complex complex::multiplication1(complex c3)
    {
        complex product;
        product.real = real * c3.real - img * c3.img;
        product.real = real * c3.real + img * c3.img;
        return product;
    }
    void complex::division(complex c2)
    {
        float div, r, i;
        div = (pow(c2.real, 2) + pow(c2.img, 2));
        complex c3, c4;
        c3.real = c2.real;
        c3.img = -c2.img;
        c4 = multiplication1(c3);
        r = c4.real / div;
        i = c4.img / div;
        cout << "DIVISION IS = ";
        if (i > 0)
        {
            cout << r << "+" << i << "i" << endl;
        }
        else
        {
            int a = -i;
            cout << r << "-" << a << "i" << endl;
        }
    }
    void complex::conjugate()
    {
        complex c;
        c.real=real;
        c.img= -img;
        cout<<"COMPLEX CONJUGATE IS = ";
        c.display();
    }
int main()
{
    
    cout << "Name:Yashovardhan Tripathi" << endl;
    cout << "PRN No.:230105231360" << endl;
    cout << "Division: D" << endl;
    cout << "Roll No.:14" << endl;
    cout << "Experiment No:07" << endl;
    complex c1, c2;
    c1.read();
    c2.read();
    c1.display();
    c2.display();
    c1.addition(c2);
    c1.subtraction(c2);
    c1.multiplication(c2);
    c1.division(c2);
    c1.conjugate();
    c2.conjugate();

    return 0;
}