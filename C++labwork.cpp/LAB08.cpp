#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:

    Person(string n, int a) : name(n), age(a) {}

    virtual void display()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

    virtual ~Person() {}
};

class Engineer : public Person
{
    string field;

public:
    Engineer(string n, int a, string f) : Person(n, a), field(f) {}

    void display() override
    {
        Person::display();
        cout << "Profession: Engineer" << endl;
        cout << "Field of Engineering: " << field << endl;
    }
};
class Doctor : public Person
{
    string specialization;

public:

    Doctor(string n, int a, string spec) : Person(n, a), specialization(spec) {}

    void display() override
    {
        Person::display();
        cout << "Profession: Doctor" << endl;
        cout << "Specialization: " << specialization << endl;
    }
};
class Student : public Person
{
    string major;

public:
    Student(string n, int a, string m) : Person(n, a), major(m) {}

    void display() override
    {
        Person::display();
        cout << "Profession: Student" << endl;
        cout << "Major: " << major << endl;
    }
};

class Laborer : public Person
{
    string jobType;

public:

    Laborer(string n, int a, string j) : Person(n, a), jobType(j) {}

    void display() override
    {
        Person::display();
        cout << "Profession: Laborer" << endl;
        cout << "Type of Job: " << jobType << endl;
    }
};

Person *createPerson(int choice)
{
    string name;
    int age;

    cout << "Enter name: ";
    cin >> name;
    cout << "Enter age: ";
    cin >> age;

    switch (choice)
    {
    case 1:
    {
        string field;
        cout << "Enter field of engineering: ";
        cin >> field;
        return new Engineer(name, age, field);
    }
    case 2:
    {
        string specialization;
        cout << "Enter specialization: ";
        cin >> specialization;
        return new Doctor(name, age, specialization);
    }
    case 3:
    {
        string major;
        cout << "Enter major: ";
        cin >> major;
        return new Student(name, age, major);
    }
    case 4:
    {
        string jobType;
        cout << "Enter type of job: ";
        cin >> jobType;
        return new Laborer(name, age, jobType);
    }
    default:
        return nullptr;
    }
}

int main()
{

    cout << "Name:Yashovardhan Tripathi" << endl;
    cout << "PRN No.:230105231360" << endl;
    cout << "Division: D" << endl;
    cout << "Roll No.:14" << endl;
    cout << "Experiment No:08" << endl
         << endl;

    vector<Person *> people;
    int numPeople, choice;

    cout << "How many people do you want to enter in the database? ";
    cin >> numPeople;

    for (int i = 0; i < numPeople; ++i)
    {
        cout << "\nEnter details for person " << i + 1 << ":" << endl;
        cout << "Choose profession:" << endl;
        cout << "1. Engineer" << endl;
        cout << "2. Doctor" << endl;
        cout << "3. Student" << endl;
        cout << "4. Laborer" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        Person *person = createPerson(choice);
        if (person)
        {
            people.push_back(person);
        }
        else
        {
            cout << "Invalid profession choice!" << endl;
        }
    }

    cout << "\nDisplaying details of all people:" << endl;
    for (Person *person : people)
    {
        person->display();
        cout << endl;
    }
    for (Person *person : people)
    {
        delete person;
    }

    return 0;
}
