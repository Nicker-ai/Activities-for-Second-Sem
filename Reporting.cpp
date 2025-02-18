#include <iostream>
#include <stdlib.h>

// cash payment
#define C_units 23
#define C_APunits 400
#define C_TuitionF 9200
#define C_EnergyF 1000
#define C_UnitL 3600
#define C_OtherF 4100
#define C_Misc 850

using namespace std;

int main(){
	int decision;
	
	cout<<"\n\nStudents tuition fee computation:\n";
	cout<<"\n\t Mode of payments ( Plan ):";
	cout<<"\n\t     1. Cash  ( 10% discount )";
	cout<<"\n\t     2. Two-Installment  ( 5% discount )";
	cout<<"\n\t     1. Three-Installment  ( 10% Interest )\n";
	cout<<"\n\t Decision: ";
	cin>>decision;
	system("cls");
	
	switch(decision){
		case 1:
			cout<<"\n\t Mode of Payment ( Cash )   ";
			cout<<"\n";
			cout<<"\n\t                               Cash    ";
			cout<<"\n\t    Units:                   | "<<C_units;
			cout<<"\n\t    Amount per unit:         | "<<C_APunits;
			cout<<"\n\t    Tuition Fee:             | "<<C_TuitionF;
			cout<<"\n\t    Energy Fee:              | "<<C_EnergyF;
			cout<<"\n\t    Unit Lab:                | "<<C_UnitL;
			cout<<"\n\t    Other Fees:              | "<<C_OtherF;
			cout<<"\n\t    Miscellaneous Fees:      | "<<C_Misc;
			cout<<"\n\t    ---------------------------------- ";
			int subtotal = C_units + C_APunits + C_TuitionF + C_EnergyF + C_UnitL + C_OtherF + C_Misc;
			cout<<"\n\t    Total:                   | "<<subtotal;
			
			cout<<"\n\n";
			cout<<"\n\t Mode of Payment ( Cash = 10% discount )\n";
			int discount = subtotal * 0.10; //Value of discount
			cout<<"\n\t    Discount Value           | "<<discount;
			
			cout<<"\n";
			int total = subtotal - discount; //Total value subtracted to discount value
			cout<<"\n\t    Total ( Computed )       | "<<total;
			
			break;
	}
	return 0;
}
