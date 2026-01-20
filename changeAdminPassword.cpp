#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // for isupper, isdigit, ispunct


// I used this code from the activity to check a strong password; it is referenced in the submitted assignment file.

using namespace std;

void changeAdminPassword() {
    string currentPassword, storedPassword, storedUsername;

    cout << "To change your password, please enter your current password: ";
    cin >> currentPassword;

    ifstream credFile("admin_cred.txt");
    if (credFile) {
        credFile >> storedUsername >> storedPassword;
        credFile.close();
    } else {
        // If file doesn't exist, use default
        storedUsername = "admin";
        storedPassword = "admin";
    }

    if (currentPassword != storedPassword) {
        cout << "Incorrect password. Returning to dashboard." << endl;
        return;
    }

    string newPassword;
    bool isUpper = false, isSpecialChar = false, isNumber = false;

    cout << "Enter new password: ";
    cin >> newPassword;

    for (char data : newPassword) {
        if (isupper(data)) isUpper = true;
        if (isdigit(data)) isNumber = true;
        if (ispunct(data)) isSpecialChar = true;
    }

    if (isUpper && isSpecialChar && isNumber && newPassword.size() > 8) {
        cout << "Strong password" << endl;
        ofstream outFile("admin_cred.txt");
        outFile << storedUsername << " " << newPassword;
        outFile.close();
        cout << "Password updated successfully!" << endl;
    } else {
        cout << "Weak password" << endl;
        char choice;
        cout << "Do you want to use this weak password anyway? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            ofstream outFile("admin_cred.txt");
            outFile << storedUsername << " " << newPassword;
            outFile.close();
            cout << "Password updated successfully!" << endl;
        } else {
            cout << "Password not changed. Returning to dashboard." << endl;
        }
    }
}