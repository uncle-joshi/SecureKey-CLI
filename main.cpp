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
        
        int upperCount = 0, lowerCount = 0, digitCount = 0, specialCount = 0;
        int score = 0;
        
        // Count each type of character
        for (char c : password) {
            if (uppercase_letters.find(c) != string::npos) {
                upperCount++;
            } 
            else if (lowercase_letters.find(c) != string::npos) {
                lowerCount++;
            } 
            else if (digits.find(c) != string::npos) {
                digitCount++;
            } 
            else if (special_characters.find(c) != string::npos) {
                specialCount++;
            } 
        }
        
        // Score Uppercase: 1-2 = +1, 3-5 = +2, 6+ = +3
        if (upperCount >= 1 && upperCount <= 2) {
            score += 1;
        } else if (upperCount >= 3 && upperCount <= 5) {
            score += 2;
        } else if (upperCount >= 6) {
            score += 3;
        }
        
        // Score Lowercase: 1-2 = +1, 3-5 = +2, 6+ = +3
        if (lowerCount >= 1 && lowerCount <= 2) {
            score += 1;
        } else if (lowerCount >= 3 && lowerCount <= 5) {
            score += 2;
        } else if (lowerCount >= 6) {
            score += 3;
        }
        
        // Score Digits: 1-2 = +1, 3-5 = +2, 6+ = +3
        if (digitCount >= 1 && digitCount <= 2) {
            score += 1;
        } else if (digitCount >= 3 && digitCount <= 5) {
            score += 2;
        } else if (digitCount >= 6) {
            score += 3;
        }
        
        // Score Special: 1-2 = +2, 3-5 = +4, 6+ = +6
        if (specialCount >= 1 && specialCount <= 2) {
            score += 2;
        } else if (specialCount >= 3 && specialCount <= 5) {
            score += 4;
        } else if (specialCount >= 6) {
            score += 6;
        }
        
        // Length bonus
        if (password.length() >= 8 && password.length() <= 10) {
            score += 1;
        } else if (password.length() >= 11 && password.length() <= 13) {
            score += 2;
        } else if (password.length() >= 14 && password.length() <= 16) {
            score += 3;
        }
        
        // Cap score at 10
        if (score > 10) score = 10;
        
        // Check if all requirements are met
        bool hasUpper = upperCount > 0;
        bool hasLower = lowerCount > 0;
        bool hasDigit = digitCount > 0;
        bool hasSpecial = specialCount > 0;
        
        if (!hasUpper || !hasLower || !hasDigit || !hasSpecial) {
            cout << red << "WEAK PASSWORD! Must contain:" << reset << endl;
            if (!hasUpper) cout << yellow << "- At least one uppercase letter" << reset << endl;
            if (!hasLower) cout << yellow << "- At least one lowercase letter" << reset << endl;
            if (!hasDigit) cout << yellow << "- At least one digit" << reset << endl;
            if (!hasSpecial) cout << yellow << "- At least one special character" << reset << endl;
            continue;
        }

        cout << "\nPassword analysis:" << endl;
        cout << "  Uppercase: " << upperCount << " (Score: ";
        if (upperCount >= 1 && upperCount <= 2) cout << "+1";
        else if (upperCount >= 3 && upperCount <= 5) cout << "+2";
        else if (upperCount >= 6) cout << "+3";
        else cout << "+0";
        cout << ")" << endl;
        
        cout << "  Lowercase: " << lowerCount << " (Score: ";
        if (lowerCount >= 1 && lowerCount <= 2) cout << "+1";
        else if (lowerCount >= 3 && lowerCount <= 5) cout << "+2";
        else if (lowerCount >= 6) cout << "+3";
        else cout << "+0";
        cout << ")" << endl;
        
        cout << "  Digits: " << digitCount << " (Score: ";
        if (digitCount >= 1 && digitCount <= 2) cout << "+1";
        else if (digitCount >= 3 && digitCount <= 5) cout << "+2";
        else if (digitCount >= 6) cout << "+3";
        else cout << "+0";
        cout << ")" << endl;
        
        cout << "  Special: " << specialCount << " (Score: ";
        if (specialCount >= 1 && specialCount <= 2) cout << "+2";
        else if (specialCount >= 3 && specialCount <= 5) cout << "+4";
        else if (specialCount >= 6) cout << "+6";
        else cout << "+0";
        cout << ")" << endl;
        
        cout << "  Length: " << password.length() << " (Bonus: ";
        if (password.length() >= 8 && password.length() <= 10) cout << "+1";
        else if (password.length() >= 11 && password.length() <= 13) cout << "+2";
        else if (password.length() >= 14 && password.length() <= 16) cout << "+3";
        cout << ")" << endl;
        
        cout << "\n" << green << "Total Score: " << score << " out of 10" << reset << endl;
        
        // Rating based on score
        if (score >= 9) {
            cout << green << "EXCELLENT PASSWORD! Very strong!" << reset << endl;
        } else if (score >= 7) {
            cout << green << "STRONG PASSWORD! All requirements met." << reset << endl;
        } else if (score >= 5) {
            cout << yellow << "MODERATE PASSWORD - Consider adding more variety." << reset << endl;
        } else {
            cout << red << "WEAK PASSWORD - Improve with more character types." << reset << endl;
        }
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