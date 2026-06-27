#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

string red = "\033[31m";
string green = "\033[32m";
string yellow = "\033[33m";
string reset = "\033[0m";

void check_password_strength();
void generate_password();

int main () {
    cout << "PASSWORD STRENGTH CHECKER\n";
    cout << "Requirements: 8-16 chars, at least 1 upper, 1 lower, 1 digit, 1 special\n\n";

    cout << "Menu:\n";
    cout << "1. Check Password\n";
    cout << "2. Generate Password\n";
    cout << "3. Exit\n\n";

    string choice;

    while (true) {
        cout << "Choose Option: ";
        getline(cin, choice);

        if (choice.empty()){
            cout << red << "Please select an option" << reset << "\n";
            continue;
        }

        if (choice != "1" && choice != "2" && choice != "3") {
            cout << red << "INVALID CHOICE!" << reset << "\n";
            continue;
        }

        if (choice == "1") {
            cout << "\nCHECK PASSWORD\n";
            check_password_strength();
            break;
        }

        if (choice == "2") {
            cout << "\nGENERATE PASSWORD\n";
            generate_password();
            break;
        }

        if (choice == "3") {
            cout << "\nEXIT\n";
            break;
        }
    }

    return 0;
}

void check_password_strength() {
    string password;

    string uppercase_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowercase_letters = "abcdefghijklmnopqrstuvwxyz";
    string digits = "0123456789";
    string special_characters = "!@#$%^&*()_+-=[]{}\\|;:'\",.<>/?";

    int min_password_length = 8;
    int max_password_length = 16;

    while (true) {
        cout << "Enter your password: ";
        getline(cin, password);

        if (password.empty()) {
            cout << red << "PASSWORD IS EMPTY\n" << reset;
            continue;
        }

        if (password.length() < min_password_length || password.length() > max_password_length) {
            cout << yellow << "PASSWORD MUST BE BETWEEN " << min_password_length 
                 << " AND " << max_password_length << " CHARACTERS\n\n" << reset;
            continue; 
        }
        
        bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;
        
        for (char c : password) {
            if (uppercase_letters.find(c) != string::npos) hasUpper = true;
            else if (lowercase_letters.find(c) != string::npos) hasLower = true;
            else if (digits.find(c) != string::npos) hasDigit = true;
            else if (special_characters.find(c) != string::npos) hasSpecial = true;
        }
        
        if (!hasUpper || !hasLower || !hasDigit || !hasSpecial) {
            cout << red << "WEAK PASSWORD! Must contain:" << reset << endl;
            if (!hasUpper) cout << yellow << "- At least one uppercase letter" << reset << endl;
            if (!hasLower) cout << yellow << "- At least one lowercase letter" << reset << endl;
            if (!hasDigit) cout << yellow << "- At least one digit" << reset << endl;
            if (!hasSpecial) cout << yellow << "- At least one special character" << reset << endl;
            continue;
        }
        
        cout << green << "STRONG PASSWORD! All requirements met.\n" << reset;
        break;  
    }
}

void generate_password() {
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string digits = "0123456789";
    string special = "!@#$%^&*()_+-=[]{}\\|;:'\",.<>/?";
    string all = uppercase + lowercase + digits + special;
    
    srand(time(0));
    
    int length;
    cout << "Enter password length (8-16): ";
    cin >> length;
    cin.ignore();
    
    while (length < 8 || length > 16) {
        cout << red << "Length must be 8-16: " << reset;
        cin >> length;
        cin.ignore();
    }
    
    int num_passwords;
    cout << "How many passwords to generate? ";
    cin >> num_passwords;
    cin.ignore();
    
    for (int p = 0; p < num_passwords; p++) {
        string password = "";
        
        password += uppercase[rand() % uppercase.length()];
        password += lowercase[rand() % lowercase.length()];
        password += digits[rand() % digits.length()];
        password += special[rand() % special.length()];
        
        for (int i = 4; i < length; i++) {
            password += all[rand() % all.length()];
        }
        
        for (int i = 0; i < password.length(); i++) {
            int j = rand() % password.length();
            swap(password[i], password[j]);
        }
        
        cout << green << "Password " << (p + 1) << ": " << password << reset << endl;
    }
    
    cout << yellow << "\nRemember to save your password securely!" << reset << endl;
}