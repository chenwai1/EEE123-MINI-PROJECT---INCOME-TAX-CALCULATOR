
// Function header files
#include <iostream> 
#include <limits>
#include <iomanip>
#include "TaxRelief.hpp"

using namespace std;

string getDisabilityInput(const string& prompt)
{
    string response;
    do {
        cout << prompt;
        cin >> response;
        if (response != "Y" && response != "N") {
            cerr << "Invalid input. Please enter 'Y' for Yes or 'N' for No." << endl;
        }
    } while (response != "Y" && response != "N");
    return response;
}
	
//Function purpose: Ask about the marital status to get the Tax Relief of the customer
void Marital_Status(double& TotalTaxRelief1)
{
    string marital_status;
    string disability_status;
    double alimony;

    do {
        cout << "Please enter your marital status. (Enter 'S' for Single/ 'M' for Married/ 'D' for Divorced): ";
        cin >> marital_status;
        if (marital_status != "S" && marital_status != "M" && marital_status != "D") { 
            cerr << "Invalid input for marital status. " << endl;
        } 
    } while (marital_status != "S" && marital_status != "M" && marital_status != "D");
    cout << endl;

    if (marital_status == "S") {
        marital_status = "Single";
        disability_status = getDisabilityInput("Do you have any disabilities? (Enter 'Y' for Yes/ 'N' for No): ");
        if (disability_status == "Y") {
            TotalTaxRelief1 = 9000 + 6000;
        } else {
            TotalTaxRelief1 = 9000;
        }
    } else if (marital_status == "M") {
        marital_status = "Married";
        disability_status = getDisabilityInput("Do you and your partner have any disabilities? (Please enter 'N' for No/ 'M' for Me/ 'P' for Partner/ 'B' for Both): ");
        if (disability_status == "N") {
            TotalTaxRelief1 = 9000;
        } else if (disability_status == "M") {
            TotalTaxRelief1 = 9000 + 6000;
        } else if (disability_status == "P") {
            TotalTaxRelief1 = 9000 + 5000;
        } else if (disability_status == "B") {
            TotalTaxRelief1 = 9000 + 6000 + 5000;
        }
    } else if (marital_status == "D") {
        marital_status = "Divorced";
        disability_status = getDisabilityInput("Do you have any disabilities? (Please enter 'Y' for Yes/ 'N' for No): ");
        if (disability_status == "Y") {
            do {
                if (cin.fail() || alimony < 0) {
                    cout << "Invalid input. Please enter a valid number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "How much did you pay in alimony to your ex-wife? (limited to RM4000): RM";
                cin >> alimony;
                TotalTaxRelief1 = 9000 + 6000 + min(4000.0, alimony);
            } while (cin.fail() || alimony < 0);
            cin.clear();
            cin.ignore();
        } else {
            do {
                if (cin.fail() || alimony < 0) {
                    cout << "Invalid input. Please enter a valid number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "How much did you pay in alimony to your ex-wife? (limited to RM4000): RM";
                cin >> alimony;
                TotalTaxRelief1 = 9000 + min(4000.0, alimony);
            } while (cin.fail() || alimony < 0);
            cin.clear();
            cin.ignore();
        }
    }
}


//Function purpose: Ask about the children status to get the Tax Relief of the customer
void Children(double& TotalTaxRelief2) {
    // Declare variables
    string children, oku4, oku5, oku6, oku7, eduLvl;
    int numOfChild, age;
    double breastfeedingequipment, childcarefee = 0.0, TaxRelief2;

    // Ask the user if they have any children
    do {
        cout << "Did you have any children? (Enter 'Y' for Yes/ 'N' for No): ";
        cin >> children;

        // Validate input 
        if (children != "Y" && children != "N") { 
            cerr << "Invalid input for children status. " << endl;
        } 
    } while (children != "Y" && children != "N");

    // If the user has children
    if (children == "Y") {
        // Ask for the number of unmarried children
        do {
            cout << "Enter the number of unmarried children: ";
            cin >> numOfChild;

            // Validate input 
            if (cin.fail() || numOfChild <= 0) { 
                cerr << "Invalid input for the number of unmarried children. Please enter a non-negative value." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
            } 
        } while (cin.fail() || numOfChild <= 0);

        // Loop through each child
        for (int i = 0; i < numOfChild; i++) {
            // Ask for the child's age
            do {
                cout << "Enter the " << i + 1 << "-child's age: ";
                cin >> age;

                // Validate input
                if (cin.fail() || age <= 0) { 
                    cerr << "Invalid input for the child's age. Please enter a non-negative value." << endl; 
                } 
            } while (cin.fail() || age <= 0);

            // Ask for the child's disabilities and the amount spent on breastfeeding equipment to calculate tax relief
            if (age <= 2) {
                do {
                    cout << "Do your child have any disabilities? (Enter 'Y' for Yes/ 'N' for No): ";
                    cin >> oku4;

                    // Validate input 
                    if (oku4 != "Y" && oku4 != "N") { 
                        cerr << "Invalid input for disable status. " << endl;
                    } 
                } while (oku4 != "Y" && oku4 != "N");

                if (oku4 == "Y") {
                    do {
                        if (cin.fail() || breastfeedingequipment < 0) {
                            cout << "Invalid input. Please enter a valid number." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        cout << "How much did you spend on breastfeeding equipment for your child aged 2 years and below? (Limited to RM1000): RM";
                        cin >> breastfeedingequipment;
                        TaxRelief2 = 2000 + 6000 + min(1000.0, breastfeedingequipment);
                    } while (cin.fail() || breastfeedingequipment < 0);
                    cin.clear(); 
                    cin.ignore();     
                } else {
                    do {
                        if (cin.fail() || breastfeedingequipment < 0) {
                            cout << "Invalid input. Please enter a valid number." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        cout << "How much did you spend on breastfeeding equipment for your child aged 2 years and below? (Limited to RM1000): RM";
                        cin >> breastfeedingequipment;
                        TaxRelief2 = 2000 + min(1000.0, breastfeedingequipment);
                    } while (cin.fail() || breastfeedingequipment < 0);
                    cin.clear(); 
                    cin.ignore();     
                }

            // Ask for the child's disabilities and the amount spent on child care fees to calculate tax relief
            } else if (age <= 6) {
                do {
                    cout << "Do your child have any disabilities? (Enter 'Y' for Yes/ 'N' for No): ";
                    cin >> oku5;

                    // Validate input 
                    if (oku5 != "Y" && oku5 != "N") { 
                        cerr << "Invalid input for disable status. " << endl;
                    } 
                } while (oku5 != "Y" && oku5 != "N");

                if (oku5 == "Y") {
                    do {
                        if (cin.fail() || childcarefee < 0) {
                            cout << "Invalid input. Please enter a valid number." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            childcarefee = 0.0; // Reset to default value
                        }
                        cout << "How much did you pay for child care fees? (Limited to RM3000): RM";
                        cin >> childcarefee;
                        TaxRelief2 = 6000 + 2000 + min(3000.0, childcarefee);
                    } while (cin.fail() || childcarefee < 0);
                    cin.clear(); 
                    cin.ignore();     
                } else {
                    do {
                        if (cin.fail() || childcarefee < 0) {
                            cout << "Invalid input. Please enter a valid number." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            childcarefee = 0.0; // Reset to default value
                        }
                        cout << "How much did you pay for child care fees? (Limited to RM3000): RM";
                        cin >> childcarefee;
                        TaxRelief2 = 2000 + min(3000.0, childcarefee);
                    } while (cin.fail() || childcarefee < 0);
                    cin.clear(); 
                    cin.ignore();     
                }

            // Ask for the child's disabilities to calculate tax relief
            } else if (age < 18) {
                do {
                    cout << "Do your child have any disabilities? (Enter 'Y' for Yes/ 'N' for No): ";
                    cin >> oku6;

                    // Validate input 
                    if (oku6 != "Y" && oku6 != "N") { 
                        cerr << "Invalid input for disable status. " << endl;
                    } 
                } while (oku6 != "Y" && oku6 != "N");

                if (oku6 == "Y") {
                    TaxRelief2 = 2000 + 6000;            
                } else {
                    TaxRelief2 = 2000;
                }

            // Ask for the child's disabilities and the education level to calculate tax relief
            } else if (age >= 18) {
                do {
                    cout << "Do your child have any disabilities? (Enter 'Y' for Yes/ 'N' for No): ";
                    cin >> oku7;

                    // Validate input 
                    if (oku7 != "Y" && oku7 != "N") { 
                        cerr << "Invalid input for disable status. " << endl;
                    } 
                } while (oku7 != "Y" && oku7 != "N");

                if (oku7 == "Y") {
                    do {
                        cout << "Is your child's education level above or equivalent to a diploma? (Enter 'Y' for Yes/ 'N' for No): ";
                        cin >> eduLvl;

                        // Validate input 
                        if (eduLvl != "Y" && eduLvl != "N") { 
                            cerr << "Invalid input for education level. " << endl;
                        } 
                    } while (eduLvl != "Y" && eduLvl != "N");

                    if (eduLvl == "Y") {
                        TaxRelief2 = 8000 + 6000;
                    } else {
                        TaxRelief2 = 6000;
                    }
                } else {
                    do {
                        cout << "Is your child's education level above or equivalent to a diploma? (Enter 'Y' for Yes/ 'N' for No): ";
                        cin >> eduLvl;

                        // Validate input 
                        if (eduLvl != "Y" && eduLvl != "N") { 
                            cerr << "Invalid input for education level. " << endl;
                        } 
                    } while (eduLvl != "Y" && eduLvl != "N");

                    if (eduLvl == "Y") {
                        TaxRelief2 = 8000;
                    } else {
                        TaxRelief2 = 2000;
                    }
                }
            }
            // Add the calculated tax relief to the total
            TotalTaxRelief2 += TaxRelief2;
        }
    } else {
        // If the user does not have children, set tax relief to 0
        TaxRelief2 = 0;
        childcarefee = 0;
    }
}


//Function purpose: Ask about the contribution to get the Tax Relief of the customer
void Contribution(double& TotalTaxRelief3)
{
    // Declare variables
    double EPF1, EPF2, ins, SOCSO, PRS, SSPN;

    // Loop to ensure valid input for EPF1
    do{
        if(cin.fail() || EPF1 < 0)
        {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout << "a. How much did you contribute to approved schemes or voluntarily to the EPF? (Limited to RM4000): RM";
        cin >> EPF1;
        EPF1 = min(4000.0, EPF1);
    }
    while(cin.fail() || EPF1 < 0);
        cin.clear(); 
        cin.ignore();

    // Loop to ensure valid input for EPF2
    do{
        if(cin.fail() || EPF2 < 0)
        {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout << "b. How much did you pay for life insurance, family takaful, or extra EPF contributions? (Limited to RM3000): RM";
        cin >> EPF2;
        EPF2 = min(3000.0, EPF2);
    }
    while(cin.fail() || EPF2 < 0);
        cin.clear(); 
        cin.ignore();

    // Loop to ensure valid input for ins
    do{
        if(cin.fail() || ins < 0)
        {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout << "c. How much did you pay for education and medical insurance? (Limited to RM3000): RM";
        cin >> ins;
        ins = min(3000.0, ins);
    }
    while(cin.fail() || ins < 0);
        cin.clear(); 
        cin.ignore();
    
    // Loop to ensure valid input for SOCSO
    do{
        if(cin.fail() || SOCSO < 0)
        {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout << "d. How much did you contribute to the Social Security Organization (SOCSO) (Limited to RM350): RM";
        cin >> SOCSO;
        SOCSO = min(350.0, SOCSO);
    }
    while(cin.fail() || SOCSO < 0);
        cin.clear(); 
        cin.ignore();
    
    // Loop to ensure valid input for PRS
    do{
        if(cin.fail() || PRS < 0)
        {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout << "e. How much did you pay into the Deferred Annuity and Private Retirement Scheme (PRS) (Limited to RM3000): RM";
        cin >> PRS;
        PRS = min(3000.0, PRS);
    }
    while(cin.fail() || PRS < 0);
        cin.clear(); 
        cin.ignore();
    
    // Loop to ensure valid input for SSPN
    do{
        if(cin.fail() || SSPN < 0)
        {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout << "f. What is your net saving in the Skim Simpanan Pendidikan Nasional (SSPN) scheme? (Limited to RM8000): RM";
        cin >> SSPN;
        SSPN = min(8000.0, SSPN);
    }
    while(cin.fail() || SSPN < 0);
        cin.clear(); 
        cin.ignore();
    
    // Calculate total tax relief
    TotalTaxRelief3 = EPF1 + EPF2 + ins + SOCSO + PRS + SSPN;
}

 	
//Function purpose: Ask about the lifestyle to get the Tax Relief of the customer
void Lifestyle(double& TotalTaxRelief4)
{
    // Declare variables
    double MTParents, equipment, lifestyleexpenses, electricvehicles, medicalexpenses, educationfee;

    // Loop to ensure valid input for MTParents
    do{
        if(cin.fail() || MTParents < 0)
        {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout << "a. How much did you spend for medical treatment, special needs, and caregiver expenses for your parents? (Limited to RM8000): RM";
        cin >> MTParents;
        MTParents = min(8000.0, MTParents);
    }
    while(cin.fail() || MTParents < 0);
        cin.clear(); 
        cin.ignore();
    
    // Loop to ensure valid input for equipment
    do{
        if(cin.fail() || equipment < 0)
        {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout << "b. How much did you spend on basic supporting equipment for a disabled family member? (Limited to RM6000): RM";
        cin >> equipment;
        equipment = min(6000.0, equipment);
    }
    while(cin.fail() || equipment < 0);
        cin.clear(); 
        cin.ignore();    
    
    // Loop to ensure valid input for lifestyleexpenses
    do{
        if(cin.fail() || lifestyleexpenses < 0)
        {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout << "c. How much did you spend on lifestyle expenses, such as books, sports equipment, internet subscriptions, or smartphones? (Limited to RM2500): RM";
        cin >> lifestyleexpenses;
        lifestyleexpenses = min(2500.0, lifestyleexpenses);
    }
    while(cin.fail() || lifestyleexpenses < 0);
        cin.clear(); 
        cin.ignore();

    // Loop to ensure valid input for electricvehicles
    do{
        if(cin.fail() || electricvehicles < 0)
        {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout << "d. How much did you spend on electric vehicle charging facilities? (Limited to RM2500): RM";
        cin >> electricvehicles;
        electricvehicles = min(2500.0, electricvehicles);
    }
    while(cin.fail() || electricvehicles < 0);
        cin.clear(); 
        cin.ignore();

    // Loop to ensure valid input for medicalexpenses
    do{
        if(cin.fail() || medicalexpenses < 0)
        {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        cout << "e. How much did you spend on medical expenses? (Limited to RM10000): RM";
        cin >> medicalexpenses;
        medicalexpenses = min(10000.0, medicalexpenses);
    }
    while(cin.fail() || medicalexpenses < 0);
        cin.clear(); 
        cin.ignore();

    // Loop to ensure valid input for educationfee
    do {
            if (cin.fail() || educationfee < 0) {
                cout << "Invalid input. Please enter a valid number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "f. How much did you spend on self-education fees? (Limited to RM7000): RM";
            cin >> educationfee;
            educationfee = min(7000.0, educationfee);
        } while (cin.fail() || educationfee < 0);
        cin.clear();
        cin.ignore();

        // Calculate the total lifestyle tax relief
        TotalTaxRelief4 = MTParents + equipment + lifestyleexpenses + electricvehicles + medicalexpenses + educationfee;
    }


//Function purpose: Getting the Total Tax Relief
double Total_Tax_Relief(double TotalTaxRelief1, double TotalTaxRelief2, double TotalTaxRelief3, double TotalTaxRelief4)
{
    // Declare variables & Calculate total tax relief by summing up individual tax reliefs
    double TotalTaxRelief = TotalTaxRelief1 + TotalTaxRelief2 + TotalTaxRelief3 + TotalTaxRelief4;
    return TotalTaxRelief;
}

int main()
{
    double TotalTaxRelief1 = 0.0;
    double TotalTaxRelief2 = 0.0;
    double TotalTaxRelief3 = 0.0;
    double TotalTaxRelief4 = 0.0;
    cout << "Welcome to the Tax Relief Calculator!" << endl;
    cout << "Please answer the following questions to calculate your tax relief." << endl;
    Marital_Status(TotalTaxRelief1);
    Children(TotalTaxRelief2);
    Contribution(TotalTaxRelief3);
    Lifestyle(TotalTaxRelief4);
    double totalTaxRelief = Total_Tax_Relief(TotalTaxRelief1, TotalTaxRelief2, TotalTaxRelief3, TotalTaxRelief4);

    PrintReliefs();
    cout << "Your total tax relief is: RM" << totalTaxRelief << endl;
}

void PrintReliefs()
{
    
    double EPF1, EPF2, ins, SOCSO, PRS, SSPN, MTParents, equipment, lifestyleexpenses, electricvehicles, medicalexpenses, educationfee, childcarefee;
    cout << setw(70) << "\n<Tax Reliefs>" << endl;
    cout << "======================================================================================================" << endl;
    cout << "1.  EPF Contributions (Limited to RM4000):                                    |RM" << EPF1 << endl;
    cout << "2.  Life Insurance/Extra EPF Contributions (Limited to RM3000):               |RM" << EPF2 << endl;
    cout << "3.  Education and Medical Insurance (Limited to RM3000):                      |RM" << ins << endl;
    cout << "4.  SOCSO Contributions (Limited to RM350):                                   |RM" << SOCSO << endl;
    cout << "5.  Deferred Annuity and PRS (Limited to RM3000):                             |RM" << PRS << endl;
    cout << "6.  SSPN Savings (Limited to RM8000):                                         |RM" << SSPN << endl;
    cout << "7.  Medical Treatment for Parents (Limited to RM8000):                        |RM" << MTParents << endl;
    cout << "8.  Basic Supporting Equipment for Disabled Family Member (Limited to RM6000):|RM" << equipment << endl;
    cout << "9.  Lifestyle Expenses (Limited to RM2500):                                   |RM" << lifestyleexpenses << endl;
    cout << "10. Electric Vehicle Charging Facilities (Limited to RM2500):                 |RM" << electricvehicles << endl;
    cout << "11. Medical Expenses (Limited to RM10000):                                    |RM" << medicalexpenses << endl;
    cout << "12. Self-Education Fees (Limited to RM7000):                                  |RM" << educationfee << endl;
    cout << "13. Childcare Fees (Limited to RM3000):                                       |RM" << childcarefee << endl;
    cout << "======================================================================================================" << endl;
}