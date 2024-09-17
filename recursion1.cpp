//Code for finding the factorial of a number.
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n > 1) {
        return n * factorial(n - 1);
    } else {
        return 1;
    }
}

int main() {
    int n;
    cout << "Enter a non-negative number: ";
    cin >> n;
    int result = factorial(n);
    cout << "Factorial of " << n << " = " << result;
    return 0;
}
