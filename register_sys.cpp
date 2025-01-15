#include "register_sys.hpp"

// Function to check if a string contains spaces
bool hasSpaces(const string& str) {
    return str.find(' ') != string::npos;
}

// Function to trim leading and trailing spaces from a string
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos) return ""; // String is all spaces
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

// Function to handle user registration
void registerUser() {
    string username, password, fileUsername, filePassword;
    ifstream inputfile;
    ofstream outputfile;
    bool registrationSuccessful = false;

    do {
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
        else if (username.empty()) {
            cout << "\nError: Username cannot be empty. Please try again.\n";
            continue; 
        }
        if (hasSpaces(username)) {
            cout << "\nError: Username cannot contain spaces. Please try again.\n";
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
            cout << "\nThe username already exists. Please choose a different username.\n";
            continue; // Skip the rest of the loop and reprompt
        }

        // Prompt for password
        while (true) {
            cout << "Enter a password (no spacing, type 'exit' to go back): ";
            getline(cin, password);

            // Check if the user wants to exit
            if (password == "exit") {
                cout << "Returning to the main menu...\n";
                return;
            }

            // Trim leading and trailing spaces from the password
            password = trim(password);

            // Validate password
            if (password.empty()) {
                cout << "\nError: Password cannot be empty. Please try again.\n";
                continue; // Reprompt for password
            }

            if (hasSpaces(password)) {
                cout << "\nError: Password cannot contain spaces. Please try again.\n";
                continue; // Reprompt for password
            }

            break; // Exit the password input loop if valid
        }

        // Save the credentials to the file
        outputfile.open("credentials.txt", ios::app);
        if (outputfile.is_open()) {
            outputfile << username << " " << password << endl;
            outputfile.close();
            cout << "Registration successful!\n";
            registrationSuccessful = true; // Set flag to true to exit the loop
        } else {
            cout << "Error: Unable to save credentials. Please try again.\n";
        }
    } while (!registrationSuccessful);
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
