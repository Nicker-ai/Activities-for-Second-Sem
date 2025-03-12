#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main(){
	
	float units, APunit, tuitionfee, energyfee, unitlab, otherfees, misc, additional,additionalpercentage,additionalamount,subtotal,total;
	int choice,mode,operation;
	
	
	
	main:
		cout << "\n\n\tStudents tuition fee computation:\n";
		cout << "\n\tWhat will be the mode of payment of student in enrollment:";
		cout << "\n\t1. Cash";
		cout << "\n\t2. Installment\n";
		cout << "\n\tchoice: ";
		cin >> choice;
		
		system("cls");
		
		cout << "\n\n";
		cout << "\n\tEnter the amount of units: ";
		cin >> units;
		cout << "\n\tEnter the Amount per unit: ";
		cin >> APunit;
		cout << "\n\tEnter the amount of Tuition fee: ";
		cin >> tuitionfee;
		cout << "\n\tEnter the amount of Energy fee: ";
		cin >> energyfee;
		cout << "\n\tEnter the amount of Unit Lab: ";
		cin >> unitlab;
		cout << "\n\tEnter the amount of Other fees: ";
		cin >> otherfees;
		cout << "\n\tEnter the amount of Miscellaneous Fees: ";
		cin >> misc;
		
		subtotal = units + APunit + tuitionfee + energyfee + unitlab + otherfees + misc;
		
		system("cls");
		
		cout << "\n\n\n";
		cout << "\n\t                               Cash    ";
		cout << "\n\t    Units:                   | " << units;
		cout << "\n\t    Amount per unit:         | " << APunit;
		cout << "\n\t    Tuition Fee:             | " << tuitionfee;
		cout << "\n\t    Energy Fee:              | " << energyfee;
		cout << "\n\t    Unit Lab:                | " << unitlab;
		cout << "\n\t    Other Fees:              | " << otherfees;
		cout << "\n\t    Miscellaneous Fees:      | " << misc;
		cout << "\n\t    -----------------------------------------------------";
		cout << "\n\t    total tuition:           | " << subtotal;
		
		if (choice == 2){
			
			cout << "\n\n\t    Enter the percentage of additional value: ";
			cin >> additional;
		
			additionalpercentage = additional / 100;
		
			cout << "\n\n\t    Choose the corresponding addition to tuition";
			cout << "\n\t    1. Discount [ deduction to tuition ]";
			cout << "\n\t    2. Interest [ addition to tuition ]";
			cout << "\n\t    choice: ";
			cin >> mode;
			
			if (mode == 1){
				additionalamount = subtotal * additionalpercentage;
				total = subtotal - additionalamount;
			} else if (mode == 2){
				additionalamount = subtotal * additionalpercentage;
				total = subtotal + additionalamount;
			}
			system("cls");
			cout << "\n\t    Full preview: ";
			cout << "\n\n\n";
			cout << "\n\t                                           Cash:    ";
			cout << "\n\t    Units:                                | " << units;
			cout << "\n\t    Amount per unit:                      | " << APunit;
			cout << "\n\t    Tuition Fee:                          | " << tuitionfee;
			cout << "\n\t    Energy Fee:                           | " << energyfee;
			cout << "\n\t    Unit Lab:                             | " << unitlab;
			cout << "\n\t    Other Fees:                           | " << otherfees;
			cout << "\n\t    Miscellaneous Fees:                   | " << misc;
			cout << "\n\t    -----------------------------------------------------";
			cout << "\n\t    total tuition:                        | " << subtotal;
			cout << "\n\t    -----------------------------------------------------";
			cout << "\n\t    Additional percentage:                | " << additional;
			cout << "\n\t    -----------------------------------------------------";
			cout << "\n\t    Addition/Deduction amount:            | " << additionalamount;
			cout << "\n\t    -----------------------------------------------------";
			cout << "\n\t    total tuition ( Additional applied ): | " << total;
			
		}
		
		cout<<"\n\n\t\t>> press a key to return to menu <<";
		getch();
		system("cls");
		goto main;
		
}
