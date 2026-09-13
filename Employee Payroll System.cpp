#include <iostream>
#include <string>

using namespace std;

// Base class
class Employee
{
protected:
    int empId;
    string name;
    string department;

public:
    // Constructor
    Employee(int id, string n, string dept)
        : empId(id), name(n), department(dept)
    {
    }

    // Display basic employee information
    void displayBasicInfo() const
    {
        cout << "ID: " << empId
             << " | Name: " << name
             << " | Department: " << department;
    }

    // Pure virtual function
    virtual double calculateSalary() const = 0;

    // Virtual destructor
    virtual ~Employee() = default;
};

// Full-Time Employee
class FullTimeEmployee : public Employee
{
private:
    double monthlySalary;

public:
    // Constructor
    FullTimeEmployee(int id, string n, string dept, double salary)
        : Employee(id, n, dept), monthlySalary(salary)
    {
    }

    // Calculate salary
    double calculateSalary() const override
    {
        return monthlySalary;
    }

    // Display employee information
    void display() const
    {
        displayBasicInfo();

        cout << " | Type: Full-Time"
             << " | Salary: Rs. "
             << calculateSalary()
             << endl;
    }
};

// Part-Time Employee
class PartTimeEmployee : public Employee
{
private:
    double hourlyRate;
    int hoursWorked;

public:
    // Constructor
    PartTimeEmployee(int id, string n, string dept,
                     double rate, int hours)
        : Employee(id, n, dept),
          hourlyRate(rate),
          hoursWorked(hours)
    {
    }

    // Calculate salary
    double calculateSalary() const override
    {
        return hourlyRate * hoursWorked;
    }

    // Display employee information
    void display() const
    {
        displayBasicInfo();

        cout << " | Type: Part-Time"
             << " | Salary: Rs. "
             << calculateSalary()
             << endl;
    }
};

// Intern
class Intern : public Employee
{
private:
    double stipend;

public:
    // Constructor
    Intern(int id, string n, string dept,
           double stipendAmount)
        : Employee(id, n, dept),
          stipend(stipendAmount)
    {
    }

    // Calculate stipend
    double calculateSalary() const override
    {
        return stipend;
    }

    // Display employee information
    void display() const
    {
        displayBasicInfo();

        cout << " | Type: Intern"
             << " | Stipend: Rs. "
             << calculateSalary()
             << endl;
    }
};

int main()
{
    // Create Full-Time Employee
    FullTimeEmployee f1(
        101,
        "Amit",
        "IT",
        65000
    );

    // Create Part-Time Employee
    PartTimeEmployee p1(
        102,
        "Sneha",
        "HR",
        250,
        120
    );

    // Create Intern
    Intern i1(
        103,
        "Rohan",
        "Marketing",
        15000
    );

    // Display payroll
    cout << "=== Employee Payroll ===" << endl;

    f1.display();
    p1.display();
    i1.display();

    return 0;
}