#include <iostream>
#include <string>
using namespace std;

class ATM {
private:
    int pin = 1234;             // Default ATM pin
    double balance = 1000.00;   // Default balance
    int enteredPin;

public:
    // Function to verify PIN
    bool verifyPin() {
        cout << "Enter PIN: ";
        cin >> enteredPin;
        if (enteredPin == pin) {
            return true;
        } else {
            cout << "Incorrect PIN. Please try again.\n";
            return false;
        }
    }

    // Function to check balance
    void checkBalance() {
        cout << "Your current balance is: $" << balance << endl;
    }

    // Function to deposit money
    void depositMoney() {
        double deposit;
        cout << "Enter amount to deposit: $";
        
        cin >> deposit;
        if (deposit > 0) {
            balance += deposit;
            cout << "$" << deposit << " has been deposited. New balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Function to withdraw money
    void withdrawMoney() {
        double withdraw;
        cout << "Enter amount to withdraw: $";
        cin >> withdraw;
        if (withdraw <= balance) {
            if (withdraw > 0) {
                balance -= withdraw;
                cout << "$" << withdraw << " has been withdrawn. New balance: $" << balance << endl;
            } else {
                cout << "Invalid withdrawal amount.\n";
            }
        } else {
            cout << "Insufficient balance.\n";
        }
    }

    // Main menu
    void displayMenu() {
        int choice;
        do {
            cout << "\nATM Menu:\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    checkBalance();
                    break;
                case 2:
                    depositMoney();
                    break;
                case 3:
                    withdrawMoney();
                    break;
                case 4:
                    cout << "Thank you for using the ATM. Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 4);
    }
};

int main() {
    ATM atm;
    
    cout << "Welcome to the ATM\n";

    if (atm.verifyPin()) {
        atm.displayMenu();
    } else {
        cout << "Too many incorrect attempts. Exiting...\n";
    }

    return 0;
}
