#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For std::setw
#include <algorithm> // For std::sort

using namespace std;

struct InventoryItem {
    string name;
    string type; // "computer", "external component", "equipment"
    int row;     // Row number
    int column;  // Column number

    // Constructor to initialize InventoryItem
    InventoryItem(string n, string t, int r, int c) {
        name = n;
        type = t;
        row = r;
        column = c;
    }
};

// Comparison function for sorting
bool compareItems(const InventoryItem& a, const InventoryItem& b) {
    if (a.row != b.row) {
        return a.row < b.row;
    }
    return a.column < b.column;
}

class InventorySystem {
private:
    vector<InventoryItem> items;

public:
    void addItem(const string& name, const string& type, int row, int column) {
        InventoryItem newItem(name, type, row, column);
        items.push_back(newItem);
        cout << "Item added successfully.\n";
    }

    void editItem(int index, const string& name, const string& type, int row, int column) {
        if (index < 0 || index >= items.size()) {
            cout << "Invalid index.\n";
            return;
        }
        items[index] = InventoryItem(name, type, row, column);
        cout << "Item updated successfully.\n";
    }

    void deleteItem(int index) {
        if (index < 0 || index >= items.size()) {
            cout << "Invalid index.\n";
            return;
        }
        items.erase(items.begin() + index);
        cout << "Item deleted successfully.\n";
    }

    void searchItem(const string& name) {
        bool found = false;
        for (size_t i = 0; i < items.size(); ++i) {
            if (items[i].name == name) {
                cout << "Found: " << items[i].name << ", Type: " << items[i].type 
                     << ", Row: " << items[i].row << ", Column: " << items[i].column << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "Item not found.\n";
        }
    }

    void displayItems() {
        if (items.empty()) {
            cout << "No items in inventory.\n";
            return;
        }

        // Sort items by row and then by column using the comparison function
        sort(items.begin(), items.end(), compareItems);

        // Display header
        cout << left << setw(5) << "Index" 
             << setw(30) << "Name" 
             << setw(25) << "Type" 
             << setw(10) << "Row" 
             << setw(10) << "Column" << endl;
        cout << string(90, '-') << endl; // Separator line

        // Display each item in a grid format with dividers
        int currentRow = -1;
        int currentColumn = -1;
        for (size_t i = 0; i < items.size(); ++i) {
            // Check if we need to print a separator line
            if (items[i].row != currentRow || items[i].column != currentColumn) {
                if (currentRow != -1 || currentColumn != -1) {
                    cout << string(90, '-') << endl; // Divider line for different rows/columns
                }
                currentRow = items[i].row;
                currentColumn = items[i].column;
            }
            cout << left << setw(5) << i 
                 << setw(30) << items[i].name 
                 << setw(25) << items[i].type 
                 << setw(10) << items[i].row 
                 << setw(10) << items[i].column << endl;
        }
    }
};

int main() {
    InventorySystem inventory;
    int choice;
    string name, type;
    int row, column, index;

    do {
        cout << "\nComputer Laboratory Inventory System\n";
        cout << "1. Add Item\n";
        cout << "2. Edit Item\n";
        cout << "3. Delete Item\n";
        cout << "4. Search Item\n";
        cout << "5. Display All Items\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input buffer

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                getline(cin, name);
                cout << "Enter item type (computer/external component/equipment): ";
                getline(cin, type);
                cout << "Enter row number: ";
                cin >> row;
                cout << "Enter column number: ";
                cin >> column;
                inventory.addItem(name, type, row, column);
                break;

            case 2:
                inventory.displayItems();
                cout << "Enter index of item to edit: ";
                cin >> index;
                cin.ignore(); // Clear the newline character from the input buffer
                cout << "Enter new item name: ";
                getline(cin, name);
                cout << "Enter new item type (computer/external component/equipment): ";
                getline(cin, type);
                cout << "Enter new row number: ";
                cin >> row;
                cout << "Enter new column number: ";
                cin >> column;
                inventory.editItem(index, name, type, row, column);
                break;

            case 3:
                inventory.displayItems();
                cout << "Enter index of item to delete: ";
                cin >> index;
                inventory.deleteItem(index);
                break;

            case 4:
                cout << "Enter item name to search: ";
                cin.ignore(); // Clear the newline character from the input buffer
                getline(cin, name);
                inventory.searchItem(name);
                break;

            case 5:
                inventory.displayItems();
                break;

            case 6:
                cout << "Exiting the system.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
