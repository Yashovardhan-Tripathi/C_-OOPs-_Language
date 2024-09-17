//code for finding a term of fibbonaci series in enterd position.
#include<iostream>
using namespace std;

int fib(int x)
{
    if(x<2)
    {
    return 1;  
    }
    else
    {
        return fib(x-2) + fib(x-1);
    }
}

int main()
{
    int term;
    cout<<"Enter the term for fibbonace series "<<endl;
    cin>>term;
    cout<<"The element present at term "<<term<<" is "<<fib(term)<<endl;    
return 0;
}