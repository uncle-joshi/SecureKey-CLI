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
* ✅ **Score-based rating system** (1-10) for password strength
* ✅ Clear feedback explaining why a password is considered weak
* ✅ Detailed breakdown of character composition and scoring

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

## 📊 Password Scoring System

SecureKey uses a comprehensive scoring system to evaluate password strength on a scale of **1 to 10**. The score is calculated based on:

### Character Type Scoring

| Character Type | Count | Points Awarded |
|----------------|-------|----------------|
| **Uppercase** | 1-2 | +1 |
| | 3-5 | +2 |
| | 6+ | +3 |
| **Lowercase** | 1-2 | +1 |
| | 3-5 | +2 |
| | 6+ | +3 |
| **Digits** | 1-2 | +1 |
| | 3-5 | +2 |
| | 6+ | +3 |
| **Special** | 1-2 | +2 |
| | 3-5 | +4 |
| | 6+ | +6 |

### Length Bonus

| Password Length | Bonus Points |
|-----------------|--------------|
| 8-10 characters | +1 |
| 11-13 characters | +2 |
| 14-16 characters | +3 |

### Score Ratings

| Score Range | Rating |
|-------------|--------|
| 9-10 | 🟢 EXCELLENT - Very strong! |
| 7-8 | 🟢 STRONG - All requirements met |
| 5-6 | 🟡 MODERATE - Consider adding more variety |
| 0-4 | 🔴 WEAK - Improve with more character types |

### Scoring Examples

**Password: `zAin@12345`**
- Uppercase: 1 → +1
- Lowercase: 3 → +2
- Digits: 5 → +2
- Special: 1 → +2
- Length Bonus (10 chars) → +1
- **Total Score: 8/10** 🟢 STRONG

**Password: `P@ssw0rd#2024!`**
- Uppercase: 2 → +1
- Lowercase: 4 → +2
- Digits: 4 → +2
- Special: 3 → +4
- Length Bonus (13 chars) → +2
- **Total Score: 10/10** 🟢 EXCELLENT

**Password: `Abc123`**
- Uppercase: 1 → +1
- Lowercase: 2 → +1
- Digits: 3 → +2
- Special: 0 → +0
- Length Bonus (6 chars) → +0 (fails minimum length)
- **Total Score: 4/10** 🔴 WEAK

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
