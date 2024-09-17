#include <stdio.h>
#include <conio.h>
void main()
{
    int a[8], i, temp, j, k, n;
    //clrscr();
    printf("\n Enter size of array:");
    scanf("%d", &n);
    printf("\n Enter array elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n Array elements are:");
    for (i = 0; i < n; i++)
    {
        printf("\n %d", a[i]);
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
        printf("\n Sorted array is:");
        for (k = 0; k < n; k++)
        {
            printf("\n%d", a[k]);
        }
    }
    getch();
}