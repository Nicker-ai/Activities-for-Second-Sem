#include <iostream>

using namespace std;

int main(){
	
	cout << "\t\t\t\tCENTIMETER TO MILLIMETER TO METER CONVERSION CALCULATOR ";
	
	 while (true) {
		
		float cm,mm,m;
		
		cout << "\n\n\n";
		cout << "\t\t ============================================================\n";
		cout << "\t\t  Enter the value you that you want to convert: ";
		cin >> cm;
		
			if (cin.fail()){
				cout << "\n\t\t  Error, Letters or any other special characters cannot be converted :( \n";
				cout << "\t\t ============================================================\n";
				break;
			} else if (cm <= -1){
				cout << "\n\t\t  Error, Input value has been detected as NEGATIVE number\n";
				cout << "\t\t ============================================================\n";
				continue;
			} else if (cm > 999999){
				cout << "\n\t\t  Error, Input value is way too high\n";
				cout << "\t\t ============================================================\n";
				continue;
			}
		
		cout << "\n\n\n";
		cout << "\t\t  ===========================\n";
		cout << "\t\t  | centimeter = " << cm << "cm\n";
		cout << "\t\t  ===========================\n";
		mm = cm * 10;
		
		cout << "\t\t  | milimeter = " << mm <<"mm\n";
		cout << "\t\t  ===========================\n";
		m = cm / 100;
		
		cout << "\t\t  | meter = " << m <<"m\n";
		cout << "\t\t  ===========================\n";
		
	}
}
