# password-strength-checker
🔐 Password Strength Checker &amp; Generator - A C++ CLI tool that validates password strength based on security requirements and generates strong random passwords. Features color-coded output, multiple password generation, and comprehensive strength analysis.

# 🔐 Password Strength Checker & Generator

A comprehensive command-line tool built in C++ that checks password strength and generates secure random passwords. This tool enforces strong password policies by validating against industry-standard security requirements.

## ✨ Features

- **Password Validation**: Checks if a password meets security requirements
  - Minimum 8 characters, maximum 16 characters
  - At least one uppercase letter (A-Z)
  - At least one lowercase letter (a-z)
  - At least one digit (0-9)
  - At least one special character (!@#$%^&*()_+-=[]{}\|;:'",.<>/?)

- **Password Generation**: Creates strong random passwords
  - Customizable length (8-16 characters)
  - Guarantees at least one character from each required category
  - Randomly shuffled for maximum security
  - Generate multiple passwords at once

- **User-Friendly Interface**
  - Color-coded output (red for errors, yellow for warnings, green for success)
  - Clear feedback on validation failures
  - Interactive menu system

## 🚀 Getting Started

### Prerequisites

- C++ compiler (g++ recommended)
- C++11 or higher

### Installation

1. Clone the repository:
```bash
git clone https://github.com/yourusername/password-strength-checker.git
cd password-strength-checker
```
2. Compile the program:
```bash
g++ -std=c++11 main.cpp -o password-checker
```
3. Run the program:
```bash
./password-checker
```

Usage
```bash
PASSWORD STRENGTH CHECKER
Requirements: 8-16 chars, at least 1 upper, 1 lower, 1 digit, 1 special

Menu:
1. Check Password
2. Generate Password
3. Exit

Choose Option:
Check Password
Enter your password: 

The tool will validate it against all requirements

Provides specific feedback on what's missing

Option 2: Generate Password
Choose password length (8-16)

Specify how many passwords to generate

Get strong random passwords instantly

Option 3: Exit
Exit the program
```

## 📝 Code Structure
```bash
main.cpp
├── check_password_strength()
│   ├── Validates password length (8-16 chars)
│   ├── Checks for uppercase letters
│   ├── Checks for lowercase letters
│   ├── Checks for digits
│   └── Checks for special characters
├── generate_password()
│   ├── Generates random passwords
│   ├── Ensures all character types are included
│   └── Shuffles characters for randomness
└── main()
    ├── Displays menu
    ├── Handles user input
    └── Calls appropriate functions
```

## 🛠️ Technologies Used
Language: C++
Libraries:
iostream - Input/Output operations
string - String manipulation
cstdlib - Random number generation
ctime - Seed for random generator
algorithm - Shuffle functionality

## 🎨 Color Coding
🔴 Red: Errors and invalid inputs
🟡 Yellow: Warnings and missing requirements
🟢 Green: Success and valid passwords
⚪ Reset: Default text color

### 📊 Example Output
```bash
Enter your password: weak
PASSWORD MUST BE BETWEEN 8 AND 16 CHARACTERS

Enter your password: WeakPassword
WEAK PASSWORD! Must contain:
- At least one digit
- At least one special character

Enter your password: StrongP@ssw0rd!
STRONG PASSWORD! All requirements met.
Password Generation
text
Enter password length (8-16): 12
How many passwords to generate? 3

Password 1: xK#9mP$2nL@7
Password 2: R!5tQw&3eA#8
Password 3: jH*1pL^6iG$4

Remember to save your password securely!
```

## 🔒 Security Best Practices
This tool follows industry-standard password security practices:
Enforces minimum length requirements
Requires character diversity
Generates cryptographically random passwords (using time-based seeding)
Does not store or transmit passwords

