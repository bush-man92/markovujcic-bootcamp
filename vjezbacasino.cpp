#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int novcic() {
	int broj;
	srand(time(NULL));
	for (int i = 0; i < 2; i++) {
		broj = (rand() % 2);
		if (broj == 0) {
			cout << "glava" << endl;
			break;
		}
		else {
			cout << "pismo" << endl;
			break;
		}
	}
	int main();
}

int nasumicno() {
	int broj;
	srand(time(NULL));
	broj = (rand() % 100 + 1);
	cout << "Stisnite 0 za izlaz" << endl;
	for (int i = 0; i < 1;) {
		int pokusaj = 0;
		cout << "Pogodi broj: " << endl;
		cin >> pokusaj;
		if (pokusaj < broj) {
			cout << "Tvoj broj je manji od trazenog" << endl;
		}
		else if (pokusaj > broj) {
			cout << "Tvoj broj je veci od trazenog" << endl;
		}
		else if(pokusaj == 0) {
			break;
		}
		else{
			cout << "POGODENO" << endl;
			break;
		}
	}
	int main();
}

int slotmachine() {
	int A = 0, B, C, D;
	srand(time(NULL));
	int choice = 0;
	cout << "Stisnite 1 da zavrtite brojeve, 0 za izlaz" << endl;
	cin >> choice;
	if (choice == 1) {
		for (int i = 0; i < 1;) {
			A = rand() % 4 + 1;
			B = rand() % 4 + 1;
			C = rand() % 4 + 1;
			D = rand() % 4 + 1;
			cout << A << '\t' << B << '\t' << C << '\t' << D << endl;;
			if (A == B && B == C && C == D) {
				cout << "POBJEDILI STE" << endl << "Dobili ste nista.." << endl;;
			}
			else {
				cout << "Izgubili ste" << endl;
			}
			cout << "Stisnite 1 da zavrtite brojeve, 0 za izlaz" << endl;
			cin >> choice;
			if (choice == 0) {
				break;
			}
		}
	}
	else if (choice == 0) {
		int main();
	}
}

int main() {
	int choice = 0;
	for (int i = 0; i < 1;) {
		cout << "Stisni 1 za bacanje novcica" << endl;
		cout << "Stisni 2 za pogadanje brojeva" << endl;
		cout << "Stisni 3 za slotmachine" << endl;
		cin >> choice;
		if (choice == 1) {
			novcic();
		}
		else if (choice == 2) {
			nasumicno();
		}
		else if (choice == 3) {
			slotmachine();
		}
	}
}
