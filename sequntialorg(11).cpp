#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure to hold student information
struct Student {
    string rollNumber;
    string name;
    string division;
    string address;
};

// Function prototypes
void addStudentInfo();
void deleteStudentInfo();
void displayStudentInfo();

// Function to read student information from file into string
string readStudentInfo() {
    ifstream file("student_info.txt");
    string content;
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            content += line + "\n";
        }
        file.close();
    } else {
        cerr << "Error opening file." << endl;
    }
    return content;
}

// Function to write student information from string to file
void writeStudentInfo(const string& content) {
    ofstream file("student_info.txt");
    if (file.is_open()) {
        file << content;
        file.close();
    } else {
        cerr << "Error opening file." << endl;
    }
}

// Main function
int main() {
    while (true) {
        cout << "\n1. Add Student Information" << endl;
        cout << "2. Delete Student Information" << endl;
        cout << "3. Display Student Information" << endl;
        cout << "4. Exit" << endl;
        
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addStudentInfo();
                break;
            case 2:
                deleteStudentInfo();
                break;
            case 3:
                displayStudentInfo();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}

// Function to add student information
void addStudentInfo() {
    string rollNumber, name, division, address;
    cout << "Enter Roll Number: ";
    cin >> rollNumber;
    cout << "Enter Name: ";
    cin >> name;
    cout << "Enter Division: ";
    cin >> division;
    cout << "Enter Address: ";
    cin >> address;
    
    string studentInfo = rollNumber + "," + name + "," + division + "," + address + "\n";
    string content = readStudentInfo();
    content += studentInfo;
    writeStudentInfo(content);
    
    cout << "Student information added successfully." << endl;
}

// Function to delete student information
void deleteStudentInfo() {
    string rollNumber;
    cout << "Enter Roll Number to delete: ";
    cin >> rollNumber;
    
    string content = readStudentInfo();
    size_t pos = content.find(rollNumber + ",");
    if (pos != string::npos) {
        size_t nextLine = content.find("\n", pos);
        if (nextLine != string::npos) {
            content.erase(pos, nextLine - pos + 1);
            writeStudentInfo(content);
            cout << "Student information deleted successfully." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

// Function to display student information
void displayStudentInfo() {
    string rollNumber;
    cout << "Enter Roll Number to display: ";
    cin >> rollNumber;
    
    string content = readStudentInfo();
    size_t pos = content.find(rollNumber + ",");
    if (pos != string::npos) {
        size_t nextLine = content.find("\n", pos);
        if (nextLine != string::npos) {
            string studentInfo = content.substr(pos, nextLine - pos);
            cout << studentInfo << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}
