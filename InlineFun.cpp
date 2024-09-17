//INline funnction basically works for memory efficency and take less memory and time of execution
#include<iostream>
using namespace std;

inline int product(int a , int b)
{
    return a*b;
}

int main()
{
    int a,b;
    cout<<"ENter the value of a & b "<<endl;
    cin>>a>>b;
    cout<<"the product of a and b is "<<product(a,b)<<endl;
    cout<<"the product of a and b is "<<product(a,b)<<endl;
    cout<<"the product of a and b is "<<product(a,b)<<endl;
    cout<<"the product of a and b is "<<product(a,b)<<endl;
    cout<<"the product of a and b is "<<product(a,b)<<endl;
return 0;
}