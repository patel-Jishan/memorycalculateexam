#include <iostream>
#include <vector>
#include <string>
using namespace std;


template <typename T>
class MemoryCalculate {
private:
    T id;
    string name;

public:
   
    MemoryCalculate(T studentId, string studentName) {
        id = studentId;
        name = studentName;
    }

  
    void displayDetails() {
        cout << "Student ID: " << id << ", Name: " << name <<endl;
    }

   
    T getId() {
        return id;
    }

   
    string getName() {
        return name;
    }
};


template <typename T>
class StudentManagementSystem {
private:
    vector<MemoryCalculate<T>> students;

public:
    
    void addStudent(T id, string name) {
        
        int existCount = 0;
        for (MemoryCalculate<T>& student : students) {
            if (student.getId() == id) {
                existCount++;
            }
        }
        
        if (existCount == 0) {
            students.push_back(MemoryCalculate<T>(id, name));
            cout << "Student added successfully!" << endl;
        } else {
            cout << "Student with ID " << id << " already exists." << endl;
        }
    }


    void displayAllStudents() {
        int studentCount = students.size();
        
        if (studentCount == 0) {
            cout << "No students in the system." << endl;
            return;
        }

        cout << "Student List:" << endl;
        for (MemoryCalculate<T>& student : students) {
            student.displayDetails();
        }
    }

   
    void removeStudent(T id) {
        int removeIndex = -1;
        
        
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                removeIndex = i;
                break;
            }
        }
        
       
        if (removeIndex != -1) {
            students.erase(students.begin() + removeIndex);
            cout << "Student with ID " << id << " removed successfully!" << endl;
        } else {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

 
    void searchStudent(T id) {
        int foundIndex = -1;
        
     
        for (int i = 0; i < students.size(); i++) {
            if (students[i].getId() == id) {
                foundIndex = i;
                break;
            }
        }
        
    
        if (foundIndex != -1) {
            cout << "Student Found:" << endl;
            students[foundIndex].displayDetails();
        } else {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }
};


int main() {
    StudentManagementSystem<int> studentSystem;
    int choice, id;
    string name;

    while (1) {
       
        
        cout<<"* * * * * * * * * * * * * * * * * * * * * *"<<endl;
        cout<<"|=======Student Management System=======|"<<endl;
        cout<<"-------------------------------------------"<<endl;
        cout<<"*       ---1.Add Student---            *"<<endl;
        cout<<"*       ---2.Display All Students---   *"<<endl;
        cout<<"*       ---3.Search Student---         *"<<endl;
        cout<<"*       ---4.Remove Student---         *"<<endl;
        cout<<"*       ---5.Exit***                   *"<<endl;
        cout<<"-------------------------------------------"<<endl;  
        cout<<"* * * * * * * * * * * * * * * * * * * * * *"<<endl;
        
        cout<<"Enter the choice:";
        cin>>choice;

       
        switch (choice) {
            case 1:
                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter Student Name: ";
                cin.ignore(); 
                getline(cin, name);
                studentSystem.addStudent(id, name);
                break;

            case 2:
                studentSystem.displayAllStudents();
                break;

            case 3:
                cout << "Enter Student ID to search: ";
                cin >> id;
                studentSystem.searchStudent(id);
                break;

            case 4:
                cout << "Enter Student ID to remove: ";
                cin >> id;
                studentSystem.removeStudent(id);
                break;

            case 5:
                cout << "Exiting Student Management System. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }


}