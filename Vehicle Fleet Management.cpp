#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

// Base class
class Vehicle
{
protected:
    string vehicleId;
    string registrationNumber;
    double fuelLevel;

public:
    // Constructor
    Vehicle(string vid, string reg)
        : vehicleId(vid),
          registrationNumber(reg),
          fuelLevel(100.0)
    {
    }

    // Start engine
    void startEngine() const
    {
        cout << "Vehicle " << vehicleId
             << " engine started." << endl;
    }

    // Refuel vehicle
    void refuel(double amount)
    {
        fuelLevel += amount;

        if (fuelLevel > 100.0)
        {
            fuelLevel = 100.0;
        }
    }

    // Display vehicle information
    virtual void displayInfo() const
    {
        cout << "Vehicle ID: " << vehicleId
             << " | Registration: " << registrationNumber
             << " | Fuel: " << fuelLevel << "%"
             << endl;
    }

    // Virtual destructor
    virtual ~Vehicle() = default;
};

// Truck class
class Truck : public Vehicle
{
private:
    double cargoCapacity;

public:
    // Constructor
    Truck(string vid, string reg, double capacity)
        : Vehicle(vid, reg),
          cargoCapacity(capacity)
    {
    }

    // Display truck information
    void displayInfo() const override
    {
        cout << "Truck | ";

        Vehicle::displayInfo();

        cout << "Cargo capacity: "
             << cargoCapacity
             << " tonnes"
             << endl;
    }
};

// Delivery Van class
class DeliveryVan : public Vehicle
{
private:
    int packageCount;

public:
    // Constructor
    DeliveryVan(string vid, string reg, int packages)
        : Vehicle(vid, reg),
          packageCount(packages)
    {
    }

    // Display delivery van information
    void displayInfo() const override
    {
        cout << "Delivery Van | ";

        Vehicle::displayInfo();

        cout << "Packages loaded: "
             << packageCount
             << endl;
    }
};

// Bike class
class Bike : public Vehicle
{
private:
    bool hasDeliveryBox;

public:
    // Constructor
    Bike(string vid, string reg, bool hasBox)
        : Vehicle(vid, reg),
          hasDeliveryBox(hasBox)
    {
    }

    // Display bike information
    void displayInfo() const override
    {
        cout << "Delivery Bike | ";

        Vehicle::displayInfo();

        cout << "Delivery box: "
             << (hasDeliveryBox ? "Available" : "Not available")
             << endl;
    }
};

int main()
{
    // Create a fleet of vehicles
    vector<unique_ptr<Vehicle>> fleet;

    // Add a truck
    fleet.push_back(
        make_unique<Truck>(
            "V001",
            "MH12-AB-1234",
            10.5
        )
    );

    // Add a delivery van
    fleet.push_back(
        make_unique<DeliveryVan>(
            "V002",
            "MH12-CD-5678",
            50
        )
    );

    // Add a delivery bike
    fleet.push_back(
        make_unique<Bike>(
            "V003",
            "MH12-EF-9012",
            true
        )
    );

    // Display fleet status
    cout << "=== Fleet Status ===" << endl;

    for (const auto& vehicle : fleet)
    {
        vehicle->startEngine();

        vehicle->displayInfo();

        cout << endl;
    }

    return 0;
}