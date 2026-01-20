#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept> // For std::runtime_error
using namespace std;

void studentDetails();

void student() {
    cout << "\n Full Student Details \n";
    ifstream file;
    try {
        file.open("students.txt");
        if (!file.is_open()) {
            throw runtime_error("File 'students.txt' not found");
        }
        string name, username, roll, email;
        int age;
        // save format : name username roll email and age
        while (file >> name >> username >> roll >> email >> age) {
            cout << "Name: " << name
                 << ", Username: " << username
                 << ", Roll: " << roll
                 << ", Email: " << email
                 << ", Age: " << age << endl;
        }
        file.close();
    } catch (const exception& e) {
        // Catch the error we threw, or any other standard exception.
        cout << "Error: " << e.what() << endl;
        if (file.is_open()) {
            file.close();
        }
    }
}
