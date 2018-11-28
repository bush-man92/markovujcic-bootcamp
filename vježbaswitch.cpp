#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	
	int num1, num2;
	char x;
	cout << "Unesite dva broja: " << endl;
	cin >> num1;
	cin >> num2;
	cout << "Unesite operator: " << endl;
	cin >> x;
	switch (x){
		case '+':
			cout << "Zbroj je: " << num1 + num2;
			break;
		case '-':
			cout << "Razlika je: " << num1 - num2;
			break;
		case '*':
			cout << "Umnožak je: " << num1 * float(num2);
			break;
		case '/':
			cout << "Kvocijent je: " << num1 / float(num2);
			break;
		default:
			cout << "Niste unijeli ispravan operator." << endl;
			break;
	}
}
