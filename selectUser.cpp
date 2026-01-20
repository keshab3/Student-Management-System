#include<iostream>
using namespace std;
void adminlogin();
void studentlogin();


void selectUser(){
    cout << "1. Admin" << endl;
    cout << "2. Student User" << endl;
    cout << "Select 1(Admin) or 2(Student): ";
    int choose;
    cin >> choose;
    cout << "\n";



    // Admin Login
    if(choose == 1){
        adminlogin();

    // Student Login
    }else if(choose == 2){
        studentlogin();
    }else{
        cout << "Invalid Option" << endl;
    }
}