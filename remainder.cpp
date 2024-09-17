//Getting a remainder of 2 number
#include<iostream>
using namespace std;

int rem(int x  ,int y)
{
    int r=x%y;
    return r;
}

int main()
{
    int a,b;
    cout<<"Enter the first number"<<endl;
    cin>>a;
    cout<<"Enter the second number"<<endl;
    cin>>b;
    cout<<"The remainder of a and b is "<<rem(a,b)<<endl;
return 0;
}