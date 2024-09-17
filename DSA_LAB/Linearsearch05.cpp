//Linear search 
#include <iostream>
using namespace std;

int main()
{
    int ray[10];
    int i, key, n;
    cout << "Enter the Array values: " << endl;
    for (i = 0; i < 10; i++)
    {
        cin >> ray[i];
    }
    cout << "Enter a number to be searched in array" << endl;
    cin >> key;
    int find = 0;
    for (n = 0; n < i; n++)
    {
        if (ray[n] == key)
        {
            cout << "Element found at index " << n << endl;
            find = 1;
            break;
        }
    }
    if (!find)
    {
        cout << "Not found" << endl;
    }
    return 0;
}