//area of shapes
#include<iostream>
using namespace std;

int area(int a)
{
    return (a*a);
}
int area(int a, float b)
{
    return(a*b);
}

int main()
{
    int side,length;
    float height;
    cout<<"Enter the dimensions in serial side , height"<<endl;
    cin>> side >>height;
    cout<<"Area of square of side "<<side<<" is "<<area(side)<<endl;
    cout<<"Area of rectangle of side "<<side << " and "<< height <<" is "<<area(side,height)<<endl;
return 0;
}