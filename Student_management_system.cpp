#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to hold student details
struct Student {
    int id;
    string name;
    int age;
    string course;
};

// Class to manage student operations
class StudentManagementSystem {
private:
    vector<Student> students; // List of students
    int nextStudentId = 1;

public:
    // Function to add a new student
    void addStudent() {
        Student newStudent;
        newStudent.id = nextStudentId++;
        cout << "Enter student name: ";
        cin >> newStudent.name;
        cout << "Enter student age: ";
        cin >> newStudent.age;
        cout << "Enter student course: ";
        cin >> newStudent.course;
        students.push_back(newStudent);
        cout << "Student added successfully with ID: " << newStudent.id << endl;
    }

    // Function to display all students
    void displayStudents() {
        if (students.empty()) {
            cout << "No students found." << endl;
            return;
        }

        cout << "\n--- List of Students ---\n";
        for (const auto& student : students) {
            cout << "ID: " << student.id << "\nName: " << student.name << "\nAge: " << student.age << "\nCourse: " << student.course << endl;
            cout << "-----------------------------" << endl;
        }
    }

    // Function to search for a student by ID
    void searchStudent() {
        int id;
        cout << "Enter student ID to search: ";
        cin >> id;

        for (const auto& student : students) {
            if (student.id == id) {
                cout << "Student found:\n";
                cout << "ID: " << student.id << "\nName: " << student.name << "\nAge: " << student.age << "\nCourse: " << student.course << endl;
                return;
            }
        }

        cout << "Student with ID " << id << " not found." << endl;
    }

    // Function to update a student's details
    void updateStudent() {
        int id;
        cout << "Enter student ID to update: ";
        cin >> id;

        for (auto& student : students) {
            if (student.id == id) {
                cout << "Enter new name (current: " << student.name << "): ";
                cin >> student.name;
                cout << "Enter new age (current: " << student.age << "): ";
                cin >> student.age;
                cout << "Enter new course (current: " << student.course << "): ";
                cin >> student.course;
                cout << "Student details updated successfully." << endl;
                return;
            }
        }

        cout << "Student with ID " << id << " not found." << endl;
    }

    // Function to delete a student
    void deleteStudent() {
        int id;
        cout << "Enter student ID to delete: ";
        cin >> id;

        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "Student deleted successfully." << endl;
                return;
            }
        }

        cout << "Student with ID " << id << " not found." << endl;
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    while (true) {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sms.addStudent();
                break;
            case 2:
                sms.displayStudents();
                break;
            case 3:
                sms.searchStudent();
                break;
            case 4:
                sms.updateStudent();
                break;
            case 5:
                sms.deleteStudent();
                break;
            case 6:
                cout << "Exiting Student Management System. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
