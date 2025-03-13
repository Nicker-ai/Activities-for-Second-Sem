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
        if (systemUnitQuantity == 0 || mouseQuantity == 0 || monitorQuantity == 0 ||
            powerSupplyQuantity == 0 || keyboardQuantity == 0 || lanCableQuantity == 0) {
            return "Not Working";
        }
        return "Working";
    }

    void updateComponentStatus() {
        systemUnitStatus = (systemUnitQuantity > 0) ? "Working" : "Not Working";
        mouseStatus = (mouseQuantity > 0) ? "Working" : "Not Working";
        monitorStatus = (monitorQuantity > 0) ? "Working" : "Not Working";
        powerSupplyStatus = (powerSupplyQuantity > 0) ? "Working" : "Not Working";
        keyboardStatus = (keyboardQuantity > 0) ? "Working" : "Not Working";
        lanCableStatus = (lanCableQuantity > 0) ? "Working" : "Not Working";
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
        cout << "  System Unit Status     : " << computers[i].systemUnitStatus << endl;
        cout << "  Mouse Status           : " << computers[i].mouseStatus << endl;
        cout << "  Monitor Status         : " << computers[i].monitorStatus << endl;
        cout << "  Power Supply Status    : " << computers[i].powerSupplyStatus << endl;
        cout << "  Keyboard Status        : " << computers[i].keyboardStatus << endl;
        cout << "  LAN Cable Status       : " << computers[i].lanCableStatus << endl;
        cout << "\n==========================================================\n";
    }
}

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

int main() {
    Computer computers[MAX_COMPUTERS];
    for (int i = 1; i < 35; i++) {
        computers[i].name = "C" + intToString(i);
        computers[i].systemUnitQuantity = 1;
        computers[i].mouseQuantity = 1;
        computers[i].monitorQuantity = 1;
        computers[i].powerSupplyQuantity = 1;
        computers[i].keyboardQuantity = 1;
        computers[i].lanCableQuantity = 1;
        computers[i].updateComponentStatus();
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
                cout << "\t\t\t\t\t\t\t\t| (2) Display Computer Status    |\n";
                cout << "\t\t\t\t\t\t\t\t| (3) Back to Main Menu          |\n";
                cout << "\t\t\t\t\t\t\t\t|                                |\n";
                cout << "\t\t\t\t\t\t\t\t|================================|\n";
                cout << "\n\n";
                cout << "\t\t\t\t\t\t\t\t Choose an option: ";
                cin >> subChoice;
                system("cls");

                while (cin.fail() || subChoice < 1 || subChoice > 3) {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Invalid choice! Please enter a number between 1 and 3: ";
                    cin >> subChoice;
                }

                if (subChoice == 1) {
                    int index;
                    cout << "Enter the number of computer to edit ( 1 - 34 ): ";
                    cin >> index;

                    while (cin.fail() || index < 0 || index >= computerCount) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid index! Please enter a valid index between 0 and " << computerCount - 1 << ": ";
                        cin >> index;
                    }

                    cout << "Editing components for " << computers[index].name << endl;

                    editComponentStatus("System Unit", computers[index].systemUnitStatus);
                    editComponentStatus("Mouse", computers[index].mouseStatus);
                    editComponentStatus("Monitor", computers[index].monitorStatus);
                    editComponentStatus("Power Supply", computers[index].powerSupplyStatus);
                    editComponentStatus("Keyboard", computers[index].keyboardStatus);
                    editComponentStatus("LAN Cable", computers[index].lanCableStatus);

                    computers[index].systemUnitQuantity = (computers[index].systemUnitStatus == "Working") ? 1 : 0;
                    computers[index].mouseQuantity = (computers[index].mouseStatus == "Working") ? 1 : 0;
                    computers[index].monitorQuantity = (computers[index].monitorStatus == "Working") ? 1 : 0;
                    computers[index].powerSupplyQuantity = (computers[index].powerSupplyStatus == "Working") ? 1 : 0;
                    computers[index].keyboardQuantity = (computers[index].keyboardStatus == "Working") ? 1 : 0;
                    computers[index].lanCableQuantity = (computers[index].lanCableStatus == "Working") ? 1 : 0;

                    computers[index].updateComponentStatus();

                    cout << "Components updated for " << computers[index].name << endl;
                } else if (subChoice == 2) {
                    system("cls");
                    displayComputers(computers, computerCount);
                    cout << "\nPress any key [ except esc key ] to return.";
                }

                getch();
            } while (subChoice != 3);
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
