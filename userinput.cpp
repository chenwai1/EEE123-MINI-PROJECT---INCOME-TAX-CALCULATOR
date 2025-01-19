//Programmer: CHEW CHEN WAI
//USM Email: chenwai16@student.usm.my
//GitHub Username: chenwai1
//Matric No.: 23301622

#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>

using namespace std;

struct User {
    string name;
    string ic;
    string phoneNo;
    string email;
    string job;
    string company;
};

// Function declarations
void GettingDetails(User& user);
string capitalize(const string& input);
void saveToFile(const User& user);
bool isReturningUser(const string& email, User& user);
void updateDetails(User& user);
void rewriteFile(const User& updatedUser);

// Function to capitalize a string
string capitalize(const string& input) {
    string result = input;
    for (char& c : result) {
        c = static_cast<char>(toupper(static_cast<unsigned char>(c)));
    }
    return result;
}

// Function to save user details to a file
void saveToFile(const User& user) {
    ofstream outputFile("userDetails.txt", ios::app); // Open in append mode
    if (outputFile.is_open()) {
        outputFile << user.name << "|" << user.ic << "|" << user.phoneNo << "|"
                   << user.email << "|" << user.job << "|" << user.company << endl;
        outputFile.close();
        cout << "\nUser details saved successfully!\n";
    } else {
        cout << "Error: Unable to save user details.\n";
    }
}

// Function to check if a user with the given email exists
bool isReturningUser(const string& email, User& user) {
    ifstream inputFile("userDetails.txt");
    string line;

    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            stringstream ss(line);
            string name, ic, phoneNo, fileEmail, job, company;

            // Parse the line into user details
            getline(ss, name, '|');
            getline(ss, ic, '|');
            getline(ss, phoneNo, '|');
            getline(ss, fileEmail, '|');
            getline(ss, job, '|');
            getline(ss, company, '|');

            if (fileEmail == email) {
                user.name = name;
                user.ic = ic;
                user.phoneNo = phoneNo;
                user.email = fileEmail;
                user.job = job;
                user.company = company;

                inputFile.close();
                return true;
            }
        }
        inputFile.close();
    }
    return false;
}

// Function to get and validate user details
void GettingDetails(User& user) {
    cout << "\n==========================================================\n";
    cout << "              <Part 1. Personal Details>\n";
    cout << "==========================================================\n";
    cout << "Data can be changed after finishing filling the personal details, allowing the user to update their information if necessary.\n";

    // Getting User's Name
    cout << "Name: ";
    getline(cin, user.name);
    user.name = capitalize(user.name);

    // Getting and Validating User IC No.
    regex icPattern("^\\d{6}-\\d{2}-\\d{4}$");
    do {
        cout << "Identity Card (IC) No. (format: XXXXXX-XX-XXXX): ";
        getline(cin, user.ic);
        if (!regex_match(user.ic, icPattern)) {
            cout << "Invalid IC No. Please Try Again.\n";
        }
    } while (!regex_match(user.ic, icPattern));

    // Getting and Validating User Phone No.
    regex phonePattern("^\\+60\\d{7,12}$");
    do {
        cout << "Phone No. (format: +6[Mobile Number without dash (-)]): ";
        getline(cin, user.phoneNo);
        if (!regex_match(user.phoneNo, phonePattern)) {
            cout << "Invalid Phone No. Please Try Again.\n";
        }
    } while (!regex_match(user.phoneNo, phonePattern));

    // Getting and Validating User Email
    regex emailPattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    do {
        cout << "Email: ";
        getline(cin, user.email);
        if (!regex_match(user.email, emailPattern)) {
            cout << "Invalid Email. Please Try Again.\n";
        }
    } while (!regex_match(user.email, emailPattern));

    cout << "Job title: ";
    getline(cin, user.job);
    user.job = capitalize(user.job);

    cout << "Company name: ";
    getline(cin, user.company);
    user.company = capitalize(user.company);

    cout << "\nYour details have been collected successfully!\n";
}

// Function to update user details
void updateDetails(User& user) {
    cout << "\n==========================================================\n";
    cout << "              <Update Your Details>\n";
    cout << "==========================================================\n";
    cout << "Select the field you want to update:\n";
    cout << "1. Name\n";
    cout << "2. Identity Card (IC) No.\n";
    cout << "3. Phone No.\n";
    cout << "4. Email\n";
    cout << "5. Job Title\n";
    cout << "6. Company Name\n";
    cout << "0. Exit Update Menu\n";

    int choice;
    regex emailPattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    regex phonePattern("^\\+60\\d{7,12}$");
    regex icPattern("^\\d{6}-\\d{2}-\\d{4}$");
    string newValue;

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter new name: ";
                getline(cin, newValue);
                user.name = capitalize(newValue);
                break;

            case 2:
                do {
                    cout << "Enter new IC No. (format: XXXXXX-XX-XXXX): ";
                    getline(cin, newValue);
                    if (!regex_match(newValue, icPattern)) {
                        cout << "Invalid IC No. Please Try Again.\n";
                    }
                } while (!regex_match(newValue, icPattern));
                user.ic = newValue;
                break;

            case 3:
                do {
                    cout << "Enter new Phone No. (format: +6[Mobile Number without dash (-)]): ";
                    getline(cin, newValue);
                    if (!regex_match(newValue, phonePattern)) {
                        cout << "Invalid Phone No. Please Try Again.\n";
                    }
                } while (!regex_match(newValue, phonePattern));
                user.phoneNo = newValue;
                break;

            case 4:
                do {
                    cout << "Enter new Email: ";
                    getline(cin, newValue);
                    if (!regex_match(newValue, emailPattern)) {
                        cout << "Invalid Email. Please Try Again.\n";
                    }
                } while (!regex_match(newValue, emailPattern));
                user.email = newValue;
                break;

            case 5:
                cout << "Enter new Job Title: ";
                getline(cin, newValue);
                user.job = capitalize(newValue);
                break;

            case 6:
                cout << "Enter new Company Name: ";
                getline(cin, newValue);
                user.company = capitalize(newValue);
                break;

            case 0:
                cout << "Exiting update menu.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    cout << "\nYour details have been updated successfully!\n";
}

// Function to rewrite the file with updated user details
void rewriteFile(const User& updatedUser) {
    ifstream inputFile("userDetails.txt");
    ofstream tempFile("temp.txt");
    string line;

    if (inputFile.is_open() && tempFile.is_open()) {
        while (getline(inputFile, line)) {
            stringstream ss(line);
            string name, ic, phoneNo, email, job, company;

            getline(ss, name, '|');
            getline(ss, ic, '|');
            getline(ss, phoneNo, '|');
            getline(ss, email, '|');
            getline(ss, job, '|');
            getline(ss, company, '|');

            if (email == updatedUser.email) {
                tempFile << updatedUser.name << "|" << updatedUser.ic << "|" << updatedUser.phoneNo << "|"
                         << updatedUser.email << "|" << updatedUser.job << "|" << updatedUser.company << endl;
            } else {
                tempFile << line << endl;
            }
        }

        inputFile.close();
        tempFile.close();

        remove("userDetails.txt");
        rename("temp.txt", "userDetails.txt");
        cout << "\nUser details updated in the file successfully!\n";
    } else {
        cout << "Error: Unable to update file.\n";
    }
}

// Main function
int main() {
    User user;
    string email;

    cout << "==========================================================\n";
    cout << "              <Welcome to the User System>\n";
    cout << "==========================================================\n";

    cout << "Please enter your email: ";
    getline(cin, email);

    if (isReturningUser(email, user)) {
        cout << "\nWelcome back, " << user.name << "!\n";
        cout << "Here are your details:\n";
        cout << "Name: " << user.name << endl;
        cout << "IC No.: " << user.ic << endl;
        cout << "Phone No.: " << user.phoneNo << endl;
        cout << "Email: " << user.email << endl;
        cout << "Job title: " << user.job << endl;
        cout << "Company name: " << user.company << endl;

        char choice;
        cout << "\nWould you like to update your details? (y/n): ";
        cin >> choice;
        cin.ignore();

        if (tolower(choice) == 'y') {
            updateDetails(user);
            rewriteFile(user);
        }
    } else {
        cout << "\nIt seems you are a new user. Let's register your details.\n";
        GettingDetails(user);
        saveToFile(user);
    }

    cout << "\nThank you for using the system. Goodbye!\n";
    return 0;
}
