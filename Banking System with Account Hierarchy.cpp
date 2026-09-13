#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <iomanip>

using namespace std;

// Base Account Class
class Account
{
protected:
    int accountNumber;
    string holderName;
    double balance;

public:
    // Constructor
    Account(int accNo, string name, double bal)
        : accountNumber(accNo), holderName(name), balance(bal)
    {
    }

    // Deposit money
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Rs. " << amount << " deposited successfully." << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Virtual withdrawal function
    virtual void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Rs. " << amount << " withdrawn successfully." << endl;
        }
        else
        {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }

    // Pure virtual interest function
    virtual double calculateInterest() const = 0;

    // Virtual display function
    virtual void displayAccount() const
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    // Virtual destructor
    virtual ~Account() = default;
};

// Savings Account
class SavingsAccount : public Account
{
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal, double rate)
        : Account(accNo, name, bal), interestRate(rate)
    {
    }

    // Calculate savings interest
    double calculateInterest() const override
    {
        return balance * interestRate / 100;
    }

    // Display savings account
    void displayAccount() const override
    {
        cout << "\n--- Savings Account ---" << endl;
        Account::displayAccount();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Interest: Rs. " << calculateInterest() << endl;
    }
};

// Current Account
class CurrentAccount : public Account
{
private:
    double minimumBalance;

public:
    CurrentAccount(int accNo, string name, double bal, double minBal)
        : Account(accNo, name, bal), minimumBalance(minBal)
    {
    }

    // Current account usually has no interest
    double calculateInterest() const override
    {
        return 0.0;
    }

    // Withdrawal with minimum balance rule
    void withdraw(double amount) override
    {
        if (amount > 0 && balance - amount >= minimumBalance)
        {
            balance -= amount;
            cout << "Rs. " << amount
                 << " withdrawn successfully." << endl;
        }
        else
        {
            cout << "Withdrawal denied. Minimum balance of Rs. "
                 << minimumBalance
                 << " must be maintained." << endl;
        }
    }

    // Display current account
    void displayAccount() const override
    {
        cout << "\n--- Current Account ---" << endl;
        Account::displayAccount();
        cout << "Minimum Balance: Rs. "
             << minimumBalance << endl;
        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }
};

// Fixed Deposit Account
class FixedDepositAccount : public Account
{
private:
    double interestRate;
    int durationYears;

public:
    FixedDepositAccount(int accNo, string name, double bal,
                        double rate, int years)
        : Account(accNo, name, bal),
          interestRate(rate),
          durationYears(years)
    {
    }

    // Calculate fixed deposit interest
    double calculateInterest() const override
    {
        return balance * interestRate * durationYears / 100;
    }

    // Withdrawal is restricted before maturity
    void withdraw(double amount) override
    {
        cout << "Withdrawal is not allowed from Fixed Deposit "
             << "before maturity." << endl;
    }

    // Display fixed deposit account
    void displayAccount() const override
    {
        cout << "\n--- Fixed Deposit Account ---" << endl;
        Account::displayAccount();
        cout << "Interest Rate: "
             << interestRate << "%" << endl;
        cout << "Duration: "
             << durationYears << " years" << endl;
        cout << "Interest: Rs. "
             << calculateInterest() << endl;
        cout << "Maturity Amount: Rs. "
             << balance + calculateInterest() << endl;
    }
};

int main()
{
    // Create accounts
    vector<unique_ptr<Account>> accounts;

    accounts.push_back(
        make_unique<SavingsAccount>(
            1001,
            "Rahul",
            50000,
            6.0
        )
    );

    accounts.push_back(
        make_unique<CurrentAccount>(
            1002,
            "Priya",
            100000,
            10000
        )
    );

    accounts.push_back(
        make_unique<FixedDepositAccount>(
            1003,
            "Amit",
            200000,
            7.5,
            3
        )
    );

    cout << fixed << setprecision(2);

    cout << "========================================" << endl;
    cout << "       BANKING SYSTEM REPORT            " << endl;
    cout << "========================================" << endl;

    // Display all accounts
    for (const auto& account : accounts)
    {
        account->displayAccount();
    }

    // Deposit money into Savings Account
    cout << "\n=== Transaction: Savings Account ===" << endl;
    accounts[0]->deposit(10000);

    // Withdraw money from Current Account
    cout << "\n=== Transaction: Current Account ===" << endl;
    accounts[1]->withdraw(20000);

    // Try to withdraw from Fixed Deposit
    cout << "\n=== Transaction: Fixed Deposit ===" << endl;
    accounts[2]->withdraw(10000);

    // Display updated accounts
    cout << "\n========================================" << endl;
    cout << "       UPDATED ACCOUNT DETAILS          " << endl;
    cout << "========================================" << endl;

    for (const auto& account : accounts)
    {
        account->displayAccount();
    }

    return 0;
}