#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    char className;
    int rollNumber;
    int marks;

public:
    // Constructor to initialize member variables
    Student(string n, char c, int r, int m) {
        name = n;
        className = c;
        rollNumber = r;
        marks = m;
    }

    // Function to calculate the grade based on marks
    char calculateGrade() {
        if (marks >= 90) {
            return 'A';
        } else if (marks >= 80) {
            return 'B';
        } else if (marks >= 70) {
            return 'C';
        } else if (marks >= 60) {
            return 'D';
        } else {
            return 'F';
        }
    }

    // Function to display student's information
    void displayInfo() {
        cout << "Student details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Class: " << className << endl;
        cout << "Roll number: " << rollNumber << endl;
        cout << "Marks (0-100): " << marks << endl;
    }
};

int main() {
    // Create a Student object with given details
    Student student("Mohamed Ali", 'A', 3, 98);

    // Display student's information
    student.displayInfo();

    // Calculate and display the grade
    char grade = student.calculateGrade();
    cout << "Grade: " << grade << endl;

    return 0;
}
