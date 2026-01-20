#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

void updateFile(string oldUser, string name, string username, string roll, string email, int age) {
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    
    string f_name, f_username, f_roll, f_email;
    int f_age;
    
    while(file >> f_name >> f_username >> f_roll >> f_email >> f_age) {
        if(f_username == oldUser) {
            temp << name << " " << username << " " << roll << " " << email << " " << age << endl;
        } else {
            temp << f_name << " " << f_username << " " << f_roll << " " << f_email << " " << f_age << endl;
        }
    }
    file.close();
    temp.close();
    
    remove("students.txt");
    rename("temp.txt", "students.txt");
}

void studentInfo(string &name, string &username, string &roll, string &email, int &age) {
    int option;
    do {
        cout << "\n Student Information \n";
        cout << "Name: " << name 
             << " | Username: " << username 
             << " | Roll: " << roll 
             << " | Email: " << email 
             << " | Age: " << age << endl;
             
        cout << "\n 1. Edit Name" << endl;
        cout << "2. Edit Username" << endl;
        cout << "3. Edit Roll" << endl;
        cout << "4. Edit Email" << endl;
        cout << "5. Edit Age" << endl;
        cout << "6. Logout" << endl;
        cout << "Select Option: ";
        cin >> option;
        
        if(option == 6) break;
        
        string oldUsername = username;
        
        if(option == 1) { cout << "Enter New Name: "; cin >> name; }
        else if(option == 2) { cout << "Enter New Username: "; cin >> username; }
        else if(option == 3) { cout << "Enter New Roll: "; cin >> roll; }
        else if(option == 4) { cout << "Enter New Email: "; cin >> email; }
        else if(option == 5) { cout << "Enter New Age: "; cin >> age; }
        
        if(option >= 1 && option <= 5) {
            updateFile(oldUsername, name, username, roll, email, age);
            cout << "Details Updated Successfully" << endl;
        }
        
    } while(option != 6);
}