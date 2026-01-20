// viewstudent.cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void viewstudent() {
    cout << "\n Student Summary \n";

    ifstream file("students.txt");

    if (!file) {
        cout << "No student data found.\n";
        return;
    }

    string name, username, roll, email;
    int age;

    // we don't use username and age here, but need to read them from the file
    while (file >> name >> username >> roll >> email >> age) {
        cout << "Name: " << name
             << ", Roll No: " << roll
             << ", Email: " << email << endl;
    }
    file.close();
}
