#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    int rollNo;
    string name;
    int totalDays;
    int presentDays;

public:
    // Constructor
    Student(int r, string n)
        : rollNo(r), name(n), totalDays(0), presentDays(0)
    {
    }

    // Mark attendance
    void markAttendance(bool isPresent)
    {
        totalDays++;

        if (isPresent)
        {
            presentDays++;
        }
    }

    // Calculate attendance percentage
    double getAttendancePercentage() const
    {
        if (totalDays == 0)
        {
            return 0.0;
        }

        return (presentDays * 100.0) / totalDays;
    }

    // Display student details
    void display() const
    {
        cout << "Roll: " << rollNo
             << " | Name: " << name
             << " | Attendance: "
             << getAttendancePercentage()
             << "%" << endl;
    }
};

int main()
{
    // Create two student objects
    Student s1(101, "Rahul");
    Student s2(102, "Priya");

    // Rahul's attendance
    s1.markAttendance(true);
    s1.markAttendance(true);
    s1.markAttendance(false);

    // Priya's attendance
    s2.markAttendance(true);
    s2.markAttendance(true);
    s2.markAttendance(true);

    // Display attendance report
    cout << "=== Attendance Report ===" << endl;

    s1.display();
    s2.display();

    return 0;
}