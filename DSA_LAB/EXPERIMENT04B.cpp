#include <iostream>
using namespace std;
int main()
{
    int a[8], i, temp, j, k, n;
    cout << " Enter size of array: " << endl;
    cin >> n;
    cout << " Enter array elements: " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << " Array elements are: " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        cout << endl;
    }
    // Insertion Sort
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];

            j--;
        }
        a[j + 1] = temp;
            // Print array after each pass
            cout<<" Sorted array after pass "<<i<< " is: ";
        for (k = 0; k < n; k++)
        {
            cin>> a[k];
        }
    }
    return 0;
}