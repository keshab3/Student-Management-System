#include<iostream>  //input/output stream
#include<fstream>  // file stream library
#include<string>
using namespace std;

void studentDetails();
void selectUser();

// Helper function to load admin credentials
void loadAdminCredentials(string& username, string& password) {
    ifstream credFile("admin_cred.txt");
    if (credFile) {
        credFile >> username >> password;
        credFile.close();
    } else {
        // If the file doesn't exist, use default credentials
        username = "admin";
        password = "admin";
    }
}

void adminlogin(){
    string username;
    string password;
    string storedUsername;
    string storedPassword;

    cout << "Enter Admin Username: ";
    cin >> username;
    cout << "Enter Admin Password: ";
    cin >> password;

// helped from another source
    ifstream credFile("admin_cred.txt");
    if (credFile) {
        credFile >> storedUsername >> storedPassword;
        credFile.close();   // Closes the file after read.
    } else {
        
        // If details doesn't exist, use default credentials
        storedUsername = "admin";
        storedPassword = "admin";
    }
    // Use the helper function to get the stored credentials
    loadAdminCredentials(storedUsername, storedPassword);



    if(username == storedUsername && password == storedPassword){
        cout << "Login Successful! Welcome Admin." << endl;
           studentDetails();
    }else{
        cout << "\n" << "Invalid Credentials. Access Denied." << endl;
        cout << "Try Again" << endl << "\n"; 
    }
}