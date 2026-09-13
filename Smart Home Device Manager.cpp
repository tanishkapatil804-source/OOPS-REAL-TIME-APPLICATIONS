#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Smart Device Class
class SmartDevice
{
private:
    string deviceId;
    string deviceType;
    string location;
    string status;
    string lastUpdated;

public:
    // Constructor
    SmartDevice(string id, string type, string loc, string stat, string time)
    {
        deviceId = id;
        deviceType = type;
        location = loc;
        status = stat;
        lastUpdated = time;
    }

    // Switch device ON
    void switchOn(string time)
    {
        status = "ON";
        lastUpdated = time;
    }

    // Switch device OFF
    void switchOff(string time)
    {
        status = "OFF";
        lastUpdated = time;
    }

    // Change device status
    void changeStatus(string newStatus, string time)
    {
        status = newStatus;
        lastUpdated = time;
    }

    // Display device information
    void display() const
    {
        cout << "Device ID: " << deviceId
             << " | Type: " << deviceType
             << " | Location: " << location
             << " | Status: " << status
             << " | Last Updated: " << lastUpdated
             << endl;
    }
};

int main()
{
    // Create smart home devices
    vector<SmartDevice> devices;

    devices.emplace_back(
        "L001",
        "Light",
        "Living Room",
        "OFF",
        "08:00"
    );

    devices.emplace_back(
        "T001",
        "Thermostat",
        "Bedroom",
        "ON",
        "08:05"
    );

    devices.emplace_back(
        "C001",
        "Camera",
        "Main Door",
        "ON",
        "08:10"
    );

    devices.emplace_back(
        "D001",
        "Door Lock",
        "Main Door",
        "LOCKED",
        "08:15"
    );

    // Display initial dashboard
    cout << "============================================" << endl;
    cout << "          SMART HOME DASHBOARD              " << endl;
    cout << "============================================" << endl;

    for (const auto& device : devices)
    {
        device.display();
    }

    // Change device states
    devices[0].switchOn("09:00");
    devices[1].changeStatus("OFF", "09:05");
    devices[2].switchOff("09:10");
    devices[3].changeStatus("UNLOCKED", "09:15");

    // Display updated dashboard
    cout << endl;
    cout << "============================================" << endl;
    cout << "          UPDATED HOME DASHBOARD            " << endl;
    cout << "============================================" << endl;

    for (const auto& device : devices)
    {
        device.display();
    }

    return 0;
}