#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
    int accountNumber;
    string accountHolderName;
    float balance;

public:
    // Constructor to initialize the account
    BankAccount(int number, const string &name, float initialBalance)
        : accountNumber(number), accountHolderName(name), balance(initialBalance) {}

    // Deposit money into the account
    void deposit(float amount)
    {
        balance += amount;
    }

    // Withdraw money from the account
    void withdraw(float amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient balance" << endl;
        }
    }

    // Display account information
    void displayAccountInfo()
    {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount account(12345, "John Doe", 1000.0);
    account.deposit(500.0);
    account.withdraw(200.0);
    account.displayAccountInfo();
    return 0;
}
