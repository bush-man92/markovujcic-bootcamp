#include <iostream>
#include <iomanip>

using namespace std;

void bottles() {
	for (int i = 99; i > 0; i--) {
		cout << i << "bottles of beer on the wall" << endl;
	}
}



int zbrajanje() {
	int x = 1;
	int zbroj = 0;
	for (int i = 0; i < x;){
		cin >> x;
		zbroj += x;
	}
	cout << zbroj;
}

int lozinka() {
	string password = "password";
	string pokusaj = "";
	for (int i = 0; i < 3; i++) {
		cout << "Upisite lozinku: " << endl;
		cin >> pokusaj;
		if (pokusaj != password) {
			cout << "Kriva lozinka" << endl;
		}
		else {
			cout << "Tocna lozinka" << endl;
			break;
		}
	}
}

int tablica() {
	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			cout << i * j << '\t';
		}
		cout << endl;
	}
}

int zbroj(int x, int y){
	return x + y;
}

int oduzimanje(int x, int y) {
	return x - y;
}

int umnozak(int x, int y) {
	return x * y;
}

float dijeljenje(int x, int y) {
	return float(x)/y;
}

int menu() {
	int x;
	cout << "Stisnite 0 za izlaz \nStisnite 1 za bottles \nStisnite 2 za zbrajanje \nStisnite 3 za lozinku \nStisnite 4 za tablicu \nStisnite 5 za kalkulator" << endl;
	cin >> x;
	switch(x) {
		case 0:
			break;
		case 1:
			bottles();
			menu();
			break;
		case 2:
			zbrajanje();
			menu();
			break;
		case 3:
			lozinka();
			menu();
			break;
		case 4:
			tablica();
			menu();
			break;
		case 5:
			int x, y;
			char z;
			cout << "Upisite operaciju: " << endl;
			cin >> x >> z >> y;
			if (z == '+') {
				cout << zbroj(x, y) << endl;
			}
			else if(z == '-') {
				cout << oduzimanje(x, y) << endl;
			}
			else if(z == '*') {
				cout << umnozak(x, y) << endl ;
			}
			else if(z == '/'){
				cout << dijeljenje(x, y) << endl;
			}
			menu();
			break;
		default:
			cout << "Broj nije u menu" << endl;
			menu();
	}
}

int promjena(int a,int b) {
	cin >> a >> b;
}

int main() {
	int a = 7;
	int b = 19;
	//menu();
	cout << a << " " << b << endl;
}

