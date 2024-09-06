#include <iostream>
#include <map>
#include <string>
using namespace std;

// Structure to hold account details
struct Account {
    string name;
    int accountNumber;
    double balance;
};

// Class to manage bank operations
class Bank {
private:
    map<int, Account> accounts; // Map of accountNumber to Account
    int nextAccountNumber = 1001;

public:
    // Function to create a new account
    void createAccount() {
        Account newAccount;
        cout << "Enter the account holder's name: ";
        cin >> newAccount.name;
        newAccount.accountNumber = nextAccountNumber++;
        newAccount.balance = 0.0;
        accounts[newAccount.accountNumber] = newAccount;
        cout << "Account created successfully! Your account number is: " << newAccount.accountNumber << endl;
    }

    // Function to deposit money into an account
    void deposit() {
        int accountNumber;
        double amount;
        cout << "Enter your account number: ";
        cin >> accountNumber;

        if (accounts.find(accountNumber) != accounts.end()) {
            cout << "Enter the amount to deposit: ";
            cin >> amount;
            accounts[accountNumber].balance += amount;
            cout << "Deposit successful! New balance: $" << accounts[accountNumber].balance << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }

    // Function to withdraw money from an account
    void withdraw() {
        int accountNumber;
        double amount;
        cout << "Enter your account number: ";
        cin >> accountNumber;

        if (accounts.find(accountNumber) != accounts.end()) {
            cout << "Enter the amount to withdraw: ";
            cin >> amount;
            if (accounts[accountNumber].balance >= amount) {
                accounts[accountNumber].balance -= amount;
                cout << "Withdrawal successful! New balance: $" << accounts[accountNumber].balance << endl;
            } else {
                cout << "Insufficient balance!" << endl;
            }
        } else {
            cout << "Account not found!" << endl;
        }
    }

    // Function to check the balance of an account
    void checkBalance() {
        int accountNumber;
        cout << "Enter your account number: ";
        cin >> accountNumber;

        if (accounts.find(accountNumber) != accounts.end()) {
            cout << "Account balance: $" << accounts[accountNumber].balance << endl;
        } else {
            cout << "Account not found!" << endl;
        }
    }
};

int main() {
    Bank bank;
    int choice;

    while (true) {
        cout << "\n--- Bank Management System ---\n";
        cout << "1. Create Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Check Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bank.createAccount();
                break;
            case 2:
                bank.deposit();
                break;
            case 3:
                bank.withdraw();
                break;
            case 4:
                bank.checkBalance();
                break;
            case 5:
                cout << "Thank you for using the Bank Management System. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
