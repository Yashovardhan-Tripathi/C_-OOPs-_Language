#include<iostream>
using namespace std;

int sum(int a, int b);
int main()
{
    cout<<"sum of numbers is "<<sum(5,10)<<endl;    
return 0;
}

int sum(int a, int b)
{
    int c =a+b;
    return c;
}