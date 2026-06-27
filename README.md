# 🔐 SecureKey

**SecureKey** is a C++ command-line application that helps users create and evaluate strong passwords. It combines a **Password Strength Checker** with a **Secure Password Generator**, making it a simple yet practical cybersecurity utility for learning and everyday use.

---

## ✨ Features

### 🔍 Password Strength Checker

Validate passwords against common security best practices:

* ✅ Length between **8 and 16 characters**
* ✅ At least **one uppercase letter**
* ✅ At least **one lowercase letter**
* ✅ At least **one digit**
* ✅ At least **one special character**
* ✅ Clear feedback explaining why a password is considered weak

### 🔑 Secure Password Generator

Generate strong passwords with customizable options:

* Choose password length (8–16 characters)
* Generate multiple passwords at once
* Includes uppercase, lowercase, numbers, and special characters
* Characters are randomized for improved password complexity

### 🎨 User-Friendly CLI

* Interactive menu system
* Color-coded terminal output
* Easy-to-understand validation messages
* Lightweight and fast

---

# 🚀 Getting Started

## Requirements

* C++11 or later
* g++ (or any compatible C++ compiler)

## Installation

Clone the repository:

```bash
git clone https://github.com/yourusername/SecureKey.git
cd SecureKey
```

Compile:

```bash
g++ -std=c++11 main.cpp -o SecureKey
```

Run:

```bash
./SecureKey
```

---

# 📖 Usage

When the application starts:

```text
1. Check Password
2. Generate Password
3. Exit
```

### Password Checker

* Enter a password.
* SecureKey verifies all security requirements.
* Missing requirements are displayed with helpful messages.

### Password Generator

* Select a password length.
* Choose how many passwords to generate.
* Receive secure, randomly generated passwords instantly.

---

# 📂 Project Structure

```text
SecureKey/
│
├── main.cpp
├── README.md
└── LICENSE
```

---

# ⚙️ Technologies Used

**Language**

* C++

**Standard Libraries**

* iostream
* string
* cstdlib
* ctime
* algorithm

---

# 📸 Example Output

### Password Strength Checker

```text
Enter your password: weak

PASSWORD MUST BE BETWEEN 8 AND 16 CHARACTERS

Enter your password: WeakPassword

WEAK PASSWORD! Must contain:
- At least one digit
- At least one special character

Enter your password: StrongP@ssw0rd!

STRONG PASSWORD! All requirements met.
```

### Password Generator

```text
Enter password length (8-16): 12
How many passwords to generate? 3

Password 1: xK#9mP$2nL@7
Password 2: R!5tQw&3eA#8
Password 3: jH*1pL^6iG$4

Remember to save your password securely!
```

---

# 🛡️ Security Notes

SecureKey follows common password security guidelines by:

* Enforcing minimum password length
* Requiring character diversity
* Ensuring generated passwords include every required character type
* Never storing passwords
* Never transmitting passwords over a network

---

# 🤝 Contributing

Contributions, suggestions, and improvements are welcome.

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Open a Pull Request

---

# 📄 License

This project is licensed under the **MIT License**.

---

## ⭐ Support

If you found this project useful, consider giving it a **⭐ Star** on GitHub.
