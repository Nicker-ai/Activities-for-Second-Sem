#include <iostream>
#include <stdlib.h>
#include <conio.h>

// prices
#define units 23
#define APunits 400
#define TuitionF 9200
#define EnergyF 1000
#define UnitL 3600
#define OtherF 4100
#define Misc 850

using namespace std;

int main(){
	int decision,total,subtotal,discount;
	
	main:
	cout<<"\n\nStudents tuition fee computation:\n";
	cout<<"\n\t Mode of payments ( Plan ):";
	cout<<"\n\t     1. Cash  ( 10% discount )";
	cout<<"\n\t     2. Two-Installment  ( 5% discount )";
	cout<<"\n\t     1. Three-Installment  ( 10% Interest )\n";
	decision = getch();
	system("cls");
	
	switch(decision){
		
		case '1':
			cout<<"\n\t Mode of Payment ( Cash )   ";
			cout<<"\n";
			cout<<"\n\t                               Cash    ";
			cout<<"\n\t    Units:                   | "<<units;
			cout<<"\n\t    Amount per unit:         | "<<APunits;
			cout<<"\n\t    Tuition Fee:             | "<<TuitionF;
			cout<<"\n\t    Energy Fee:              | "<<EnergyF;
			cout<<"\n\t    Unit Lab:                | "<<UnitL;
			cout<<"\n\t    Other Fees:              | "<<OtherF;
			cout<<"\n\t    Miscellaneous Fees:      | "<<Misc;
			cout<<"\n\t    ---------------------------------- ";
			subtotal = units + APunits + TuitionF + EnergyF + UnitL + OtherF + Misc;
			cout<<"\n\t    Total:                   | "<<subtotal;
			
			cout<<"\n\n";
			cout<<"\n\t Mode of Payment ( Cash = 10% discount )\n";
			discount = subtotal * 0.1; //Value of discount
			cout<<"\n\t    ---------------------------------- ";
			cout<<"\n\t    Discount Value           | "<<discount;
			cout<<"\n\t    ---------------------------------- ";
			
			cout<<"\n";
			total = subtotal - discount; //Total value subtracted to discount value
			cout<<"\n\t    ---------------------------------- ";
			cout<<"\n\t    Total ( Computed )       | "<<total;
			cout<<"\n\t    ---------------------------------- ";
			
			cout<<"\n\n\t\t>> press key to return to menu <<";
			getch();
			system("cls");
			goto main;
			break;
			
		case '2':
			cout<<"\n\t Mode of Payment ( Installment )   ";
			cout<<"\n";
			cout<<"\n\t                               Cash    ";
			cout<<"\n\t    Units:                   | "<<units;
			cout<<"\n\t    Amount per unit:         | "<<APunits;
			cout<<"\n\t    Tuition Fee:             | "<<TuitionF;
			cout<<"\n\t    Energy Fee:              | "<<EnergyF;
			cout<<"\n\t    Unit Lab:                | "<<UnitL;
			cout<<"\n\t    Other Fees:              | "<<OtherF;
			cout<<"\n\t    Miscellaneous Fees:      | "<<Misc;
			cout<<"\n\t    ---------------------------------- ";
			subtotal = units + APunits + TuitionF + EnergyF + UnitL + OtherF + Misc;
			cout<<"\n\t    Total:                   | "<<subtotal;
			
			cout<<"\n\n";
			cout<<"\n\t Mode of Payment ( Two-Installment = 5% discount )\n";
			discount = subtotal * 0.05; //Value of discount
			cout<<"\n\t    ---------------------------------- ";
			cout<<"\n\t    Discount Value           | "<<discount;
			cout<<"\n\t    ---------------------------------- ";
			
			cout<<"\n";
			total = subtotal - discount; //Total value subtracted to discount value
			cout<<"\n\t    ---------------------------------- ";
			cout<<"\n\t    Total ( Computed )       | "<<total;
			cout<<"\n\t    ---------------------------------- ";
			
			cout<<"\n\n\t\t>> press key to return to menu <<";
			getch();
			system("cls");
			goto main;
			break;
			
		case '3':
			cout<<"\n\t Mode of Payment ( Installment )   ";
			cout<<"\n";
			cout<<"\n\t                               Cash    ";
			cout<<"\n\t    Units:                   | "<<units;
			cout<<"\n\t    Amount per unit:         | "<<APunits;
			cout<<"\n\t    Tuition Fee:             | "<<TuitionF;
			cout<<"\n\t    Energy Fee:              | "<<EnergyF;
			cout<<"\n\t    Unit Lab:                | "<<UnitL;
			cout<<"\n\t    Other Fees:              | "<<OtherF;
			cout<<"\n\t    Miscellaneous Fees:      | "<<Misc;
			cout<<"\n\t    ---------------------------------- ";
			subtotal = units + APunits + TuitionF + EnergyF + UnitL + OtherF + Misc;
			cout<<"\n\t    Total:                   | "<<subtotal;
			
			cout<<"\n\n";
			cout<<"\n\t Mode of Payment ( Three-Installment = 10% Interest )\n";
			discount = subtotal * 0.1; //Value of discount
			cout<<"\n\t    ---------------------------------- ";
			cout<<"\n\t    Discount Value           | "<<discount;
			cout<<"\n\t    ---------------------------------- ";
			
			cout<<"\n";
			total = subtotal + discount; //Total value subtracted to discount value
			cout<<"\n\t    ---------------------------------- ";
			cout<<"\n\t    Total ( Computed )       | "<<total;
			cout<<"\n\t    ---------------------------------- ";
			
			cout<<"\n\n\t\t>> press key to return to menu <<";
			getch();
			system("cls");
			goto main;
			break;
			
		default:
			cout<<"Invalid input! Please select from the choices below.";
			goto main;
			break;
			
			
			
			
		
	}
	return 0;
}
