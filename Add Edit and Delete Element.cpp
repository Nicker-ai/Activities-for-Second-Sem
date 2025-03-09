#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX_ELEMENTS = 101; 

int main() {
    string elements[MAX_ELEMENTS];
    int size = 1;
    int choice;

    do {
    	cout << "\n\n";
    	cout << "\t\t\t\t\t|=========================================|\n";
    	cout << "\t\t\t\t\t|=========================================|\n\n";
        cout << "\t\t\t\t\t      Menu:\n";
        cout << "\t\t\t\t\t          1. Add Element\n";
        cout << "\t\t\t\t\t          2. Edit Element\n";
        cout << "\t\t\t\t\t          3. Delete Element\n";
        cout << "\t\t\t\t\t          4. Display Elements\n";
        cout << "\t\t\t\t\t          5. Exit\n";
        cout << "\t\t\t\t\t          Choose an option: ";
        
        cin >> choice;


        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            cout << "\t\t\t\t\t>> Invalid input. Please enter a number. <<\n";
            continue;
        }

        system("cls");

        if (choice == 1) { 
            if (size < MAX_ELEMENTS) {
            	cout << "\n\n\n\n";
                cout << "\t\t\t\t\t       Enter the element to add:\n\n";
                cout << "\t\t\t\t\t           >>: ";
                cin >> elements[size];
                size++;
                system("cls");
                cout << "\t\t\t\t\t            >> Element added. <<\n";
            } else {
                system("cls");
                cout << "\t\t\t\t\t Elements is full. Please remove other elements.\n";
            }
        } else if (choice == 2) { 
            int index;
            cout << "Enter the index of the element to edit (1 to " << size - 1 << "): ";
            cin >> index;
            if (index >= 1 && index < size) {
            	cout << "\n\n\n\n";
                cout << "cout << \t\t\t\t\t       Enter the new value: ";
                cin >> elements[index];
                system("cls");
                cout << "\t\t\t\t\t            >> Element updated. <<\n";
            } else {
                system("cls");
                cout << "\t\t\t\t\t            >> Invalid index. <<\n";
            }
        } else if (choice == 3) { 
            int index;
            cout << "\n\n\n";
            cout << "Elements:\n";
            for (int i = 1; i < size; i++) {
            	cout << "\t\t\t------------------------------------------\n";
                cout << "\t\t\t[" << i << "]" << ": " << elements[i] << "\n";
            }
            cout << "Enter the index of the element to delete (1 to " << size - 1 << "): ";
            cin >> index;
            if (index >= 1 && index < size) {
                for (int i = index; i < size - 1; i++) {
                    elements[i] = elements[i + 1];
                }
                size--; 
                system("cls");
                cout << "Element deleted.\n";
            } else {
                system("cls");
                cout << "Invalid index.\n";
            }
        } else if (choice == 4) { 
        	cout << "Elements:\n";
            for (int i = 1; i < size; i++) {
            	cout << "\t\t\t------------------------------------------\n";
                cout << "\t\t\t[" << i << "]" << ": " << elements[i] << "\n";
            }
        } else if (choice != 5) { 
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    cout << "Exiting...\n";
    return 0;
}
