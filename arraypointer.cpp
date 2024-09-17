#include<iostream>
using namespace std;

int main()
{
    int marks[4]={35,23,98,53};
    int* p = marks;
    cout<<"The value of *p = "<<*p<<endl;
    cout<<"The value of *(p+1) = "<<*(p+1)<<endl;
    cout<<"The value of *(p+2) = "<<*(p+2)<<endl;
    cout<<"The value of *(p+3) = "<<*(p+3)<<endl;

return 0;
}