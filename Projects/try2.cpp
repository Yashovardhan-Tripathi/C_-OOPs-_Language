// #include <iostream>
// using namespace std;

// class Base {
// public:
//     void print() {
//         cout << "Printing the Base class Content" << endl;
//     }
// };

// class Derived : public Base {
// public:
//     void print() {
//         cout << "Printing the Derived class Content" << endl;
//     }
// };

// int main() {
//     Base* geeksforgeeks = new Base();
//     geeksforgeeks->print(); // Calls Base class print()

//     Base* geeksforgeeks2 = new Derived();
//     geeksforgeeks2->print(); // Calls Derived class print()

//     delete geeksforgeeks;
//     delete geeksforgeeks2;
//     return 0;
// }
#include <iostream>
using namespace std;

int main()
{
    int c;
    cout << "Enter ";
    cin >> c;
    cout << "Your number is " << c;
    return 0;
}
