//Multiplication table 
#include<iostream>
using namespace std ;
int main()
{
    int i=1,t;
    cout<<"Enter a number for creating is table : "<<endl;
    cin>>t;
    cout<<"Table for your entered number "<<t<<endl;
    for(i;i<=10;i++)
    cout<<t<<" * "<<i<<" = "<<(t*i)<<endl;
    return 0;
}

