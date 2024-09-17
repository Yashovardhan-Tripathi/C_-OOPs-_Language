#include <iostream>
using namespace std;
int main()
{
    int a[8], i, temp, j, k, n;
    cout<< "Enter size of array: " << endl;
    cin >> n;
    cout<< "Enter array elements: " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout<< "Array elements are: " << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // Selection Sort
    for (i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
        // Print array after each pass
        cout << " Sorted array after pass " << i + 1 << " is: ";
        for (k = 0; k < n; k++)
        {
            cin >> a[k];
        }
    }
    return 0;
}
