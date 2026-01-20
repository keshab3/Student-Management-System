#include<iostream>
#include <fstream>
using namespace std;
void studentDetails();
void studentlogin();
void newStudent();
void studentInfo(string &name, string &username, string &roll, string &email, int &age);

void studentlogin(){
    while (true) {
        cout << "Student Portal" << endl;
        cout << "1. Existing User Account" << endl;
        cout << "2. New Student Registration" << endl;
        cout << "3. Go Back" << endl;
        cout << "Select Option: ";

        int choose;
        cin >> choose;
        cout << "\n";

        // existing user login
        if (choose == 1) {
            bool loginSuccess = false;
            while (!loginSuccess) {
                string username;
                string password;
                string f_name, f_username, f_roll, f_email; // these hold the student info from the file
                int f_age;
                bool found = false;

                cout << "Type Your Student Credentials" << endl;
                cout << "Enter Student Username: ";
                cin >> username;

                if (username == "back") {
                    break; // lets the user go back
                }

                cout << "Enter Student Password: ";
                cin >> password;

                ifstream file("students.txt");
                // read student info from the file
                while (file >> f_name >> f_username >> f_roll >> f_email >> f_age) {
                    if (f_username == username) {
                        found = true;
                        break;
                    }
                }
                file.close();

                if (found && password == "student") { // check if the username is real and password is "student"
                    cout << "Login Successful! Welcome Student." << endl;
                    studentInfo(f_name, f_username, f_roll, f_email, f_age);
                    loginSuccess = true; // this gets us out of the login loop
                } else {
                    cout << "\n" << "Invalid Credentials. Access Denied. " << endl;
                    cout << "Please Try Again." << endl << "\n";
                }
            }
        // for new students
        } else if (choose == 2) {
            cout << "Student registration page" << endl;
            newStudent();
        } else if (choose == 3) {
            return; // go back to the last menu
        } else {
            cout << "Invalid Option. Please try again." << endl;
        }
    }
}
