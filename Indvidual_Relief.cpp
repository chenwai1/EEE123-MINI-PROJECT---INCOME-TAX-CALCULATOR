//Programmer: OOI YEEZON
//USM Email: Yeezon@student.usm.my
//GitHub Username: yeezon1
//Matric No.: 23301291
//Selection expenses for individual

//Function Prototype
double calculateTotal();

#include "Indvidual_Relief.hpp"

/*
MAXIMUM DEDUCTIONS FOR EACH EXPENSES CATEGORY
1. Personal Relief: 9000
2. Disability Relief: 6000
3. Lifestyle Relief: 2500
4. Medical Expenses Relief: 8000
5. Education Fees Relief: 7000
6. Child Relief: 2000 per child
7. Parent Relief: 1500 per parent
*/

// Constant for the maximum deductions for each expenses category
const int MaxDeductions[23] = {
    9000,  // 1. Individual and dependent relatives
    8000,  // 2. Expenses for parents (medical, dental, etc.)
    6000,  // 3. Purchase of basic supporting equipment for disabled
    6000,  // 4. Disabled individual
    7000,  // 5. Education fees (self)
    10000, // 6. Medical expenses (serious diseases, fertility, etc.)
    1000,  // 7. Expenses (medical examination, COVID-19, mental health)
    4000,  // 8. Expenses for child (intellectual disability, early intervention)
    2500,  // 9. Lifestyle (books, computers, internet, courses)
    1000,  // 10. Lifestyle (sports equipment, gym membership)
    1000,  // 11. Breastfeeding equipment
    3000,  // 12. Child care fees
    8000,  // 13. Skim Simpanan Pendidikan Nasional
    4000,  // 14. Husband/wife/alimony
    5000,  // 15. Disabled husband/wife
    2000,  // 16. Unmarried child under 18
    2000,  // 17. Unmarried child 18+ (A-Level, diploma, etc.)
    6000,  // 18. Disabled child
    7000,  // 19. Life insurance and EPF
    3000,  // 20. Deferred Annuity and PRS
    3000,  // 21. Education and medical insurance
    350,   // 22. SOCSO contribution
    2500   // 23. Electric vehicle charging facilities
};
void IndividualRelief() {
    // Map to track selected categories, their deductible amounts, and descriptions
    map<int, pair<int, string>> selectedCategories;

    // Total Expenses
    int TotalExpenses = 0;

    // Code of choice of expenses (User can only input 0-23)
    int CodeOfChoice;

    // DISPLAY the allowed categories for EXPENSES
    cout << "\n=============================================================================================\n";
    cout << "                               <Part 3. Relief Selection>\n";
    cout << "==============================================================================================\n";
    cout << "The following list is the allowed categories for expenses:\n";
    cout << "+----+-----------------------------------------------------------------+---------------------+\n";
    cout << "| No | Category                                                        | Maximum Deduction   |\n";
    cout << "+----+-----------------------------------------------------------------+---------------------+\n";
    cout << "|  1 | Individual and dependent relatives                              | RM 9000             |\n";
    cout << "|  2 | Expenses for parents (medical, dental, etc.)                    | RM 8000             |\n";
    cout << "|  3 | Purchase of basic supporting equipment for disabled             | RM 6000             |\n";
    cout << "|  4 | Disabled individual                                             | RM 6000             |\n";
    cout << "|  5 | Education fees (self)                                           | RM 7000             |\n";
    cout << "|  6 | Medical expenses (serious diseases, fertility, etc.)            | RM 10000            |\n";
    cout << "|  7 | Expenses (medical examination, COVID-19, mental health)         | RM 1000             |\n";
    cout << "|  8 | Expenses for child (intellectual disability, early intervention)| RM 4000             |\n";
    cout << "|  9 | Lifestyle (books, computers, internet, courses)                 | RM 2500             |\n";
    cout << "| 10 | Lifestyle (sports equipment, gym membership)                    | RM 1000             |\n";
    cout << "| 11 | Breastfeeding equipment                                         | RM 1000             |\n";
    cout << "| 12 | Child care fees                                                 | RM 3000             |\n";
    cout << "| 13 | Skim Simpanan Pendidikan Nasional                               | RM 8000             |\n";
    cout << "| 14 | Husband/wife/alimony                                            | RM 4000             |\n";
    cout << "| 15 | Disabled husband/wife                                           | RM 5000             |\n";
    cout << "| 16 | Unmarried child under 18                                        | RM 2000 per child   |\n";
    cout << "| 17 | Unmarried child 18+ (A-Level, diploma, etc.)                    | RM 2000 per child   |\n";
    cout << "| 18 | Disabled child                                                  | RM 6000 per child   |\n";
    cout << "| 19 | Life insurance and EPF                                          | RM 7000             |\n";
    cout << "| 20 | Deferred Annuity and PRS                                        | RM 3000             |\n";
    cout << "| 21 | Education and medical insurance                                 | RM 3000             |\n";
    cout << "| 22 | SOCSO contribution                                              | RM 350              |\n";
    cout << "| 23 | Electric vehicle charging facilities                            | RM 2500             |\n";
    cout << "+----+-----------------------------------------------------------------+---------------------+\n";
    cout << "|  0 | Finish and Exit                                                 |                     |\n";
    cout << "+----+-----------------------------------------------------------------+---------------------+\n";

    // Guide for User to input
    cout << "\n=== Step 1: Select a Category ===\n";
    cout << "Enter your expenses category (1-23) or '0' to finish.\n";

    // User input Choice
    while (true) {
        // User input their choice here (0-23)
        cout << "\nCategory: ";
        cin >> CodeOfChoice;

        // Validate input
        if (cin.fail() || CodeOfChoice < 0 || CodeOfChoice > 23) {
            cout << "Invalid input. Please enter a number between 0 and 23.\n";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            continue;
        }

        // Condition to exit the loop
        if (CodeOfChoice == 0) {
            cout << "Finished selection.\n";
            break;
        }

        // Avoid user repeated input same category
        if (selectedCategories.find(CodeOfChoice) != selectedCategories.end()) {
            cout << "You have already selected this category. Please choose a different category.\n";
            continue;
        }

        // Check if the category is applicable
        bool isApplicable = true;
        switch (CodeOfChoice) {
            case 3: // Purchase of basic supporting equipment for disabled
            case 4: // Disabled individual
                if (user.disability != 'N') {
                    cout << "You do not have a disability. Skipping this relief.\n";
                    isApplicable = false;
                }
                break;
            case 8: // Expenses for child (intellectual disability, early intervention)
            case 12: // Child care fees
            case 16: // Unmarried child under 18
            case 17: // Unmarried child 18+
            case 18: // Disabled child
                if (user.children != 'N' || user.NoOfChild <= 0) {
                    cout << "You do not have any children. Skipping this relief.\n";
                    isApplicable = false;
                }
                break;
            case 14: // Husband/wife/alimony
            case 15: // Disabled husband/wife
                if (marital_status != "Married") {
                    cout << "You are not married. Skipping this relief.\n";
                    isApplicable = false;
                }
                break;
            default:
                break;
        }

        if (!isApplicable) {
            continue; // Skip this category
        }

        // === Step 2: Enter Expense Amount ===
        cout << "\n=== Step 2: Enter Expense Amount ===\n";
        cout << "Enter the amount you spent for this category: RM ";
        int expense;
        cin >> expense;

        // === Step 3: Provide a Description ===
        cout << "\n=== Step 3: Provide a Description ===\n";
        cout << "Enter a brief description for this expense: ";
        string description;
        cin.ignore(); // Clear the input buffer
        getline(cin, description);

        // Calculate amount deductible
        int deductible = 0;
        if (CodeOfChoice == 12 || CodeOfChoice == 16 || CodeOfChoice == 17 || CodeOfChoice == 18) {
            // Handle child-related deductions
            switch (CodeOfChoice) {
                case 12:
                    
                case 16: // Unmarried child under 18
                    deductible = 2000 * user.NoOfChild;
                    break;
                case 17: // Unmarried child 18+ (A-Level, diploma, etc.)
                    deductible = 2000 * user.NoOfChild;
                    break;
                case 18: // Disabled child
                    deductible = 6000 * user.NoOfChild;
                    break;
            }
        } else {
            // Cap the deductible amount at the maximum allowed
            deductible = min(expense, MaxDeductions[CodeOfChoice - 1]);
        }

        // Add to total expenses
        TotalExpenses += deductible;

        // Add the category, deductible amount, and description to the map
        selectedCategories[CodeOfChoice] = make_pair(deductible, description);

        // === Deductible Amount ===
        cout << "\n=== Deductible Amount ===\n";
        cout << "Deductible amount for this category: RM " << deductible << "\n";
    }

    // Display total deductible expenses in the new table style
    cout << "\n========================================================\n";
    cout << "                      TAX DEDUCTIONS                     \n";
    cout << "========================================================\n";
    cout << std::setw(30) << std::left << "Expense Category" 
         << std::setw(20) << "Description" 
         << std::setw(15) << "Amount (RM)" << "\n";
    cout << "--------------------------------------------------------\n";

    for (const auto& entry : selectedCategories) {
        int code = entry.first;
        int deductible = entry.second.first;
        string description = entry.second.second;

        string categoryName;
        switch (code) {
            case 1: categoryName = "Individual and dependent relatives"; break;
            case 2: categoryName = "Expenses for parents"; break;
            case 3: categoryName = "Support equipment for disabled"; break;
            case 4: categoryName = "Disabled individual"; break;
            case 5: categoryName = "Education fees (self)"; break;
            case 6: categoryName = "Medical expenses"; break;
            case 7: categoryName = "Medical examination"; break;
            case 8: categoryName = "Child intervention"; break;
            case 9: categoryName = "Lifestyle (books, computers)"; break;
            case 10: categoryName = "Lifestyle (sports)"; break;
            case 11: categoryName = "Breastfeeding equipment"; break;
            case 12: categoryName = "Child care fees"; break;
            case 13: categoryName = "Skim Simpanan Pendidikan"; break;
            case 14: categoryName = "Husband/wife/alimony"; break;
            case 15: categoryName = "Disabled husband/wife"; break;
            case 16: categoryName = "Unmarried child under 18"; break;
            case 17: categoryName = "Unmarried child 18+"; break;
            case 18: categoryName = "Disabled child"; break;
            case 19: categoryName = "Life insurance and EPF"; break;
            case 20: categoryName = "Deferred Annuity and PRS"; break;
            case 21: categoryName = "Education/medical insurance"; break;
            case 22: categoryName = "SOCSO contribution"; break;
            case 23: categoryName = "EV charging facilities"; break;
            default: categoryName = "Unknown"; break;
        }

        // Display the category, deductible amount, and description
        cout << std::setw(30) << categoryName 
             << std::setw(20) << description 
             << std::setw(15) << deductible << "\n";
    }

    cout << "--------------------------------------------------------\n";
    cout << std::setw(30) << "Total Deductible Expenses" 
         << std::setw(35) << TotalExpenses << "\n";
    cout << "========================================================\n";
}
