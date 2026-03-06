# 🏦 ATM Management System (Simulation)

A robust, console-based **ATM Simulation System** developed in C++. This project demonstrates fundamental programming concepts including File Handling, Modular Programming, and Input Validation.

---

## 🚀 Key Features
* **Secure Authentication:** Validates users via Account Number and PinCode.
* **Smart Transactions:** * **Quick Withdraw:** Fixed amounts for faster user experience.
    * **Normal Withdraw:** Custom amounts with validation (multiples of 5).
    * **Secure Deposit:** Ensures only positive amounts are processed.
* **Real-time Balance Inquiry:** Instant access to account funds.
* **Data Persistence:** All transactions are updated and saved to a local database (`ClientData.txt`).
* **Input Validation:** Robust logic to prevent negative inputs or exceeding balance limits.

## 🛠 Technical Stack
* **Language:** C++
* **Architecture:** Modular Design (Separation of concerns using `.h` files).
* **File Handling:** Reading and writing structured data to `.txt` files.
* **Data Structures:** Using `Vectors` and `Structs` for efficient data management.

🖥️ Main Menu Navigation
The Main Menu serves as the central control hub of the application. It is designed with a clean interface to ensure a smooth and logical user experience for all banking tasks.
<img width="1112" height="601" alt="ATMMainMenu" src="https://github.com/user-attachments/assets/125f2cb3-1092-43ad-83b4-8494cde73527" />

Available Services:
[1] Quick Withdraw ⚡

Description: Offers a fast-track way to withdraw pre-set amounts (e.g., 20, 50, 100) without manual typing.
<img width="1112" height="602" alt="QuickWithdraw" src="https://github.com/user-attachments/assets/2e4dc8e3-3fc5-43e5-8058-4f191bb8a5ed" />

[2] Normal Withdraw 💸

Description: Provides the flexibility to enter a custom amount for withdrawal (must be a multiple of 5).
<img width="1111" height="575" alt="NormalWithdraw" src="https://github.com/user-attachments/assets/40b579ab-96e6-44bd-83e3-fe0bdc8f986d" />

[3] Deposit 📥

Description: Allows users to add funds to their account securely. The system strictly validates that only positive amounts are accepted.
<img width="1116" height="607" alt="Deposit" src="https://github.com/user-attachments/assets/c7a97888-e2c6-424e-b8e8-446dad914645" />

[4] Check Balance 🔍

Description: A dedicated screen for users to view their current financial status and total available balance instantly.
<img width="1111" height="617" alt="CheckBalance" src="https://github.com/user-attachments/assets/59b2314f-97e4-4824-b605-533673c53091" />

[5] Logout 🔑

Description: Ends the current user session securely and returns to the login screen to protect sensitive data.
<img width="1108" height="585" alt="Login" src="https://github.com/user-attachments/assets/a625ab23-786d-4468-b28d-2d9ffa2a0b61" />

[6] Exit 🚪

Description: Safely shuts down the application while ensuring all transaction data is permanently saved to the database file.
<img width="1120" height="587" alt="End" src="https://github.com/user-attachments/assets/51feab5d-baa4-4fe1-a019-3190b5121e9e" />


## 🌟 Future Goals & Roadmap
This project is part of my dedicated **Gap Year** journey, where I am sharpening my software engineering skills and building a solid technical foundation. 
My next steps include:
- Implementing **Object-Oriented Programming (OOP)** principles to enhance code reusability.
- Adding a **Multi-User Admin Panel** for managing client records.
- Transitioning the interface from Console to a **Graphical User Interface (GUI)**.
  ---
*“Programming isn't just about what you know; it's about what you can figure out.”* **Happy Coding! 🚀**
