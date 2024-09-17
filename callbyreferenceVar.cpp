//swaping two numbers using pointer variables
#include<iostream>
using namespace std;

void swapPointer(int& a, int& b)
{
    int temp = a;
    a=b;
    b=temp;
}
int main()
{
    int x=5, y=10;
    cout<<"The value of x is "<<x<<" and value of y is "<<y<<endl;
    swapPointer(x,y);
    cout<<"The value of x is "<<x<<" and value of y is "<<y<<endl;
    
return 0;
}