//Programmer: CHEW CHEN WAI
//USM Email: chenwai16@student.usm.my
//GitHub Username: chenwai1
//Matric No.: 23301622

#include "register_sys.hpp"

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


// Function to check if a string contains spaces
bool hasSpaces(const string& str) {
    return str.find(' ') != string::npos;
}

// Function to handle user registration
void registerUser() {
    string username, password, fileUsername, filePassword;
    ifstream inputfile;
    ofstream outputfile;
    bool registrationSuccessful = false;

    while (true) {
        // Prompt for username
        cout << "\nRegister:\n";
        cout << "Enter a username (no spacing, type 'exit' to go back): ";
        getline(cin, username);

        // Check if the user wants to exit
        if (username == "exit") {
            cout << "Returning to the main menu...\n";
            return;
        }

        // Validate username
        if (hasSpaces(username) || username.empty()) {
            cout << "Error: Username cannot contain spaces or be empty.\n";
            continue;
        }

        // Check if the username already exists
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
            continue;// Skip the rest of the loop and reprompt
        }

        // Prompt for password
        cout << "Enter a password (no spacing, type 'exit' to go back): ";
        getline(cin, password);

        // Check if the user wants to exit
        if (password == "exit") {
            cout << "Returning to the main menu...\n";
            return;
        }

        // Validate password
        if (hasSpaces(password) || password.empty()) {
            cout << "Error: Password cannot contain spaces or be empty.\n";
            continue; // Reprompt for password
        }

        // Save the credentials to the file
        outputfile.open("credentials.txt", ios::app);
        if (outputfile.is_open()) {
            outputfile << username << " " << password << endl;
            outputfile.close();
            cout << "Registration successful!\n"; 
            break; // Set flag to true to exit the loop
        } else {
            cout << "Error: Unable to save credentials. Please try again.\n";
        }
    }
}


// Function to handle user login
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
