#include <string.h>
#include <iostream>
#include <ctype.h>
#include <stdlib.h>

using namespace std;

int main(){
	char username[20];
	char pass1[20],pass2[20],pass3[9999];
	
	cout << "\n\n";
	cout << "\t_----------------------------------------_\n";
	cout << "\t|                                        |\n";
	cout << "\t|            ACCOUNT GENERATOR           |\n";
	cout << "\t|                                        |\n";
	cout << "\t*----------------------------------------*\n";
	
	cout << "\n\n";
	cout << "\t Enter your username: ",strcpy;
	cin >> username;
	
	strlwr(username);
	
	retry:
		
	cout << "\n\n";
	cout << "\t -------> Random password generator part <------ \n";
	cout << "\t Enter first string to contain in your password: ",strcpy;
	cin >> pass1;
	if (strlen(pass1) <= 5){
		cout << "\n\t Please enter a string more than 6";
		goto retry;
	}
	strlwr(pass1);
	strrev(pass1);
	
	cout << "\n\n";
	cout << "\t Enter second string to contain in your password: ",strcpy;
	cin >> pass2;
	if (strlen(pass2) <= 5){
		cout << "\n\t Please enter a string more than 6";
		goto retry;
	}
	strlwr(pass1);
	strrev(pass2);
	
	if (strcmp(pass1,pass2)==0){
		cout << "\n\t Please retry, both string are the same. ";
		goto retry;
	}
	
	strcat(pass1,pass2);
	
	cout << "\n\n";
	cout << "\t Enter a number: ",strcpy;
	cin >> pass2;
	
	strcat(pass1,pass2);
	strupr(pass1);
	
	
	system("cls");
	
	cout << "\n\n";
	cout << "\t-------------------------------------------\n";
	cout << "\n\t Username: " << username;
	cout << "\n\t Random generated password: " << pass1;
	cout << "\n\n\t-------------------------------------------\n";
	cout << "\n\t Password length: " <<strlen(pass1);
	cout << "\n\t Password strength: ";
	if (strlen(pass1) >= 10 && strlen(pass1) <= 14 ){
		cout << "weak";
	} else if (strlen(pass1) >= 15 && strlen(pass1) <= 19 ){
		cout << "average";
	} else if (strlen(pass1) >= 20 ){
		cout << "strong";
	}
	cout << "\n\n\t-------------------------------------------\n";
	
	
	
	
	
	
	
	
	
	
}
