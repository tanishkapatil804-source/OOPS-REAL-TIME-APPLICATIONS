#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Soil Sensor Class
class SoilSensor
{
private:
    string sensorId;
    double moistureLevel;
    string timestamp;

public:
    // Constructor
    SoilSensor(string id, double moisture, string time)
    {
        sensorId = id;
        moistureLevel = moisture;
        timestamp = time;
    }

    // Function to update sensor reading
    void readSensor(double newMoisture, string newTime)
    {
        moistureLevel = newMoisture;
        timestamp = newTime;
    }

    // Function to display sensor data
    void displayData() const
    {
        cout << "Sensor: " << sensorId
             << " | Moisture: " << moistureLevel << "%"
             << " | Time: " << timestamp << endl;
    }
};

int main()
{
    // Create a vector to store soil sensors
    vector<SoilSensor> farmSensors;

    // Add sensors
    farmSensors.emplace_back("S001", 45.2, "08:00");
    farmSensors.emplace_back("S002", 52.8, "08:00");
    farmSensors.emplace_back("S003", 38.5, "08:00");

    // Display morning readings
    cout << "=== Morning Sensor Readings ===" << endl;

    for (const auto& sensor : farmSensors)
    {
        sensor.displayData();
    }

    // Update first sensor
    farmSensors[0].readSensor(47.5, "09:00");

    // Display updated reading
    cout << endl;
    cout << "=== Updated Reading ===" << endl;

    farmSensors[0].displayData();

    return 0;
}