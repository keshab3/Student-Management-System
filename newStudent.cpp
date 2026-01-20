#include<iostream>
#include <fstream>
using namespace std;
string name, roll, email , username;
int age;

void newStudent(){
    cout << "New Student Registration Page" << endl;
    cout << "Enter Name: ";
    cin.ignore(); // Consume the newline character left by previous cin
    getline(cin, name);
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Roll No: ";
    cin >> roll;
    cout << "Enter Email: ";
    cin >> email;
    cout << "Enter Age: ";
    cin >> age; 
    ofstream file("students.txt", ios::app);
    file << name << " " << username << " " << roll << " " << email << " " << age << endl;
    file.close();
    cout << "Student Registered Successfully!" << endl;
}