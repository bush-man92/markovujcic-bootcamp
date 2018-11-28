#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int age1, age2;
	cout << "Napisi starost osobe broj jedan: " << endl;
	cin >> age1;
	cout << "Napisi starost osobe broj dva: " << endl;
	cin >> age2;
	if (age1 > age2) {
		cout << "Prva osoba je starija." << endl;
	}
	else if (age1 == age2){
		cout << "Osobe imaju jednako godina." << endl;
	}
	else {
		cout << "Druga osoba je starija" << endl;
	}
	
	int num;
	cout << "Napisi broj: " << endl;
	cin >> num;
	if (num % 2) {
		cout << "Broj je neparan" << endl;
	}
	else {
		cout << "Broj je paran" << endl;
	}
	
	string psw = "gefufna";
	string usr = "";
	cout << "Napisi lozinku: ";
	cin >> usr;
	if (psw == usr) {
		cout << "Lozinka je tocna." << endl;
	}
	else {
		cout << "Lozinka nije tocna." << endl;
	}
	
	float one, two;
	string opr = "";
	cout << "Napisite Vase brojeve: " << endl;
	cin >> one;
	cin >> two;
	cout << "Napisite operator: " << endl;
	cin >> opr;
	if (opr == "+"){
		cout << "Zbroj je: " << one + two;
	}
	else if (opr == "-"){
		cout << "Razlika je: " << one - two;
	}
	else if (opr == "*"){
		cout << "Umnozak je: " << one * two;
	}
	else if (opr == "/"){
		cout << "Kvocijent je: " << setprecision(2) << fixed << one / two << endl;
	}
	
}
