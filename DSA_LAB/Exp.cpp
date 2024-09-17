#include <iostream>
#include <stdlib.h>
using namespace std;

// Functions to add two Polynomiols

void addPoly(int *p1, int *p2, int *result, int n1, int n2)
{
    int maxDegree = (n1 > n2) ? n1 : n2;
    for (int i = 0; i <= maxDegree; i++)
    {
        int coeff_1 = (i <= n1) ? p1[i] : 0;
        int coeff_2 = (i <= n2) ? p2[i] : 0;
        result[i] = coeff_1 + coeff_2;
    }
}

// Function to subtract two Polynomiols

void subtractPoly(int *p1, int *p2, int *result, int n1, int n2)
{
    int maxDegree = (n1 > n2) ? n1 : n2;
    for (int i = 0; i <= maxDegree; i++)
    {
        int coeff_1 = (i <= n1) ? p1[i] : 0;
        int coeff_2 = (i <= n2) ? p2[i] : 0;
        result[i] = coeff_1 - coeff_2;
    }
}

// Functions to multiply two Polynomials

void multiPoly(int *p1, int *p2, int *result, int n1, int n2)
{
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            result[i + j] += p1[i] * p2[j];
        }
    }
}

// Function to evaluate a polynomial at a given value of x

int evaluatePoly(int *p, int degree, int x)
{
    int result = 0;
    int power = 1;
    for (int i = 0; i <= degree; i++)
    {
        result += p[i] * power;
        power *= x;
    }
    return result;
}

// Function to print a polynomial

void printPoly(int *p, int degree)
{
    for (int i = degree; i >= 0; i--)
    {
        if (p[i] != 0)
        {
            if (i != degree)
            {
                cout << ((p[i] > 0) ? "+" : "-");
            }
            if (i == 0 || p[i] != 1)
            {
                cout << abs(p[i]);
            }
            if (i > 0)
            {
                cout << "x";
                if (i > 1)
                {
                    cout << i;
                }
            }
        }
    }
}
int main()
{
    int choice, degree1, degree2;
    cout << "Enter the degree of the first polynomial: ";
    cin >> degree1;
    cout << "Enter the degree of the second polynomial: ";
    cin >> degree2;

    int *poly1 = (int *)malloc((degree1 + 1) * sizeof(int));
    int *poly2 = (int *)malloc((degree2 + 1) * sizeof(int));

    cout << "Enter coefficients for the first polynomial (highest degree first): " << endl;
    for (int i = degree1; i >= 0; i--)
    {
        cout << "Coefficient of x^" << i << " is: ";
        cin >> poly1[i];
    }
    cout << "Enter coefficients for the second polynomial (highest degree first): " << endl;
    for (int i = degree2; i >= 0; i--)
    {
        cout << "Coefficient of x^" << i << " is: ";
        cin >> poly2[i];
    }

    do
    {
        cout << endl;
        cout << "1. Add Polynomials" << endl;
        cout << "2. Subtract Polynomials" << endl;
        cout << "3. Multiply Polynomials" << endl;
        cout << "4. Evaluate Polynomials" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int maxDegree = (degree1 > degree2) ? degree1 : degree2;
            int *result = (int *)calloc(maxDegree + 1, sizeof(int));
            addPoly(poly1, poly2, result, degree1, degree2);
            cout << "Result of Addition: " << endl;
            printPoly(result, maxDegree);
            free(result);
            break;
        }
        case 2:
        {
            int maxDegree = (degree1 > degree2) ? degree1 : degree2;
            int *result = (int *)calloc(maxDegree + 1, sizeof(int));
            subtractPoly(poly1, poly2, result, degree1, degree2);
            cout << "Result of Subtraction: " << endl;
            printPoly(result, maxDegree);
            free(result);
            break;
        }
        case 3:
        {
            int resultDegree = degree1 + degree2;
            int *result = (int *)calloc(resultDegree + 1, sizeof(int));
            multiPoly(poly1, poly2, result, degree1, degree2);
            cout << "Result of Multiplication: " << endl;
            printPoly(result, resultDegree);
            free(result);
            break;
        }
        case 4:
        {
            int x;
            cout << "Enter the value of x: ";
            cin >> x;
            cout << "Polynnomial 1 Evaluation: " << evaluatePoly(poly1, degree1, x);
            cout << "Polynnomial 2 Evaluation: " << evaluatePoly(poly2, degree2, x);
            break;
        }
        case 5:
        {
            cout << "Exiting......." << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice !!!! " << endl;
            cout << "Enter your choice again " << endl;
        }
        }
    } while (choice != 5);

    free(poly1);
    free(poly2);

    return 0;
}