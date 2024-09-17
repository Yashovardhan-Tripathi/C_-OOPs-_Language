#include<iostream>
using namespace std;

int main()
{
    enum Meal {
        breakfast,lunch,dinner
    };
    Meal m1=lunch;
    cout<<(m1!=2)<<endl;
    // cout<<dinner<<endl;
    // cout<<breakfast<<endl;
    // cout<<lunch<<endl;


return 0;
}