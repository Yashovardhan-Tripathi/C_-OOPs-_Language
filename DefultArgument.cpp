#include<iostream>
using namespace std;

float moneyrecieve(int money,float factor=1.04)
{
    return money*factor;
}

int main()
{
    int money=10000;
    cout<<"If u have "<<money<<"Rs in your bank account , you will get "<<moneyrecieve(money)<<"Rs after 1 year."<<endl;
    cout<<"FOR VIP:-If u have "<<money<<"Rs in your bank account , you will get "<<moneyrecieve(money,1.1)<<"Rs after 1 year."<<endl;
return 0;
}