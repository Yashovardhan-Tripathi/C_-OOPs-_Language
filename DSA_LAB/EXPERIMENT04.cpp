#include <iostream>
using namespace std;
int main()
{
    int a[8], i, temp, j, k, n;
    cout << "Enter size of array:" << endl;
    cin >> n;
    cout << "Enter array elements:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << " Array elements are:" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (i = 1; i < n; i++) // passes
    {
        for (j = 0; j < n - i; j++) // inner element
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        // print resultant array
        cout << "Sorted array is: " << endl;
        for (k = 0; k < n; k++)
        {
            cin >> a[k];
            cout << endl;
        }
    }
    return 0;
}