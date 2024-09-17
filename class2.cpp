#include<iostream>
using namespace std;
class Animal
{
    private:
    int legs,hand,eye;
    public:
    char sound;
    void parts(int a, int b, int c);
    void printparts();
};
void Animal::parts(int a, int b, int c)
{
    legs=a;
    hand=b;
    eye=c;
}

void Animal::printparts()
{
    cout<<"Total legs of animals are "<<legs<<endl;
    cout<<"Total hand of animals are "<<hand<<endl;
    cout<<"Total eye of animals are "<<eye<<endl;
    cout<<"Sound of animal is "<<sound<<endl;
}
int main()
{
    Animal lion;
    lion.sound='R';
    lion.parts(4,0,2);
    lion.printparts();
return 0;
}