#include "getting_details.hpp"
#include "main.hpp"

// Function to capitalize a string
string capitalize(const string& input) {
    string result = input;
    for (char& c : result) {
        c = static_cast<char>(toupper(static_cast<unsigned char>(c))); // Fix: Explicit cast
    }
    return result;
}

// Function to validate IC number format
bool is_valid_ic(const string& ic) {
    regex pattern("^\\d{6}-\\d{2}-\\d{4}$");
    return regex_match(ic, pattern);
}

// Function to get the current date
string getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[11];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", ltm);
    return string(buffer);
}

// Function to get user details
void GettingDetails() {
    cout << "\n==========================================================\n";
    cout << "              <Part 1. Personal Details>\n";
    cout << "==========================================================\n";

    // Getting User's Name
    cout << "Name: ";
    cin.ignore(); // Clear the input buffer
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

    // Getting and Validating User TIN
    regex tinPattern("^[A-Za-z0-9]{10,15}$");
    do {
        cout << "Tax Identification Number (TIN): ";
        getline(cin, user.TIN);
        if (!regex_match(user.TIN, tinPattern)) {
            cout << "Invalid TIN. Please Try Again.\n";
        }
    } while (!regex_match(user.TIN, tinPattern));

    // Getting User's Religion
    do {
        cout << "Religion (M: Muslim, C: Christian, B: Buddhist, H: Hindu, O: Others): ";
        cin >> user.religion;
        user.religion = static_cast<char>(toupper(static_cast<unsigned char>(user.religion))); // Fix: Explicit cast

        if (user.religion == 'M' || user.religion == 'C' || user.religion == 'B' || user.religion == 'H' || user.religion == 'O') {
            switch (user.religion) {
                case 'M': religionName = "Islam"; break;
                case 'C': religionName = "Christian"; break;
                case 'B': religionName = "Buddhist"; break;
                case 'H': religionName = "Hindu"; break;
                case 'O': religionName = "Others"; break;
                default: religionName = "Unknown"; break;
            }
            break;
        } else {
            cout << "Invalid Character. Please Try Again.\n";
        }
    } while (true);

    // Getting User's Children Status
    do {
        cout << "Do you have children? (Yes = Y | No = N): ";
        cin >> user.children;
        user.children = static_cast<char>(toupper(static_cast<unsigned char>(user.children))); // Fix: Explicit cast
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid. Try Again.\n";
        }
    } while (user.children != 'Y' && user.children != 'N');

    if (user.children == 'Y') {
        cout << "Number of Children: ";
        while (!(cin >> user.NoOfChild) || user.NoOfChild < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a non-negative integer: ";
        }
    } else {
        user.NoOfChild = 0;
    }

    // Getting User's Disability Status
    do {
        cout << "Do you have any disability? (Yes = Y | No = N): ";
        cin >> user.disability;
        user.disability = static_cast<char>(toupper(static_cast<unsigned char>(user.disability))); // Fix: Explicit cast
        if (user.disability == 'Y') {
            cin.ignore(); // Clear the input buffer
            cout << "Describe Disability: ";
            getline(cin, DisabilityType);
        }
        else{
            cout <<"Invalid. Try Again.";
        }
    } while (user.disability != 'Y' && user.disability != 'N');

    // Getting User's Marital Status
    do {
        cout << "Do you have a spouse? (Yes = Y | No = N): ";
        cin >> user.spouse;
        user.spouse = static_cast<char>(toupper(static_cast<unsigned char>(user.spouse))); // Fix: Explicit cast
        if (user.spouse == 'Y') {
            marital_status = "Married";
        } else if (user.spouse == 'N') {
            marital_status = "Single";
        } else {
            cout << "Invalid. Try Again.\n";
        }
    } while (user.spouse != 'Y' && user.spouse != 'N');
}

// Function to print collected details
void PrintDetails() {
    cout << "\n==========================================================\n";
    cout << "              <Part 1. Personal Details>\n";
    cout << "==========================================================\n";
    cout << "Date:               " << getCurrentDate() << endl;
    cout << "Name:               " << user.name << endl;
    cout << "IC No.:             " << user.ic << endl;
    cout << "Phone No.:          " << user.phoneNo << endl;
    cout << "Email:              " << user.email << endl;
    cout << "TIN:                " << user.TIN << endl;
    cout << "Religion:           " << religionName << endl;
    cout << "Marital Status:     " << marital_status << endl;
    cout << "Number of Children: " << user.NoOfChild << endl;
    cout << "Disability:         " << (user.disability == 'Y' ? "Yes" : "None") << endl;
    if (user.disability == 'Y') {
        cout << "Type of Disability: " << DisabilityType << endl;
    }
    cout << "==========================================================\n";
}