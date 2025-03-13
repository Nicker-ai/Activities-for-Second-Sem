#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include <cstdlib>

using namespace std;

const int MAX_COMPUTERS = 50;

struct Computer {
    string name;
    int systemUnitQuantity;
    string systemUnitStatus;
    int mouseQuantity;
    string mouseStatus;
    int monitorQuantity;
    string monitorStatus;
    int powerSupplyQuantity;
    string powerSupplyStatus;
    int keyboardQuantity;
    string keyboardStatus;
    int lanCableQuantity;
    string lanCableStatus;

    string getStatus() {
        if (systemUnitStatus == "Not Working" || mouseStatus == "Not Working" || 
            monitorStatus == "Not Working" || powerSupplyStatus == "Not Working" || 
            keyboardStatus == "Not Working" || lanCableStatus == "Not Working") {
            return "Not Working";
        }
        return "Working";
    }

    void updateComponentStatus() {
        // Only update status based on quantities
        // If quantity is 0, component must be "Not Working"
        // Otherwise, status stays as manually set
        if (systemUnitQuantity == 0) systemUnitStatus = "Not Working";
        if (mouseQuantity == 0) mouseStatus = "Not Working";
        if (monitorQuantity == 0) monitorStatus = "Not Working";
        if (powerSupplyQuantity == 0) powerSupplyStatus = "Not Working";
        if (keyboardQuantity == 0) keyboardStatus = "Not Working";
        if (lanCableQuantity == 0) lanCableStatus = "Not Working";
    }
};

string intToString(int number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

void displayComputers(Computer computers[], int computerCount) {
    for (int i = 1; i < computerCount; i++) {
        cout << "\n==========================================================\n";
        cout << "------------------------------\n";
        cout << i << ": " << computers[i].name << " - " << computers[i].getStatus() << endl;
        cout << "------------------------------\n";
        cout << "  System Unit Status     : " << computers[i].systemUnitStatus << " (Quantity: " << computers[i].systemUnitQuantity << ")" << endl;
        cout << "  Mouse Status           : " << computers[i].mouseStatus << " (Quantity: " << computers[i].mouseQuantity << ")" << endl;
        cout << "  Monitor Status         : " << computers[i].monitorStatus << " (Quantity: " << computers[i].monitorQuantity << ")" << endl;
        cout << "  Power Supply Status    : " << computers[i].powerSupplyStatus << " (Quantity: " << computers[i].powerSupplyQuantity << ")" << endl;
        cout << "  Keyboard Status        : " << computers[i].keyboardStatus << " (Quantity: " << computers[i].keyboardQuantity << ")" << endl;
        cout << "  LAN Cable Status       : " << computers[i].lanCableStatus << " (Quantity: " << computers[i].lanCableQuantity << ")" << endl;
        cout << "\n==========================================================\n";
    }
}

// Fixed editComponentStatus function that only changes status without affecting quantity
void editComponentStatus(const string& componentName, string& status) {
    int statusInput;
    cout << "Enter " << componentName << " Status (1 for Working, 0 for Not Working): ";
    cin >> statusInput;
    while (cin.fail() || (statusInput != 0 && statusInput != 1)) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input! Please enter 1 for Working or 0 for Not Working: ";
        cin >> statusInput;
    }
    status = (statusInput == 1) ? "Working" : "Not Working";
}

// Function to add a component
void addComponent(const string& componentName, int& quantity) {
    int addQuantity;
    cout << "Enter the quantity of " << componentName << " to add: ";
    cin >> addQuantity;
    while (cin.fail() || addQuantity < 0) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input! Please enter a non-negative number: ";
        cin >> addQuantity;
    }
    quantity += addQuantity; // Increase the quantity
}

// Function to delete a component
void deleteComponent(const string& componentName, int& quantity, string& status) {
    int deleteQuantity;
    cout << "Enter the quantity of " << componentName << " to delete: ";
    cin >> deleteQuantity;
    while (cin.fail() || deleteQuantity < 0 || deleteQuantity > quantity) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input! Please enter a number between 0 and " << quantity << ": ";
        cin >> deleteQuantity;
    }
    quantity -= deleteQuantity; // Decrease the quantity
    
    // If quantity becomes 0, component must be "Not Working"
    if (quantity == 0) {
        status = "Not Working";
    }
}

int main() {
    Computer computers[MAX_COMPUTERS];
    for (int i = 1; i < 35; i++) {
        computers[i].name = "C" + intToString(i);
        computers[i].systemUnitQuantity = 1;
        computers[i].systemUnitStatus = "Working";
        computers[i].mouseQuantity = 1;
        computers[i].mouseStatus = "Working";
        computers[i].monitorQuantity = 1;
        computers[i].monitorStatus = "Working";
        computers[i].powerSupplyQuantity = 1;
        computers[i].powerSupplyStatus = "Working";
        computers[i].keyboardQuantity = 1;
        computers[i].keyboardStatus = "Working";
        computers[i].lanCableQuantity = 1;
        computers[i].lanCableStatus = "Working";
    }

    int computerCount = 35;
    int choice;

    do {
        system("cls");
        cout << "\t\t\t _______________________________________________________________________________________________________________________________\n";
        cout << "\t\t\t|               |   _________   |   _________   |   _________   |   _________   |               |   _________   |   _________   |\n";
        cout << "\t\t\t|               |  |C6       |  |  |C5       |  |  |C4       |  |  |C3       |  |               |  |C2       |  |  |C1       |  |\n";
        cout << "\t\t\t|               |  |_________|  |  |_________|  |  |_________|  |  |_________|  |     EMPTY     |  |_________|  |  |_________|  |\n";
        cout << "\t\t\t|               |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |               |     _[ ]_     |     _[ ]_     |\n";
        cout << "\t\t\t|               |_______________|_______________|_______________|_______________|_______________|_______________|_______________|\n";
        cout << "\t\t\t|               |   _________   |   _________   |   _________   |   _________   |   _________   |   _________   |   _________   |\n";
        cout << "\t\t\t|               |  |C13      |  |  |C12      |  |  |C11      |  |  |C10      |  |  |C9       |  |  |C8       |  |  |C7       |  |\n";
        cout << "\t\t\t|               |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |\n";
        cout << "\t\t\t|               |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |\n";
        cout << "\t\t\t|    EMPTY      |_______________|_______________|_______________|_______________|_______________|_______________|_______________|\n";
        cout << "\t\t\t|     SPACE     |   _________   |   _________   |   _________   |   _________   |   _________   |   _________   |               |\n";
        cout << "\t\t\t|               |  |C19      |  |  |C18      |  |  |C17      |  |  |C16      |  |  |C15      |  |  |C14      |  |    WIFI       |\n";
        cout << "\t\t\t|               |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |     ROUTER    |\n";
        cout << "\t\t\t|               |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |               |\n";
        cout << "\t\t\t|               |_______________|_______________|_______________|_______________|_______________|_______________|_______________|\n";
        cout << "\t\t\t|               |   _________   |   _________   |   _________   |   _________   |   _________   |   _________   |   _________   |\n";
        cout << "\t\t\t|               |  |C26      |  |  |C25      |  |  |C24      |  |  |C23      |  |  |C22      |  |  |C21      |  |  |C20      |  |\n";
        cout << "\t\t\t|               |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |\n";
        cout << "\t\t\t|               |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |\n";
        cout << "\t\t\t|_______________|_______________|_______________|_______________|_______________|_______________|_______________|_______________|\n";
        cout << "\t\t\t|   _________   |   _________   |   _________   |   _________   |   _________   |   _________   |   _________   |   _________   |\n";
        cout << "\t\t\t|  |C34      |  |  |C33      |  |  |C32      |  |  |C31      |  |  |C30      |  |  |C29      |  |  |C28      |  |  |C27      |  |\n";
        cout << "\t\t\t|  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |\n";
        cout << "\t\t\t|     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |\n";
        cout << "\t\t\t|_______________|_______________|_______________|_______________|_______________|_______________|_______________|_______________|\n";
        cout << "\n\n";
        cout << "\t\t\t\t\t\t\t-============-  -===========================-  -==========-\n ";
        cout << "\t\t\t\t\t\t\t| (1) SEARCH |  | (2) DISPLAY ALL COMPUTERS |  | (3) EXIT |\n ";
        cout << "\t\t\t\t\t\t\t-============-  -===========================-  -==========-\n\n ";
        cout << "\t\t\t\t\t\t\t                 Choose an option: ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice! Please enter a number between 1 and 3: ";
            cin >> choice;
        }

        if (choice == 1) {
            int subChoice;
            do {
                system("cls");
                cout << "\n\n\n\n\n\n";
                cout << "\t\t\t\t\t\t\t\t|================================|\n";
                cout << "\t\t\t\t\t\t\t\t|          SUBMENU               |\n";
                cout << "\t\t\t\t\t\t\t\t|================================|\n";
                cout << "\t\t\t\t\t\t\t\t|                                |\n";
                cout << "\t\t\t\t\t\t\t\t| (1) Edit Components            |\n";
                cout << "\t\t\t\t\t\t\t\t| (2) Add Components             |\n"; 
                cout << "\t\t\t\t\t\t\t\t| (3) Delete Components          |\n";
                cout << "\t\t\t\t\t\t\t\t| (4) Display Computer Status    |\n";
                cout << "\t\t\t\t\t\t\t\t| (5) Back to Main Menu          |\n";
                cout << "\t\t\t\t\t\t\t\t|                                |\n";
                cout << "\t\t\t\t\t\t\t\t|================================|\n";
                cout << "\n\n";
                cout << "\t\t\t\t\t\t\t\t Choose an option: ";
                cin >> subChoice;
                system("cls");

                while (cin.fail() || subChoice < 1 || subChoice > 5) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid choice! Please enter a number between 1 and 5: ";
                    cin >> subChoice;
                }

                if (subChoice == 1) {
                    int index;
                    cout << "Enter the number of computer to edit ( 1 - 34 ): ";
                    cin >> index;

                    while (cin.fail() || index < 1 || index >= computerCount) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid index! Please enter a valid index between 1 and " << computerCount - 1 << ": ";
                        cin >> index;
                    }

                    cout << "Editing components for " << computers[index].name << endl;

                    // Edit status without affecting quantities
                    editComponentStatus("System Unit", computers[index].systemUnitStatus);
                    editComponentStatus("Mouse", computers[index].mouseStatus);
                    editComponentStatus("Monitor", computers[index].monitorStatus);
                    editComponentStatus("Power Supply", computers[index].powerSupplyStatus);
                    editComponentStatus("Keyboard", computers[index].keyboardStatus);
                    editComponentStatus("LAN Cable", computers[index].lanCableStatus);

                    cout << "Components updated for " << computers[index].name << endl;
                } else if (subChoice == 2) {
                    int index;
                    cout << "Enter the number of computer to add components to ( 1 - 34 ): ";
                    cin >> index;

                    while (cin.fail() || index < 1 || index >= computerCount) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid index! Please enter a valid index between 1 and " << computerCount - 1 << ": ";
                        cin >> index;
                    }

                    // Add components
                    addComponent("System Unit", computers[index].systemUnitQuantity);
                    addComponent("Mouse", computers[index].mouseQuantity);
                    addComponent("Monitor", computers[index].monitorQuantity);
                    addComponent("Power Supply", computers[index].powerSupplyQuantity);
                    addComponent("Keyboard", computers[index].keyboardQuantity);
                    addComponent("LAN Cable", computers[index].lanCableQuantity);

                    // If a component now has quantity > 0, update status if it was "Not Working"
                    if (computers[index].systemUnitQuantity > 0 && computers[index].systemUnitStatus == "Not Working") {
                        cout << "System Unit now has components. Do you want to mark it as Working? (1 for Yes, 0 for No): ";
                        int choice;
                        cin >> choice;
                        if (choice == 1) computers[index].systemUnitStatus = "Working";
                    }
                    
                    if (computers[index].mouseQuantity > 0 && computers[index].mouseStatus == "Not Working") {
                        cout << "Mouse now has components. Do you want to mark it as Working? (1 for Yes, 0 for No): ";
                        int choice;
                        cin >> choice;
                        if (choice == 1) computers[index].mouseStatus = "Working";
                    }
                    
                    if (computers[index].monitorQuantity > 0 && computers[index].monitorStatus == "Not Working") {
                        cout << "Monitor now has components. Do you want to mark it as Working? (1 for Yes, 0 for No): ";
                        int choice;
                        cin >> choice;
                        if (choice == 1) computers[index].monitorStatus = "Working";
                    }
                    
                    if (computers[index].powerSupplyQuantity > 0 && computers[index].powerSupplyStatus == "Not Working") {
                        cout << "Power Supply now has components. Do you want to mark it as Working? (1 for Yes, 0 for No): ";
                        int choice;
                        cin >> choice;
                        if (choice == 1) computers[index].powerSupplyStatus = "Working";
                    }
                    
                    if (computers[index].keyboardQuantity > 0 && computers[index].keyboardStatus == "Not Working") {
                        cout << "Keyboard now has components. Do you want to mark it as Working? (1 for Yes, 0 for No): ";
                        int choice;
                        cin >> choice;
                        if (choice == 1) computers[index].keyboardStatus = "Working";
                    }
                    
                    if (computers[index].lanCableQuantity > 0 && computers[index].lanCableStatus == "Not Working") {
                        cout << "LAN Cable now has components. Do you want to mark it as Working? (1 for Yes, 0 for No): ";
                        int choice;
                        cin >> choice;
                        if (choice == 1) computers[index].lanCableStatus = "Working";
                    }

                    cout << "Components added for " << computers[index].name << endl;
                } else if (subChoice == 3) {
                    int index;
                    cout << "Enter the number of computer to delete components from ( 1 - 34 ): ";
                    cin >> index;

                    while (cin.fail() || index < 1 || index >= computerCount) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid index! Please enter a valid index between 1 and " << computerCount - 1 << ": ";
                        cin >> index;
                    }

                    // Delete components and update status if quantity becomes 0
                    deleteComponent("System Unit", computers[index].systemUnitQuantity, computers[index].systemUnitStatus);
                    deleteComponent("Mouse", computers[index].mouseQuantity, computers[index].mouseStatus);
                    deleteComponent("Monitor", computers[index].monitorQuantity, computers[index].monitorStatus);
                    deleteComponent("Power Supply", computers[index].powerSupplyQuantity, computers[index].powerSupplyStatus);
                    deleteComponent("Keyboard", computers[index].keyboardQuantity, computers[index].keyboardStatus);
                    deleteComponent("LAN Cable", computers[index].lanCableQuantity, computers[index].lanCableStatus);

                    cout << "Components deleted for " << computers[index].name << endl;
                } else if (subChoice == 4) {
                    system("cls");
                    displayComputers(computers, computerCount);
                    cout << "\nPress any key [ except esc key ] to return.";
                }

                getch();
            } while (subChoice != 5);
        } else if (choice == 2) {
            system("cls");
            displayComputers(computers, computerCount);
            cout << "\nPress any key [ except esc key ] to return.";
            getch();
        }
    } while (choice != 3);

    cout << "Exiting..." << endl;
    return 0;
}
