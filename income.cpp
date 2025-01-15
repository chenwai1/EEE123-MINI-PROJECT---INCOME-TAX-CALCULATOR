#include "main.hpp"
#include "income.hpp"

void income() {
    Income income; // Create an object of the Income class
    int choice;

    cout << setw(40) << "<Part 2. Income Declaration>" << endl;
    cout << "==========================================================" << endl;

    do {
        // Display menu
        cout << "\nChoose your Income:\n";
        cout << "1. Salary\n";
        cout << "2. Business\n";
        cout << "3. Dividend\n";
        cout << "4. Edit Previous Entries\n";
        cout << "5. Finish and calculate total\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the input buffer

        switch (choice) {
            case 1: // Salary
                cout << "Enter the new description for Salary: ";
                getline(cin, income.salary.description);

                // Input validation for salary amount
                do {
                    cout << "Enter your new Yearly Salary in RM: ";
                    if (!(cin >> income.salary.amount) || income.salary.amount < 0) {
                        cout << "Invalid input. Please enter a non-negative number.\n";
                        cin.clear(); // Clear the error state
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    } else {
                        break; // Exit the loop if input is valid
                    }
                } while (true);
                break;

            case 2: // Business
                cout << "Enter the new description for Business: ";
                getline(cin, income.business.description);

                // Input validation for business amount
                do {
                    cout << "Enter your new Yearly Business in RM: ";
                    if (!(cin >> income.business.amount) || income.business.amount < 0) {
                        cout << "Invalid input. Please enter a non-negative number.\n";
                        cin.clear(); // Clear the error state
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    } else {
                        break; // Exit the loop if input is valid
                    }
                } while (true);
                break;

            case 3: // Dividend
                cout << "Enter the new description for Dividend Income: ";
                getline(cin, income.dividend.description);

                // Input validation for dividend amount
                do {
                    cout << "Enter your new Yearly Dividend Income in RM: ";
                    if (!(cin >> income.dividend.amount) || income.dividend.amount < 0) {
                        cout << "Invalid input. Please enter a non-negative number.\n";
                        cin.clear(); // Clear the error state
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    } else {
                        break; // Exit the loop if input is valid
                    }
                } while (true);
                break;

            case 4: // Edit previous entries
                int editChoice;
                cout << "\nWhat would you like to edit?\n";
                cout << "1. Salary\n";
                cout << "2. Business Income\n";
                cout << "3. Dividend Income\n";
                cout << "Enter your choice: ";
                cin >> editChoice;
                cin.ignore(); // Clear the input buffer

                switch (editChoice) {
                    case 1: // Edit Salary
                        cout << "Enter the new description for Salary: ";
                        getline(cin, income.salary.description);

                        // Input validation for salary amount
                        do {
                            cout << "Enter your new Yearly Salary in RM: ";
                            if (!(cin >> income.salary.amount) || income.salary.amount < 0) {
                                cout << "Invalid input. Please enter a non-negative number.\n";
                                cin.clear(); // Clear the error state
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                            } else {
                                break; // Exit the loop if input is valid
                            }
                        } while (true);
                        break;

                    case 2: // Edit Business
                        cout << "Enter the new description for Business: ";
                        getline(cin, income.business.description);

                        // Input validation for business amount
                        do {
                            cout << "Enter your new Yearly Business in RM: ";
                            if (!(cin >> income.business.amount) || income.business.amount < 0) {
                                cout << "Invalid input. Please enter a non-negative number.\n";
                                cin.clear(); // Clear the error state
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                            } else {
                                break; // Exit the loop if input is valid
                            }
                        } while (true);
                        break;

                    case 3: // Edit Dividend
                        cout << "Enter the new description for Dividend Income: ";
                        getline(cin, income.dividend.description);

                        // Input validation for dividend amount
                        do {
                            cout << "Enter your new Yearly Dividend Income in RM: ";
                            if (!(cin >> income.dividend.amount) || income.dividend.amount < 0) {
                                cout << "Invalid input. Please enter a non-negative number.\n";
                                cin.clear(); // Clear the error state
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                            } else {
                                break; // Exit the loop if input is valid
                            }
                        } while (true);
                        break;

                    default:
                        cout << "Invalid choice. No changes made.\n";
                }
                break;

            case 5: // Finish and calculate total
                income.display();
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
}

// Constructor to initialize income values
Income::Income() {
    salary.amount = 0;
    salary.description = "";
    business.amount = 0;
    business.description = "";
    dividend.amount = 0;
    dividend.description = "";
}

// Function to calculate the maximum width of the description column
size_t Income::getMaxDescriptionWidth() const {
    size_t maxWidth = 0;
    maxWidth = max(maxWidth, salary.description.length());
    maxWidth = max(maxWidth, business.description.length());
    maxWidth = max(maxWidth, dividend.description.length());
    maxWidth = max(maxWidth, string("Total Income").length());
    return maxWidth;
}

// Function to calculate the maximum width of the amount column
size_t Income::getMaxAmountWidth() const {
    size_t maxWidth = 0;
    maxWidth = max(maxWidth, to_string(salary.amount).length());
    maxWidth = max(maxWidth, to_string(business.amount).length());
    maxWidth = max(maxWidth, to_string(dividend.amount).length());
    maxWidth = max(maxWidth, to_string(calculateTotal()).length());
    return maxWidth;
}

// Function to display income details
void Income::display() const {
    // Calculate dynamic widths
    size_t descWidth = getMaxDescriptionWidth() + 2; // Add padding
    size_t amountWidth = getMaxAmountWidth() + 2;    // Add padding

    // Ensure minimum column widths
    descWidth = max(descWidth, string("Description").length() + 2);
    amountWidth = max(amountWidth, string("Amount (RM)").length() + 2);

    // Table header
    cout << "+" << setfill('-') << setw(static_cast<int>(descWidth + amountWidth + 5)) << "+" << setfill(' ') << "\n";
    cout << "| " << setw(static_cast<int>(descWidth)) << left << "Description" << " | " << setw(static_cast<int>(amountWidth)) << right << "Amount (RM)" << " |\n";
    cout << "+" << setfill('-') << setw(static_cast<int>(descWidth + amountWidth + 5)) << "+" << setfill(' ') << "\n";

    // Display salary
    cout << "| " << setw(static_cast<int>(descWidth)) << left << salary.description << " | " << setw(static_cast<int>(amountWidth)) << right << fixed <<setprecision(2) << salary.amount << " |\n";

    // Display business income
    cout << "| " << setw(static_cast<int>(descWidth)) << left << business.description << " | " << setw(static_cast<int>(amountWidth)) << right << fixed << setprecision(2) << business.amount << " |\n";

    // Display dividend income
    cout << "| " << setw(static_cast<int>(descWidth)) << left << dividend.description << " | " << setw(static_cast<int>(amountWidth)) << right << fixed << setprecision(2) << dividend.amount << " |\n";

    // Separator before total income
    cout << "+" << setfill('-') << setw(static_cast<int>(descWidth + amountWidth + 5)) << "+" << setfill(' ') << "\n";

    // Calculate and display total income
    double totalIncome = calculateTotal();
    cout << "| " << setw(static_cast<int>(descWidth)) << left << "Total Income" << " | " << setw(static_cast<int>(amountWidth)) << right << setprecision(2) <<totalIncome << " |\n";

    // Table footer
    cout << "+" << setfill('-') << setw(static_cast<int>(descWidth + amountWidth + 5)) << "+" << setfill(' ') << "\n";
}

// Function to calculate total income
double Income::calculateTotal() const {
    return salary.amount + business.amount + dividend.amount;
}

// Function to calculate remaining income after deductions
double Income::RemainingIncome(double deductions) const {
    double totalIncome = calculateTotal();
    return totalIncome - deductions;
}

