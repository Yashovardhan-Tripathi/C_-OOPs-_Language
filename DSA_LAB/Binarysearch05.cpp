#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{

    int Array[10];
    int number_ele;
    cout << "Enter the number of elements in array is: " << endl;
    cin >> number_ele;
    cout << "Enter the elements for Array :" << endl;
    for (int v = 0; v < number_ele; v++)
    {
        cin >> Array[v];
    }
    for (int i = 1; i < number_ele; i++)
    {
        for (int j = 0; j < number_ele-i; j++)
        {
            if (Array[j] > Array[j+1])
            {
                int num = Array[j];
                Array[j] = Array[j+1];
                Array[j+1] = num;
            }
        }
    }
    cout << "The sorted array is :" << endl;
    for (int g = 0; g < number_ele; g++)
    {
        cout << Array[g]<<" ";
    }

    return 0;
}