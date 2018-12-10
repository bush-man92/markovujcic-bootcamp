#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int iznos = 1000;

void menu();
void novcic();

void novcic_menu() {
	system("cls");
	cout << "Broj Vasih zetona je " << iznos << endl;
	cout << "________________________________________________" << endl;
	cout << endl;
	cout << "Stisnite 1 za igranje pismo ili glava" << endl;
	cout << "Stisnite 0 za povratak na menu" << endl;
	int choice;
	cin >> choice;
	if (choice == 1)  {
		novcic();
	}
	else if (choice == 0) {
		menu();
	}
}

void novcic() {
	system("cls");
	cout << "Broj Vasih zetona je " << iznos << endl;
	cout << "________________________________________________" << endl;
	cout << endl;
	int broj;
	srand(time(NULL));
	cout << "Novcic je bacen, odaberite p ili g" << endl;
	string pogodak = "";
	string pokusaj = "";
	cin >> pokusaj;
	for (int i = 0; i < 2; i++) {
		broj = (rand() % 2);
		if (broj == 0) {
			pogodak = "g";
			cout << "GLAVA" << endl;
			break;
		}
		else {
			pogodak = "p";
			cout << "PISMO" << endl;
			break;
		}
	}
	if (pokusaj == pogodak) {
		cout << "Pogodili ste" << endl;
		iznos += 10;
	}
	else {
		cout << "Izgubili ste" << endl;
		iznos -= 10;
	}
	cout << endl;
	cout << "Zelite li nastaviti igrati?(y/n)" << endl;
	char nastavak = ' ';
	cin >> nastavak;
	if (nastavak == 'y') {
		novcic();
	}
	else if (nastavak == 'n') {
		menu();
	}
}

void nasumicno() {
	system("cls");
	cout << "Broj Vasih zetona je " << iznos << endl;
	cout << "________________________________________________" << endl;
	cout << endl;
	cout << "Stisnite 1 za igranje pogadanja broja" << endl;
	cout << "Stisnite 0 za povratak na menu" << endl;
	int choice;
	cin >> choice;
	int broj;
	srand(time(NULL));
	broj = (rand() % 100 + 1);
	if (choice == 1) {
		cout << "Imate cetiri pokusaja da pogodite broj" << endl;
		for (int i = 0; i <= 4;) {
			int pokusaj = 0;
			cout << "Upisi prvi pokusaj: " << endl;
			cin >> pokusaj;
			if (i == 4) {
				cout << "Izgubili ste" << endl;
				iznos -= 50;
			}
			if (pokusaj < broj) {
				cout << "Tvoj broj je manji od trazenog" << endl;
			}
			else if (pokusaj > broj) {
				cout << "Tvoj broj je veci od trazenog" << endl;
			}
			else{
				cout << "POGODENO" << endl;
				iznos += 50;
			}	
		}
		int A = 0;
		cin >> A;
		nasumicno();
	}
	else if (choice == 0) {
		menu();
	}
}

void slotmachine() {
	system("cls");
	cout << "Broj Vasih zetona je " << iznos << endl;
	cout << "________________________________________________" << endl;
	cout << endl;
	int A = 0, B, C, D;
	srand(time(NULL));
	int choice = 0;
	cout << "Stisnite 1 da zavrtite brojeve" << endl;
	cout << "Stisnite 0 za povratak na menu" << endl;
	for (int i = 0; i < 1;) {
		cin >> choice;
		if (choice == 1) {
			for (int i = 0; i < 1;) {
				A = rand() % 4 + 1;
				B = rand() % 4 + 1;
				C = rand() % 4 + 1;
				D = rand() % 4 + 1;
				cout << A << '\t' << B << '\t' << C << '\t' << D << endl;
			}
			if (A == B && B == C && C == D) {
				cout << "POBJEDILI STE" << endl;
				iznos += 50;
				
			}
			else {
				cout << "Izgubili ste" << endl;
				iznos -= 50;
			}
			int A = 0;
			cin >> A;
			slotmachine();
		}
		if (choice == 0) {
			menu();
		}
	}
}


void menu() {
	system("cls");
	cout << "Broj Vasih zetona je " << iznos << endl;
	cout << "________________________________________________" << endl;
	cout << endl;
	int choice = 0;
	for (int i = 0; i < 1;){
		cout << "Stisnite 1 za bacanje novcica" << endl;
		cout << "Stisnite 2 za pogadanje brojeva" << endl;
		cout << "Stisnite 3 za slotmachine" << endl;
		cout << "Stisnite 0 za izlaz" << endl;
		cin >> choice;
		if (choice == 1) {
			novcic_menu();
		}
		else if (choice == 2) {
			nasumicno();
		}
		else if (choice == 3) {
			slotmachine();
		}
		else if (choice == 0) {
			exit(0);
		}
	}
}

int main() {
	cout << "Upisite ime korisnika: " << endl;
	string username = " ";
	cin >> username;
	system("cls");
	cout << "Dobrodosli " << username << endl;
	string bilosta = " ";
	cout << "Pritisnite bilokoju tipku za nastavak" << endl;
	cin >> bilosta;
	menu();
}
