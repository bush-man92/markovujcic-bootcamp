#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main() {
	int harry_puta = 0, hermiona_puta = 0;
	cin >> harry_puta >> hermiona_puta;
	string harry_broj = "";
	string hermiona_broj = "";
	for (int i = 0; i < harry_puta; i++) {
		string izvuceni_broj = "";
		cin >> izvuceni_broj;
		harry_broj += izvuceni_broj;
	}
	for (int i = 0; i < hermiona_puta; i++) {
		string izvuceni_broj = "";
		cin >> izvuceni_broj;
		hermiona_broj += izvuceni_broj;
	}
	int integar_harry = atoi(harry_broj.c_str());
	int integar_hermiona = atoi(hermiona_broj.c_str());
	cout << "HARRY:" << integar_harry << endl;
	cout << "HERMIONA:" << integar_hermiona << endl;
	if (integar_harry > integar_hermiona) {
		cout << "HARRY " << integar_harry - integar_hermiona;
	}
	else if (integar_harry < integar_hermiona) {
		cout << "HERMIONA " << integar_hermiona - integar_harry;
	}	
	else {
		cout << "JEDNAKO " << 0;
	}
}
