#ifndef MAIN_HPP
#define MAIN_HPP

#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include <ctime>
#include <cctype>
#include <limits>
#include <fstream> // For file handling
#include <algorithm> // For std::max
# include <set>



using namespace std;

// Structure to store user details
struct UserDetails {
    string name;
    string ic;
    string phoneNo;
    string email;
    string TIN;
    string HaveDisableChild;
    char religion;
    char spouse;
    char children;
    int NoOfChild;
    int AdultChild;
    int NumberDisableChild;
    int Under18;
    char disability;
};


// Global variables
extern UserDetails user; // User details
extern string religionName; // Religion name
extern string marital_status; // Marital status
extern string DisabilityType; // Disability description

// Function prototypes
bool is_valid_ic(const string& ic);
void income();
void displayMainMenu();
void handleRegistration();
void handleLogin();
void handleTaxCalculator();
void GettingDetails();
void PrintDetails();
string getCurrentDate();
string capitalize(const string& input);
double calculateTotal();




#endif