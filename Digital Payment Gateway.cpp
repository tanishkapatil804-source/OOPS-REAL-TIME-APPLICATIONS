#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// Base class
class PaymentMethod
{
protected:
    string transactionId;
    double amount;

public:
    // Constructor
    PaymentMethod(string tid, double amt)
        : transactionId(tid), amount(amt)
    {
    }

    // Pure virtual function
    virtual bool processPayment() const = 0;

    // Virtual destructor
    virtual ~PaymentMethod() = default;
};

// Credit Card Payment
class CreditCardPayment : public PaymentMethod
{
private:
    string maskedCardNumber;

public:
    // Constructor
    CreditCardPayment(string tid, double amt, string card)
        : PaymentMethod(tid, amt),
          maskedCardNumber(card)
    {
    }

    // Process credit card payment
    bool processPayment() const override
    {
        cout << "Credit-card transaction "
             << transactionId
             << " for Rs. "
             << amount
             << " using "
             << maskedCardNumber
             << " completed."
             << endl;

        return true;
    }
};

// UPI Payment
class UPIPayment : public PaymentMethod
{
private:
    string upiId;

public:
    // Constructor
    UPIPayment(string tid, double amt, string upi)
        : PaymentMethod(tid, amt),
          upiId(upi)
    {
    }

    // Process UPI payment
    bool processPayment() const override
    {
        cout << "UPI transaction "
             << transactionId
             << " for Rs. "
             << amount
             << " from "
             << upiId
             << " completed."
             << endl;

        return true;
    }
};

// Net Banking Payment
class NetBankingPayment : public PaymentMethod
{
private:
    string bankName;

public:
    // Constructor
    NetBankingPayment(string tid, double amt, string bank)
        : PaymentMethod(tid, amt),
          bankName(bank)
    {
    }

    // Process Net Banking payment
    bool processPayment() const override
    {
        cout << "Net-banking transaction "
             << transactionId
             << " for Rs. "
             << amount
             << " through "
             << bankName
             << " completed."
             << endl;

        return true;
    }
};

int main()
{
    // Create a vector of smart pointers
    vector<unique_ptr<PaymentMethod>> payments;

    // Add Credit Card payment
    payments.push_back(
        make_unique<CreditCardPayment>(
            "TXN001",
            2500,
            "XXXX-XXXX1234"
        )
    );

    // Add UPI payment
    payments.push_back(
        make_unique<UPIPayment>(
            "TXN002",
            1200,
            "student@upi"
        )
    );

    // Add Net Banking payment
    payments.push_back(
        make_unique<NetBankingPayment>(
            "TXN003",
            5000,
            "Example Bank"
        )
    );

    // Display payment gateway heading
    cout << "=== Payment Gateway ===" << endl;

    // Process all payments
    for (const auto& payment : payments)
    {
        payment->processPayment();
    }

    return 0;
}