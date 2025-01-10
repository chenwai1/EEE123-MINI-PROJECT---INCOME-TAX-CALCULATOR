#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void registerUser();
bool loginUser();
void calculator();
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

        if (choice == 1) {
            registerUser();
        } else if (choice == 2) {
            if (loginUser()) {
                calculator();
                break;
            } else {
                cout << "Login failed. Please try again.\n";
            }
        } else if (choice == 3) {
            cout << "Thanks for using the calculator. Goodbye!\n";
            break;
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
        cin.ignore();
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
        cin.ignore();
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

void calculator() {
    int choice;
    double num1, num2;

    cout << "\nCalculator Menu:\n";
    cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n";
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    switch (choice) {
        case 1:
            cout << "Result: " << num1 + num2 << endl;
            break;
        case 2:
            cout << "Result: " << num1 - num2 << endl;
            break;
        case 3:
            cout << "Result: " << num1 * num2 << endl;
            break;
        case 4:
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Error: Division by zero is not allowed.\n";
            }
            break;
        default:
            cout << "Invalid choice.\n";
    }
}
