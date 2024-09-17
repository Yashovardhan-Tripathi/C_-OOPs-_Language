#include<iostream>
using namespace std;
union money
{
    int rice ;
    float rupee;
    char car ;
};


int main()
{
    union money m1;
    m1.car='f';
    m1.rupee=25.5;
    cout<<m1.rupee;
    
return 0;
}