//pointer $$ pointer to pointer
#include<iostream>
using namespace std;

int main()
{
    int a=3;
    int* b= &a;
    cout<<"The address of a is :"<<&a<<endl;
    cout<<"The address of a is :"<<b<<endl;
    cout<<"The value stored at address b is :"<<*b<<endl;
    //pointer to pointers
    int**c=&b;
    cout<<"The adderess of b is :"<<&b<<endl;
    cout<<"The adderess of b is :"<<c<<endl;
    cout<<"The value stored at address c is :"<<*c<<endl;
    cout<<"The value stored at address value_at(value_at(c)) is :"<<**c<<endl;
    

return 0;
}