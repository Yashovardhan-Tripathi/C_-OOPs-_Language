#include<iostream>
using namespace std;

typedef struct employee
{
    int eId;
    char favChar;
    float salary;
} ep;


int main()
{
    ep yash;
    yash.eId = 5;
    yash.favChar = 'Y';
    yash.salary = 256.5;
    cout<<"Thr value is "<<yash.eId<<endl;
    cout<<"Thr value is "<<yash.favChar<<endl;
    cout<<"Thr value is "<<yash.salary<<endl;

    
return 0;
}