//Programmer: CHEW CHEN WAI
//USM Email: chenwai16@student.usm.my
//GitHub Username: chenwai1
//Matric No.: 23301622

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

void registerUser();
bool loginUser();
void mainMenu();
bool hasSpaces(const string& str);

int main() {
    mainMenu();
    return 0;
}

void mainMenu() {
    int choice;

    while (true) {
        cout << "\nWelcome to the INCOME TAX CALCULATOR!\n";
        cout << "__________________________________________________________________________________\n";
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            if (loginUser()) {
                cout << "Login successful. Proceeding to the calculator...\n";
                break;
            } else {
                cout << "Login failed. Please try again.\n";
            }
        } else if (choice == 3) {
            cout << "Thanks for using the calculator. Goodbye!\n";
            break;
        } else if (cin.fail()) {
            cout << "Invalid choice. Please enter 1, 2, or 3.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    }
}

bool hasSpaces(const string& str) {
    return str.find(' ') != string::npos;
}

void registerUser() {
    string username, password, fileUsername, filePassword;
    ifstream inputfile;
    ofstream outputfile;

    while (true) {
        cout << "\nRegister:\n";
        cout << "Enter a username (no spacing, type 'exit' to go back): ";
        getline(cin, username);

        if (username == "exit") {
            cout << "Returning to the main menu...\n";
            return;
        }

        if (hasSpaces(username) || username.empty()) {
            cout << "Error: Username cannot contain spaces or be empty.\n";
            continue;
        }

        inputfile.open("credentials.txt");
        bool userExists = false;

        if (inputfile.is_open()) {
            while (inputfile >> fileUsername >> filePassword) {
                if (fileUsername == username) {
                    userExists = true;
                    break;
                }
            }
            inputfile.close();
        }

        if (userExists) {
            cout << "The username already exists. Please choose a different username.\n";
            continue;
        }

        cout << "Enter a password (no spacing, type 'exit' to go back): ";
        getline(cin, password);

        if (password == "exit") {
            cout << "Returning to the main menu...\n";
            return;
        }

        if (hasSpaces(password) || password.empty()) {
            cout << "Error: Password cannot contain spaces or be empty.\n";
            continue;
        }

        outputfile.open("credentials.txt", ios::app);
        if (outputfile.is_open()) {
            outputfile << username << " " << password << endl;
            outputfile.close();
            cout << "Registration successful!\n";
            break; 
        } else {
            cout << "Error: Unable to save credentials. Please try again.\n";
        }
    }
}

bool loginUser() {
    string username, password, fileUsername, filePassword;
    ifstream inputfile;

    while (true) {
        cout << "\nLogin:\n";
        cout << "Enter your username (type 'exit' to go back): ";
        getline(cin, username);

        if (username == "exit") {
            cout << "Returning to the main menu...\n";
            return false;
        }

        cout << "Enter your password (type 'exit' to go back): ";
        getline(cin, password);

        if (password == "exit") {
            cout << "Returning to the main menu...\n";
            return false;
        }

        inputfile.open("credentials.txt");
        if (inputfile.is_open()) {
            bool loginSuccessful = false;

            while (inputfile >> fileUsername >> filePassword) {
                if (username == fileUsername && password == filePassword) {
                    loginSuccessful = true;
                    break;
                }
            }

            inputfile.close();

            if (loginSuccessful) {
                cout << "Login successful!\n";
                return true;
            } else {
                cout << "Invalid username or password. Please try again.\n";
            }
        } else {
            cout << "Error: Unable to open the credentials file.\n";
            return false;
        }
    }
}