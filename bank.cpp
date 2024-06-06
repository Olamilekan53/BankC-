#include <iostream>
#include <string>

class BankAccount {
private:
    std::string owner;
    double balance;

public:
    // Constructor
    BankAccount(std::string ownerName, double initialBalance = 0.0) {
        owner = ownerName;
        balance = initialBalance;
    }

    // Deposit method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit of $" << amount << " successful. New balance: $" << balance << std::endl;
        } else {
            std::cout << "Deposit amount must be positive." << std::endl;
        }
    }

    // Withdraw method
    void withdraw(double amount) {
        if (amount > 0) {
            if (amount <= balance) {
                balance -= amount;
                std::cout << "Withdrawal of $" << amount << " successful. New balance: $" << balance << std::endl;
            } else {
                std::cout << "Insufficient funds for this withdrawal." << std::endl;
            }
        } else {
            std::cout << "Withdrawal amount must be positive." << std::endl;
        }
    }

    // Display balance method
    void displayBalance() const {
        std::cout << owner << "'s account balance: $" << balance << std::endl;
    }
};

int main() {
    std::string fullname;
    std::cout << "Enter your full name: ";
    std::getline(std::cin, fullname);

    // Creating a bank account for the user
    BankAccount userAccount(fullname);

    int choice;
    double amount;

    do {
        std::cout << "\nBank Menu:\n";
        std::cout << "1. Deposit Money\n";
        std::cout << "2. Withdraw Money\n";
        std::cout << "3. Display Balance\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice (1-4): ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                userAccount.deposit(amount);
                break;
            case 2:
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                userAccount.withdraw(amount);
                break;
            case 3:
                userAccount.displayBalance();
                break;
            case 4:
                std::cout << "Exiting the application." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a number between 1 and 4." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
