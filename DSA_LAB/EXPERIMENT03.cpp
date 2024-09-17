#include <iostream>
#include <string.h>
using namespace std;

#define MAX_ENTRIES 100
char keys[MAX_ENTRIES][20];
char values[MAX_ENTRIES][50];
int numEntries = 0;
int main()
{
    strcpy(keys[numEntries], "001 ");
    strcpy(values[numEntries], "John Doe");
    numEntries++;
    strcpy(keys[numEntries], "002 ");
    strcpy(values[numEntries], "Jane Smith");
    numEntries++;
    strcpy(keys[numEntries], "003 ");
    strcpy(values[numEntries], "Alice Johnson");
    numEntries++;
    cout << ("Database contents: ") << endl;
    for (int i = 0; i < numEntries; i++)
    {
        cout << keys[i] << values[i] << endl;
    }
    for (int i = 0; i < numEntries; i++)
    {
        if (strcmp(keys[i], "002") == 0)
        {
            for (int j = i; j < numEntries - 1; j++)
            {

                strcpy(keys[j], keys[j + 1]);
                strcpy(values[j], values[j + 1]);
            }
            numEntries--;
            break;
        }
    }
    for (int i = 0; i < numEntries; i++)
    {
        if (strcmp(keys[i], "001") == 0)
        {
            strcpy(values[i], "John Smith");
            break;
        }
    }
    for (int i = 0; i < numEntries; i++)
    {
        if (strcmp(keys[i], "003") == 0)
        {
            cout << "Entry found: " << values[i] << endl;
            break;
        }
    }
    char tempKey[20];
    char tempValue[50];
    for (int i = 0; i < numEntries - 1; i++)
    {
        for (int j = 0; j < numEntries - i - 1; j++)
        {
            if (strcmp(keys[j], keys[j + 1]) > 0)
            {
                strcpy(tempKey, keys[j]);
                strcpy(tempValue, values[j]);
                strcpy(keys[j], keys[j + 1]);
                strcpy(values[j], values[j + 1]);
                strcpy(keys[j + 1], tempKey);
                strcpy(values[j + 1], tempValue);
            }
        }
    }
    cout << "Sorted Database: " << endl;
    for (int i = 0; i < numEntries; i++)
    {
        cout << keys[i] << values[i] << endl;
    }
    return 0;
}
