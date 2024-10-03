#include <iostream>
#include <string.h>
using namespace std;

#define MAX_RECORDS 100
#define NAME_LENGTH 50

// Define a struct for a record
typedef struct
{
    int id;
    char name[NAME_LENGTH];
    float pervalue;
} Record;

// Global array and counter for records
Record database[MAX_RECORDS];
int record_count = 0;

// Function to add a record
void addRecord()
{
    if (record_count >= MAX_RECORDS)
    {
        cout << "Database is full. Cannot add more records." << endl;
        return;
    }

    Record new_record;
    cout << "Enter ID: " << endl;
    cin >> new_record.id;
    cout << "Enter Name: " << endl;
    cin >> new_record.name;
    cout << "Enter Percentage: " << endl;
    cin >> new_record.pervalue;

    database[record_count++] = new_record;
    cout << "Record added successfully." << endl;
}
// Function to delete a record by ID
void deleteRecord()
{
    int id, i, found = 0;
    cout << "Enter ID of record to delete: " << endl;
    cin >> id;

    for (i = 0; i < record_count; i++)
    {
        if (database[i].id == id)
        {
            found = 1;
            for (int j = i; j < record_count - 1; j++)
            {
                database[j] = database[j + 1];
            }
            record_count--;
            cout << "Record deleted successfully." << endl;
            break;
        }
    }
    if (!found)
    {
        cout << "Record with ID's " << id << " not found." << endl;
    }
}

// Function to modify a record by ID
void modifyRecord()
{
    int id, found = 0;
    cout << "Enter ID of record to modify: " << endl;
    cin >> id;

    for (int i = 0; i < record_count; i++)
    {
        if (database[i].id == id)
        {
            found = 1;
            cout << "Enter new Name: " << endl;
            cin >> database[i].name;
            cout << "Enter new Value: " << endl;
            cin >> database[i].pervalue;
            cout << "Record modified successfully." << endl;
            break;
        }
    }
    if (!found)
    {
        cout << "Record with ID" << id << " not found." << endl;
    }
}

// Function to search for a record by ID
void searchRecord()
{
    int id, found = 0;
    cout << "Enter ID of record to search: " << endl;
    cin >> id;

    for (int i = 0; i < record_count; i++)
    {
        if (database[i].id == id)
        {
            cout << "Record found: " << endl;
            cout << "ID: " << database[i].id << endl;
            cout << "Name: " << database[i].name << endl;
            cout << "Value: " << database[i].pervalue << endl;
            found = 1;
            break;
        }
    }
    if (!found)
    {
        cout << "Record with ID" << id << " not found." << endl;
    }
}

// Function to sort records by ID (ascending)
void sortRecords()
{
    for (int i = 0; i < record_count - 1; i++)
    {
        for (int j = i + 1; j < record_count; j++)
        {
            if (database[i].id > database[j].id)
            {
                Record temp = database[i];
                database[i] = database[j];
                database[j] = temp;
            }
        }
    }
    cout << "Records sorted successfully." << endl;
}

// Function to display all records
void displayRecords()
{
    if (record_count == 0)
    {
        cout << "No records to display." << endl;
        return;
    }

    cout << "Displaying all records: " << endl;
    for (int i = 0; i < record_count; i++)
    {
        cout << "ID: " << database[i].id << endl;
        cout << "Name: " << database[i].name << endl;
        cout << "Value: " << database[i].pervalue << endl;
        cout << endl;
    }
}

int main()
{
    int choice;

    while (1)
    {
        cout << "Database Operations Menu:" << endl;
        cout << "1. Add Record" << endl;
        cout << "2. Delete Record" << endl;
        cout << "3. Modify Record" << endl;
        cout << "4. Search Record" << endl;
        cout << "5. Sort Records" << endl;
        cout << "6. Display Records" << endl;
        cout << "7. Exit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            addRecord();
            break;
        case 2:
            deleteRecord();
            break;
        case 3:
            modifyRecord();
            break;
        case 4:
            searchRecord();
            break;
        case 5:
            sortRecords();
            break;
        case 6:
            displayRecords();
            break;
        case 7:
            return 0;
        default:
            cout << "Invalid choice, please try again." << endl;
        }
    }
}
