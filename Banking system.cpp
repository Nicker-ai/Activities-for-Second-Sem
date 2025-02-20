#include <iostream>
#include <string>
#include <limits>
#include <ctime>

using namespace std;

#define MAX_ACCOUNTS 10
#define MAX_TRANSACTIONS 100

// Structure to store transaction details
struct Transaction {
    string type;      // "Deposit" or "Withdrawal"
    double amount;
    double balance;   // Balance after transaction
    string date;      // Date of transaction
};

// Function to get current date as string
string getCurrentDate() {
    time_t now = time(0);
    string date = ctime(&now);
    return date.substr(0, date.length() - 1); // Remove newline character
}

// Function to clear input buffer and handle invalid input
void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to get valid integer input
int getIntInput() {
    int input;
    while (!(cin >> input)) {
        cout << "Invalid input! Please enter a number: ";
        clearInputBuffer();
    }
    clearInputBuffer();
    return input;
}

// Function to get valid double input
double getDoubleInput() {
    double input;
    while (!(cin >> input)) {
        cout << "Invalid input! Please enter a number: ";
        clearInputBuffer();
    }
    clearInputBuffer();
    return input;
}

// Function to get valid string input
string getStringInput() {
    string input;
    while (true) {
        getline(cin, input);
        if (!input.empty()) {
            bool valid = true;
            for (int i = 0; i < input.length(); i++) {
                if (!isalpha(input[i]) && !isspace(input[i])) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                return input;
            }
        }
        cout << "Invalid input! Please enter only letters: ";
    }
}

class Account {
private:
    string name;
    int accountNumber;
    double balance;
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount;

public:
    Account(string n, int accNum) {
        name = n;
        accountNumber = accNum;
        balance = 0;
        transactionCount = 0;
    }

    string getName() {
        return name;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void addTransaction(string type, double amount) {
        if (transactionCount < MAX_TRANSACTIONS) {
            transactions[transactionCount].type = type;
            transactions[transactionCount].amount = amount;
            transactions[transactionCount].balance = balance;
            transactions[transactionCount].date = getCurrentDate();
            transactionCount++;
        }
    }

    bool deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            addTransaction("Deposit", amount);
            return true;
        }
        return false;
    }

    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            addTransaction("Withdrawal", amount);
            return true;
        }
        return false;
    }

    void showTransactionHistory() {
        cout << "\nTransaction History for Account " << accountNumber << " (" << name << ")\n";
        cout << "--------------------------------------------------------\n";
        cout << "Date                  Type        Amount    Balance\n";
        cout << "--------------------------------------------------------\n";
        
        for (int i = 0; i < transactionCount; i++) {
            cout << transactions[i].date << "    ";
            cout << transactions[i].type;
            // Padding for alignment
            for (int j = 0; j < 12 - transactions[i].type.length(); j++) {
                cout << " ";
            }
            cout << "$" << transactions[i].amount << "    $" << transactions[i].balance << endl;
        }
        cout << "--------------------------------------------------------\n";
    }
};

class Bank {
private:
    Account* accounts[MAX_ACCOUNTS];
    int numAccounts;
    int nextAccountNumber;

public:
    Bank() {
        numAccounts = 0;
        nextAccountNumber = 1001;
        for (int i = 0; i < MAX_ACCOUNTS; i++) {
            accounts[i] = NULL;
        }
    }

    int createAccount(string name) {
        if (numAccounts >= MAX_ACCOUNTS) {
            return -1;
        }
        
        accounts[numAccounts] = new Account(name, nextAccountNumber);
        numAccounts++;
        return nextAccountNumber++;
    }

    Account* findAccount(int accountNumber) {
        for (int i = 0; i < numAccounts; i++) {
            if (accounts[i]->getAccountNumber() == accountNumber) {
                return accounts[i];
            }
        }
        return NULL;
    }
};

int main() {
    Bank bank;
    int choice, accountNum;
    string name;
    double amount;

    while (true) {
        cout << "\n\t\t\t\t\t\t =---------------------= \n";
		cout << "\n\t\t\t\t\t\t  Simple Banking System \n";
		cout << "\n\t\t\t\t\t\t =---------------------= \n";
		cout << "\n\n\n";
        cout << "\n\t\t\t\t\t 1. Create New Account\n";
        cout << "\n\t\t\t\t\t 2. Deposit Money\n";
        cout << "\n\t\t\t\t\t 3. Withdraw Money\n";
        cout << "\n\t\t\t\t\t 4. Check Balance\n";
        cout << "\n\t\t\t\t\t 5. View Transaction history\n";
        cout << "\n\t\t\t\t\t 6. Exit\n";
        cout << "\n\t\t\t\t\t Enter your choice (1-6): ";
        choice = getIntInput();
        
        system("cls");

        switch (choice) {
            case 1:
                cout << "\n\n\n\n\n\n";
                cout << "\n\t\t\t\t\tEnter your name (letters only) \n";
                cout << "\n\t\t\t\t\tAccount name: ";
                name = getStringInput();
                accountNum = bank.createAccount(name);
                if (accountNum != -1) {
                    system("cls");
                    cout << "\n\t\t\t\t   >> Account created! Your account number is: " << accountNum << endl;
                } else {
                    system("cls");
                    cout << "\n\t\t\t Sorry, cannot create more accounts. Maximum limit reached.\n";
                }
                break;

            case 2:
                cout << "Enter account number: ";
                accountNum = getIntInput();
                cout << "Enter amount to deposit: $";
                amount = getDoubleInput();
                if (Account* acc = bank.findAccount(accountNum)) {
                    if (acc->deposit(amount)) {
                        cout << "Deposit successful! New balance: $" << acc->getBalance() << endl;
                    } else {
                        cout << "Invalid amount for deposit. Amount must be positive.\n";
                    }
                } else {
                    cout << "Account not found!\n";
                }
                break;

            case 3:
                cout << "Enter account number: ";
                accountNum = getIntInput();
                cout << "Enter amount to withdraw: $";
                amount = getDoubleInput();
                if (Account* acc = bank.findAccount(accountNum)) {
                    if (acc->withdraw(amount)) {
                        cout << "Withdrawal successful! New balance: $" << acc->getBalance() << endl;
                    } else {
                        cout << "Insufficient funds or invalid amount.\n";
                    }
                } else {
                    cout << "Account not found!\n";
                }
                break;

            case 4:
                cout << "Enter account number: ";
                accountNum = getIntInput();
                if (Account* acc = bank.findAccount(accountNum)) {
                    cout << "Account holder: " << acc->getName() << endl;
                    cout << "Current balance: $" << acc->getBalance() << endl;
                } else {
                    cout << "Account not found!\n";
                }
                break;

            case 5:
                cout << "Enter account number: ";
                accountNum = getIntInput();
                if (Account* acc = bank.findAccount(accountNum)) {
                    acc->showTransactionHistory();
                } else {
                    cout << "Account not found!\n";
                }
                break;

            case 6:
                cout << "Thank you for using our banking system!\n";
                return 0;

            default:
                cout << "Invalid choice! Please enter a number between 1 and 6.\n";
        }
    }
    return 0;
}
