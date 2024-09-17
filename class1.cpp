#include<iostream>
using namespace std;
class Employee //Creating a class named it as Employee
{
    private:
    int a,b,c;
    public:
    int d,e;
    void setData(int a1, int b1, int c1);
    void getData()
    {
        cout<<"The value of a is "<<a<<endl;        
        cout<<"The value of b is "<<b<<endl;        
        cout<<"The value of c is "<<c<<endl;        
        cout<<"The value of d is "<<d<<endl;        
        cout<<"The value of e is "<<e<<endl;        
    }
};
void Employee::setData(int a1,int b1, int c1)
{
    a=a1;
    b=b1;
    c=c1;
}
int main()
{
    Employee yash; //Creating a object named it as yash 
    yash.d=10;
    yash.e=15;
    yash.setData(1,5,9);
    yash.getData();
return 0;
}