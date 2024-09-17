#include <iostream>
#include <string>
using namespace std;
//Making the class
class BankAccount
{
private:
    long long int accountNumber;
    string accountHolderName;
    float balance;

public:
    // Constructor to initialize the account
    BankAccount(const long long int number, const string &name, float initialBalance)
    {
        accountNumber = number;
        accountHolderName = name;
        balance = initialBalance;
    }                   
    // Initalizing the funtions
    void deposit(float amount);
    void withdraw(float amount);
    void displayAccountInfo();
};
//Ending of class


// Defining the initalized functions

//  Deposit money into the account
void BankAccount ::deposit(float amount)
{
    balance += amount;
}
// Withdraw money from the account
void BankAccount ::withdraw(float amount)
{
    if (balance >= amount)
    {
        balance -= amount;
    }
    else
    {
        cout << ("Insufficient balance")<<endl;
    }
}
// Display account information
void BankAccount ::displayAccountInfo()
{
    cout << "Account Number:" << accountNumber << endl;
    cout << "Account Holder: " << accountHolderName << endl;
    cout << "Balance: " << balance << endl;
}
int main()
{
    BankAccount account(230105231360, "Yashovardhan Tripathi", 500.6);
    account.deposit(0.4);
    account.withdraw(1.0);
    account.displayAccountInfo();

    return 0;
}