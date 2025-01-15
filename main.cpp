#include "main.hpp"
#include "getting_details.hpp"
#include "income.hpp"
#include "register_sys.hpp"
#include "Indvidual_Relief.hpp"

// Global variable definitions
UserDetails user;
string religionName;
string marital_status;
string DisabilityType;
int AssesmentType = 0; // 0 = Not chosen, 1 = Individual, 2 = Joint


int main() {
    displayMainMenu(); // Start the program by displaying the main menu
    return 0;
}

// Function to display the main menu
void displayMainMenu() {
    int choice;

    while (true) {
        cout << "==========================================================\n";
        cout << "            Welcome to APEX Tax Calculator\n";
        cout << "==========================================================\n";
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                handleRegistration();
                break;

            case 2:
                handleLogin();
                break;

            case 3:
                cout << "Thanks for using the calculator. Goodbye!\n";
                return;

            default:
                cout << "Invalid choice. Please enter 1, 2, or 3.\n";
        }
    }
}

// Function to handle user registration
void handleRegistration() {
    registerUser();
}

// Function to handle user login
void handleLogin() {
    if (loginUser()) {
        handleTaxCalculator(); // Proceed to tax calculator after successful login
    } else {
        cout << "Login failed. Please try again.\n";
    }
}

// Function to handle the tax calculator
void handleTaxCalculator() {
    GettingDetails(); // Collect user details
    PrintDetails();   // Display user details

    // Ask for Assessment Type
    cout << "==========================================================\n";
    cout << "                <Part 1. Assessment Type>                  \n";
    cout << "==========================================================\n";

    if (marital_status == "Married") {
        cout << "Assessment Types:\n";
        cout << "1. Individual Assessment\n";
        cout << "2. Joint Assessment\n";
        cout << "==========================================================\n";
        cout << "Choose type of Assessment (Type 1 or 2): ";
        cin >> AssesmentType;

        switch (AssesmentType) {
            case 1:
                cout << "You have chosen Individual Assessment" << endl;
                break;

            case 2:
                cout << "You have chosen Joint Assessment" << endl;
                break;

            default:
                cout << "Invalid choice. Defaulting to Individual Assessment." << endl;
                AssesmentType = 1;
                break;
        }
    } else {
        // For single users, skip Joint Assessment and inform the user
        cout << "You are single. Joint Assessment is not applicable.\n";
        cout << "Assessment Types:\n";
        cout << "1. Individual Assessment\n";
        cout << "==========================================================\n";
        cout << "Choose type of Assessment (Type 1): ";
        cin >> AssesmentType;

        if (AssesmentType != 1) {
            cout << "Invalid choice. Defaulting to Individual Assessment." << endl;
            AssesmentType = 1;
        }
        cout << "You have chosen Individual Assessment" << endl;
    }

    // Proceed to income declaration
    income();
    // Relief Declaration
    if (marital_status == "Single") 
    {
    IndividualRelief();
    }
    else if (marital_status == "Married")
    {
        cout << "JointRelief(); coming soon";
    }

}