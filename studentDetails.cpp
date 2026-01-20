#include<iostream>
using namespace std;
void student();
void changeAdminPassword();
void viewstudent();

void studentDetails(){
    while (true) {
        cout << "\nAdmin Dashboard \n";
        cout << "1. View Full Student Details" << endl;
        cout << "2. View Student Summary" << endl;
        cout << "3. Change Admin Password" << endl;
        cout << "4. Logout" << endl;  // called 
        cout << "Select an option: ";
        int choice;
        cin >> choice;

        if (choice == 1) { 
            student();
        } else if (choice == 2) { 
            viewstudent();
        } else if (choice == 3) { 
            changeAdminPassword();
        } else if (choice == 4) { // Logout
            cout << "Logging out" << endl;
            return; 
        }
        else {
            cout << "Invalid Option. Please try again." << endl;
        }
    }
}