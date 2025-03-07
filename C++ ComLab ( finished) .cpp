#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include <cstdlib>

using namespace std;

const int MAX_COMPUTERS = 50; // Maximum number of computers

struct Computer {
    string name;
    int unitQuantity;          // Quantity of units
    string unitStatus;        // Status of unit
    int mouseQuantity;         // Quantity of mice
    string mouseStatus;       // Status of mouse
    int monitorQuantity;       // Quantity of monitors
    string monitorStatus;     // Status of monitor
    int powerSupplyQuantity;   // Quantity of power supplies
    string powerSupplyStatus;  // Status of power supply
    int keyboardQuantity;      // Quantity of keyboards
    string keyboardStatus;     // Status of keyboard
    int lanQuantity;           // Quantity of LAN components
    string lanStatus;         // Status of LAN component

    // Function to determine if the computer is working
    string getStatus() {
        // Check if any component is not working
        if (unitQuantity == 0 || mouseQuantity == 0 || monitorQuantity == 0 ||
            powerSupplyQuantity == 0 || keyboardQuantity == 0 || lanQuantity == 0) {
            return "Not Working"; // Mark as "Not Working" if any component is missing
        }
        return "Working"; // All components are present
    }

    // Function to update status based on quantity
    void updateComponentStatus() {
        unitStatus = (unitQuantity > 0) ? "Working" : "Not Working";
        mouseStatus = (mouseQuantity > 0) ? "Working" : "Not Working";
        monitorStatus = (monitorQuantity > 0) ? "Working" : "Not Working";
        powerSupplyStatus = (powerSupplyQuantity > 0) ? "Working" : "Not Working";
        keyboardStatus = (keyboardQuantity > 0) ? "Working" : "Not Working";
        lanStatus = (lanQuantity > 0) ? "Working" : "Not Working";
    }
};

// Function to convert integer to string
string intToString(int number) {
    stringstream ss;
    ss << number;
    return ss.str();
}

void displayComputers(Computer computers[], int computerCount) {
    for (int i = 0; i < computerCount; i++) {
        cout << "\n==========================================================\n";
        cout << "------------------------------\n";
        cout << i << ": " << computers[i].name << " - " << computers[i].getStatus() << endl;
        cout << "------------------------------\n";
        cout << "  Unit Quantity          [ " << computers[i].unitQuantity << " ] Status: " << computers[i].unitStatus << endl;
        cout << "  Mouse Quantity         [ " << computers[i].mouseQuantity << " ] Status: " << computers[i].mouseStatus << endl;
        cout << "  Monitor Quantity       [ " << computers[i].monitorQuantity << " ] Status: " << computers[i].monitorStatus << endl;
        cout << "  Power Supply Quantity  [ " << computers[i].powerSupplyQuantity << " ] Status: " << computers[i].powerSupplyStatus << endl;
        cout << "  Keyboard Quantity      [ " << computers[i].keyboardQuantity << " ] Status: " << computers[i].keyboardStatus << endl;
        cout << "  LAN Quantity           [ " << computers[i].lanQuantity << " ] Status: " << computers[i].lanStatus << endl;
        cout << "\n==========================================================\n";
    }
}

int main() {
    // Initialize the inventory with 34 pre-filled computers
    Computer computers[MAX_COMPUTERS];
    for (int i = 0; i < 34; i++) {
        computers[i].name = "C" + intToString(i + 1); // Set names to C1, C2, ...
        computers[i].unitQuantity = 1;
        computers[i].unitStatus = "Working";
        computers[i].mouseQuantity = 1;
        computers[i].mouseStatus = "Working";
        computers[i].monitorQuantity = 1;
        computers[i].monitorStatus = "Working";
        computers[i].powerSupplyQuantity = 1;
        computers[i].powerSupplyStatus = "Working";
        computers[i].keyboardQuantity = 1;
        computers[i].keyboardStatus = "Working";
        computers[i].lanQuantity = 1;
        computers[i].lanStatus = "Working";
    }

    int computerCount = 34; // Start with 34 pre-filled computers
    int choice;

    do {
        system("cls"); // Clear the console
        // Display the interface
        cout<<"\t\t\t _______________________________________________________________________________________________________________________________\n";
		cout<<"\t\t\t|               |   _________   |   _________   |   _________   |   _________   |               |   _________   |   _________   |\n";
		cout<<"\t\t\t|               |  |C6       |  |  |C5       |  |  |C4       |  |  |C3       |  |               |  |C2       |  |  |C1       |  |\n";
		cout<<"\t\t\t|               |  |_________|  |  |_________|  |  |_________|  |  |_________|  |     EMPTY     |  |_________|  |  |_________|  |\n";
		cout<<"\t\t\t|               |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |               |     _[ ]_     |     _[ ]_     |\n";
		cout<<"\t\t\t|               |_______________|_______________|_______________|_______________|_______________|_______________|_______________|\n";
		cout<<"\t\t\t|               |   _________   |   _________   |   _________   |   _________   |   _________   |   _________   |   _________   |\n";
		cout<<"\t\t\t|               |  |C13      |  |  |C12      |  |  |C11      |  |  |C10      |  |  |C9       |  |  |C8       |  |  |C7       |  |\n";
		cout<<"\t\t\t|               |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |\n";
		cout<<"\t\t\t|               |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |\n";
		cout<<"\t\t\t|    EMPTY      |_______________|_______________|_______________|_______________|_______________|_______________|_______________|\n";
		cout<<"\t\t\t|     SPACE     |   _________   |   _________   |   _________   |   _________   |   _________   |   _________   |               |\n";
		cout<<"\t\t\t|               |  |C19      |  |  |C18      |  |  |C17      |  |  |C16      |  |  |C15      |  |  |C14      |  |    WIFI       |\n";
		cout<<"\t\t\t|               |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |     ROUTER    |\n";
		cout<<"\t\t\t|               |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |               |\n";
		cout<<"\t\t\t|               |_______________|_______________|_______________|_______________|_______________|_______________|_______________|\n";
		cout<<"\t\t\t|               |   _________   |   _________   |   _________   |   _________   |   _________   |   _________   |   _________   |\n";
		cout<<"\t\t\t|               |  |C26      |  |  |C25      |  |  |C24      |  |  |C23      |  |  |C22      |  |  |C21      |  |  |C20      |  |\n";
		cout<<"\t\t\t|               |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |\n";
		cout<<"\t\t\t|               |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |\n";
		cout<<"\t\t\t|_______________|_______________|_______________|_______________|_______________|_______________|_______________|_______________|\n";
		cout<<"\t\t\t|   _________   |   _________   |   _________   |   _________   |   _________   |   _________   |   _________   |   _________   |\n";
		cout<<"\t\t\t|  |C34      |  |  |C33      |  |  |C32      |  |  |C31      |  |  |C30      |  |  |C29      |  |  |C28      |  |  |C27      |  |\n";
		cout<<"\t\t\t|  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |  |_________|  |\n";
		cout<<"\t\t\t|     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |     _[ ]_     |\n";
		cout<<"\t\t\t|_______________|_______________|_______________|_______________|_______________|_______________|_______________|_______________|\n";
		cout<<"\n\n";
        cout << "\t\t\t\t\t\t\t-============-  -===========================-  -==========-\n ";
        cout << "\t\t\t\t\t\t\t| (1) SEARCH |  | (2) DISPLAY ALL COMPUTERS |  | (3) EXIT |\n ";
        cout << "\t\t\t\t\t\t\t-============-  -===========================-  -==========-\n\n ";
		cout << "\t\t\t\t\t\t\t                 Choose an option: ";
        cin >> choice;

        // Simple error handling for menu choice
        while (cin.fail() || choice < 1 || choice > 3) {
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Discard invalid input
            cout << "Invalid choice! Please enter a number between 1 and 3: ";
            cin >> choice;
        }

        if (choice == 1) {
            int subChoice, statusInput;
            do {
                system("cls"); // Clear the console
                cout << "\n\n\n\n\n\n";
                cout << "\t\t\t\t\t\t\t\t-=========================-\n";
    			cout << "\t\t\t\t\t\t\t\t|   SUBMENU               |\n";
    			cout << "\t\t\t\t\t\t\t\t-=========================-\n";
    			cout << "\t\t\t\t\t\t\t\t|                         |\n";
    			cout << "\t\t\t\t\t\t\t\t| (1) Add Computer        |\n";
    			cout << "\t\t\t\t\t\t\t\t| (2) Edit Computer       |\n";
  				cout << "\t\t\t\t\t\t\t\t| (3) Delete Computer     |\n";
    			cout << "\t\t\t\t\t\t\t\t| (4) Display Computers   |\n";
    			cout << "\t\t\t\t\t\t\t\t| (5) Back to Main Menu   |\n";
    			cout << "\t\t\t\t\t\t\t\t|                         |\n";
    			cout << "\t\t\t\t\t\t\t\t-=========================-\n";
    			cout << "\n\n";
    			cout << "\t\t\t\t\t\t\t\t Choose an option: ";
                cin >> subChoice;
                system("cls");

                // Simple error handling for submenu choice
                while (cin.fail() || subChoice < 1 || subChoice > 5) {
                    cin.clear(); // Clear the error flag
                    cin.ignore(10000, '\n'); // Discard invalid input
                    cout << "Invalid choice! Please enter a number between 1 and 5: ";
                    cin >> subChoice;
                }

                if (subChoice == 1) {
                    if (computerCount < MAX_COMPUTERS) {
                        cout << "Enter name for the new computer (e.g., C35): ";
                        cin >> computers[computerCount].name;

                        // Initialize component quantities to 1 and status to "Working"
                        computers[computerCount].unitQuantity = 1;
                        computers[computerCount].unitStatus = "Working";
                        computers[computerCount].mouseQuantity = 1;
                        computers[computerCount].mouseStatus = "Working";
                        computers[computerCount].monitorQuantity = 1;
                        computers[computerCount].monitorStatus = "Working";
                        computers[computerCount].powerSupplyQuantity = 1;
                        computers[computerCount].powerSupplyStatus = "Working";
                        computers[computerCount].keyboardQuantity = 1;
                        computers[computerCount].keyboardStatus = "Working";
                        computers[computerCount].lanQuantity = 1;
                        computers[computerCount].lanStatus = "Working";

                        computerCount++;
                        cout << "New computer added: " << computers[computerCount - 1].name << endl;
                    } else {
                        cout << "Inventory is full! Cannot add more computers." << endl;
                    }
                } else if (subChoice == 2) {
                    int index;
                    cout << "Enter index of the computer to edit: ";
                    cin >> index;

                    // Simple error handling for index
                    while (cin.fail() || index < 0 || index >= computerCount) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid index! Please enter a valid index between 0 and " << computerCount - 1 << ": ";
                        cin >> index;
                    }

                    cout << "Editing components for " << computers[index].name << endl;

                    // Input for component quantities
                    cout << "Enter Unit Quantity (0 or 1): ";
                    cin >> computers[index].unitQuantity;
                    while (cin.fail() || (computers[index].unitQuantity != 0 && computers[index].unitQuantity != 1)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input! Please enter 0 or 1 for Unit Quantity: ";
                        cin >> computers[index].unitQuantity;
                    }

                    // Only ask for status if quantity is greater than 0
                    if (computers[index].unitQuantity > 0) {
                        int statusInput; // Declare statusInput here
                        cout << "Enter Unit Status (1 for Working, 0 for Not Working): ";
                        cin >> statusInput;
                        while (cin.fail() || (statusInput != 0 && statusInput != 1)) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cout << "Invalid input! Please enter 1 for Working or 0 for Not Working: ";
                            cin >> statusInput;
                        }
                        computers[index].unitStatus = (statusInput == 1) ? "Working" : "Not Working";
                    }

                    // Repeat for other components (mouse, monitor, power supply, keyboard, LAN)
                    cout << "Enter Mouse Quantity (0 or 1): ";
                    cin >> computers[index].mouseQuantity;
                    while (cin.fail() || (computers[index].mouseQuantity != 0 && computers[index].mouseQuantity != 1)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input! Please enter 0 or 1 for Mouse Quantity: ";
                        cin >> computers[index].mouseQuantity;
                    }
                    if (computers[index].mouseQuantity > 0) {
                        cout << "Enter Mouse Status (1 for Working, 0 for Not Working): ";
                        cin >> statusInput;
                        while (cin.fail() || (statusInput != 0 && statusInput != 1)) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cout << "Invalid input! Please enter 1 for Working or 0 for Not Working: ";
                            cin >> statusInput;
                        }
                        computers[index].mouseStatus = (statusInput == 1) ? "Working" : "Not Working";
                    }

                    cout << "Enter Monitor Quantity (0 or 1): ";
                    cin >> computers[index].monitorQuantity;
                    while (cin.fail() || (computers[index].monitorQuantity != 0 && computers[index].monitorQuantity != 1)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input! Please enter 0 or 1 for Monitor Quantity: ";
                        cin >> computers[index].monitorQuantity;
                    }
                    if (computers[index].monitorQuantity > 0) {
                        cout << "Enter Monitor Status (1 for Working, 0 for Not Working): ";
                        cin >> statusInput;
                        while (cin.fail() || (statusInput != 0 && statusInput != 1)) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cout << "Invalid input! Please enter 1 for Working or 0 for Not Working: ";
                            cin >> statusInput;
                        }
                        computers[index].monitorStatus = (statusInput == 1) ? "Working" : "Not Working";
                    }

                    cout << "Enter Power Supply Quantity (0 or 1): ";
                    cin >> computers[index].powerSupplyQuantity;
                    while (cin.fail() || (computers[index].powerSupplyQuantity != 0 && computers[index].powerSupplyQuantity != 1)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input! Please enter 0 or 1 for Power Supply Quantity: ";
                        cin >> computers[index].powerSupplyQuantity;
                    }
                    if (computers[index].powerSupplyQuantity > 0) {
                        cout << "Enter Power Supply Status (1 for Working, 0 for Not Working): ";
                        cin >> statusInput;
                        while (cin.fail() || (statusInput != 0 && statusInput != 1)) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cout << "Invalid input! Please enter 1 for Working or 0 for Not Working: ";
                            cin >> statusInput;
                        }
                        computers[index].powerSupplyStatus = (statusInput == 1) ? "Working" : "Not Working";
                    }

                    cout << "Enter Keyboard Quantity (0 or 1): ";
                    cin >> computers[index].keyboardQuantity;
                    while (cin.fail() || (computers[index].keyboardQuantity != 0 && computers[index].keyboardQuantity != 1)) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid input! Please enter 0 or 1 for Keyboard Quantity: ";
                        cin >> computers[index].keyboardQuantity;
                    }
                    if (computers[index].keyboardQuantity > 0) {
                        cout << "Enter Keyboard Status (1 for Working, 0 for Not Working): ";
                        cin >> statusInput;
                        while (cin.fail() || (statusInput != 0 && statusInput != 1)) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cout << "Invalid input! Please enter 1 for Working or 0 for Not Working: ";
                            cin >> statusInput;
                        }
                        computers[index].keyboardStatus = (statusInput == 1) ? "Working" : "Not Working";
                    }

                    cout << "Enter LAN Quantity (0 or 1): ";
                    cin >> computers[index].lanQuantity;
                    while (cin.fail() || (computers[index].lanQuantity != 0 && computers[index].lanQuantity != 1)) {
                        cin.clear();
                        cin.ignore(10000,                        '\n');
                        cout << "Invalid input! Please enter 0 or 1 for LAN Quantity: ";
                        cin >> computers[index].lanQuantity;
                    }
                    if (computers[index].lanQuantity > 0) {
                        cout << "Enter LAN Status (1 for Working, 0 for Not Working): ";
                        cin >> statusInput;
                        while (cin.fail() || (statusInput != 0 && statusInput != 1)) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cout << "Invalid input! Please enter 1 for Working or 0 for Not Working: ";
                            cin >> statusInput;
                        }
                        computers[index].lanStatus = (statusInput == 1) ? "Working" : "Not Working";
                    }

                    // Update the overall status of the computer
                    computers[index].updateComponentStatus();

                    cout << "Components updated for " << computers[index].name << endl;
                } else if (subChoice == 3) {
                    int index;
                    cout << "Enter index to delete: ";
                    cin >> index;

                    // Simple error handling for index
                    while (cin.fail() || index < 0 || index >= computerCount) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid index! Please enter a valid index between 0 and " << computerCount - 1 << ": ";
                        cin >> index;
                    }

                    for (int i = index; i < computerCount - 1; i++) {
                        computers[i] = computers[i + 1]; // Shift left
                    }
                    computerCount--;
                    cout << "Deleted computer." << endl;
                } else if (subChoice == 4) {
                    displayComputers(computers, computerCount);
                }

                getch(); // Wait for a key press before returning to the submenu
            } while (subChoice != 5);
        } else if (choice == 2) {
        	system("cls");
            displayComputers(computers, computerCount);
            getch(); // Wait for a key press before returning to the main menu
        }
    } while (choice != 3); // Exit option in the main menu

    cout << "Exiting..." << endl;
    return 0;
}
