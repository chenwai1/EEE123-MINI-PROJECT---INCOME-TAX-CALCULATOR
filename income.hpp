#ifndef INCOME_HPP
#define INCOME_HPP

#include <iostream>
#include <string>
#include <iomanip> // For setw, setfill
using namespace std;

// Define the Income class
class Income {
public:
    // Define the structs inside the class
    struct Salary {
        double amount;
        string description;
    };

    struct Dividend {
        double amount;
        string description;
    };

    struct Business {
        double amount;
        string description;
    };

    // Instances of the structs
    Salary salary;
    Dividend dividend;
    Business business;

    //Function Declaration
    Income();
    size_t getMaxDescriptionWidth() const;
    size_t getMaxAmountWidth() const;
    void display() const;
    double calculateTotal() const;
    double RemainingIncome(double deductions = 0.0) const;
};

#endif