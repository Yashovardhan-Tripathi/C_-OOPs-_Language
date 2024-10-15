#include <iostream>
using namespace std;

class ClassB;
class ClassA
{
    int numA;
    friend int add(ClassA, ClassB);

public:
    ClassA() : numA(12)
    {
    }
};

class ClassB
{
private:
    int numB;
    friend int add(ClassA, ClassB);

public:
    ClassB() : numB(45)
    {
    }
};

int add(ClassA objectA, ClassB objectB)
{
    return (objectA.numA + objectB.numB);
}

int main()
{
    cout << "Name:Yashovardhan Tripathi" << endl;
    cout << "PRN No.:230105231360" << endl;
    cout << "Division: D" << endl;
    cout << "Roll No.:14" << endl;
    cout << "Experiment No:04" << endl;
    ClassA objectA;
    ClassB objectB;
    cout<<"Sum : "<<add(objectA,objectB)<<endl;
    return 0;
}