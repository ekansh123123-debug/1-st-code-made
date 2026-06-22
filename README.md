# Simple Account Management System 🔐

A lightweight, console-based user authentication and account management application written in C++. The system uses file-based storage to persist user credentials, allowing users to register new accounts, log into existing accounts, and recover forgotten passwords.

---

## 🚀 Features

* **User Registration:** Creates new user accounts. Validates username unique availability, checks email formats, and enforces minimum password lengths.
* **Secure-ish File Storage:** Persists credential data inside a local flat-file (`loginid.txt`) using deliberate delimiters (`*`) to separate fields.
* **User Authentication (Login):** Validates user credentials against stored parameters before granting access.
* **Password Recovery:** Provides a simple utility to recover lost passwords by cross-referencing matching usernames and recovery emails.

---

## 🛠️ Validation System Rules

The application uses specific sanity checks to ensure data integrity during registration:

| Metric | Rule Criteria | Validation Logic |
| :--- | :--- | :--- |
| **Username Length** | Greater than 4 characters | Minimum of 5 alphanumeric characters |
| **Username Availability** | Must be globally unique | Scans database to prevent profile overwrites |
| **Email Formatting** | Standard pattern validation | Checks for sequential availability of `@` and `.` characters |
| **Password Strength** | Length enforcement | Minimum string length of 6 characters |

---

## 📁 File Structure & Storage Format

All accounts are appended to a text file named `loginid.txt` in the root execution directory. Profiles are written line-by-line using custom field segregation:

```text
username*email_address*password
⚠️ Note: Passwords are currently stored as plain text for simplicity. For production environments, integrating a cryptographic hashing algorithm (like SHA-256 or bcrypt) is highly recommended.

💻 Technical Prerequisites & Building
Requirements
A standard modern C++ compiler supporting at least C++11 or higher (such as g++, clang++, or MSVC).

Building via Terminal
Clone or save the source code into a file named main.cpp.

Compile using a standard C++ CLI toolset:

Bash
g++ -std=c++11 main.cpp -o AccountSystem
Run the compiled binary:

Bash
./AccountSystem
🔄 Core Program Workflow
Main Menu Loop: The console prompts the user to select one of four standard options: Login, Register, Forgot Password, or Exit.

Global Application State: State mutations and database writing actions are governed safely through an encapsulated Account object.

Stream Management: Input streams utilize std::cin.ignore() across choice selections to elegantly clear string delimiters and neutralize residual trailing newlines.
