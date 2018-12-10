#include <iostream>
#include <iomanip>

using namespace std;

void izbornik();
void uplata_novca();
void uplata_povratak();
void prikaz_stanja();
void isplata_novca();
void izbor_igara();

string user_name = "";
int broj_chipova = 0;
int kolicina_novca = 0;

void prikaz_stanja() {
	cout << endl;
	cout << "\t" << user_name << "\t" "\t" << "chips " << broj_chipova << "\t" "\t" << "novac " << kolicina_novca << endl;
	cout << "____________________________________________________________________";
	cout << endl;
}

void jednoruki_jack() {
	
}

void izbor_igara () {
	system("cls");
	prikaz_stanja();
	cout << endl;
	cout << "Odaberite igru" << endl;
	cout << endl;
	cout << "Stisnite 1 za igru Jednoruki Jack" << endl;
	cout << "Stisnite 2 za igru Bacanje kockica" << endl;
	cout << "Stisnite 3 za igru Duplo ili nista" << endl;
	cout << "Stisnite 4 za vracanje na izbornik" << endl;
	int choice;
	cin >> choice;
}

void isplata_povratak() {
	system("cls");
	prikaz_stanja();
	cout << "Stisnite 1 za zamijeniti jos chipova" << endl;
	cout << "Stisnite 2 za povratak na izbornik" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		isplata_novca();
	}
	else if (choice == 2) {
		izbornik();
	}
	else {
		cout << "Niste unijeli ispravan odabir" << endl;
	}
	
}

void isplata_novca() {
	system("cls");
	prikaz_stanja();
	cout << "Zamijenite 1 chip za 5 kuna" << endl;
	cout << endl;
	cout << "Imate " << broj_chipova << " chipova" << endl;
	cout << endl;
	cout << "Unesite broj chipova koje zelite unovciti: " << endl;
	int zamjena = 0;
	cin >> zamjena;
	cout << endl;
	cout << "Jeste li sigurni da zelite unovciti " << zamjena << " chipova? (y/n)" << endl;
	char provjera = ' ';
	cin >> provjera;
	if (provjera == 'y' || provjera  == 'Y') {
		if (zamjena > broj_chipova) {
			kolicina_novca += broj_chipova * 5;
			broj_chipova = 0;
		}
		else {
			broj_chipova -= zamjena;
			kolicina_novca += zamjena * 5;
		}
		isplata_povratak();
	}
	else if (provjera == 'n' || provjera == 'N'){
		izbornik();
	}
}

void uplata_novca() {
	system("cls");
	prikaz_stanja();
	cout << "Kupite 1 chip za 5 kuna" << endl;
	cout << endl;
	cout << "Imate " << kolicina_novca << " kuna";
	cout << endl;
	cout << "Unesite broj chipova koje zelite uzeti: " << endl;
	int chip_broj;
	cin >> chip_broj;
	if (chip_broj * 5 >= kolicina_novca) {
		broj_chipova = kolicina_novca/5;
		kolicina_novca = 0;
	}
	else if (chip_broj * 5 < kolicina_novca) {
		broj_chipova += chip_broj;
		kolicina_novca -= chip_broj * 5;
	}
	uplata_povratak();
}

void uplata_povratak() {
	system("cls");
	prikaz_stanja();
	cout << "Stisnite 1 za kupiti jos chipova" << endl;
	cout << "Stisnite 2 za povratak na izbornik" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		uplata_novca();
	}
	else if (choice == 2) {
		izbornik();
	}
	else {
		cout << "Niste unijeli ispravan odabir" << endl;
	}
}

void izbornik() {
	system("cls");
	prikaz_stanja();
	cout << "Stisnite 1 za uplatu novca" << endl;
	cout << "Stisnite 2 za isplatu novca" << endl;
	cout << "Stisnite 3 za odabir igre" << endl;
	cout << "Stisnite 4 za pogled na highscore" << endl;
	cout << "Stisnite 5 za izlaz iz programa" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		uplata_novca();
	}
	else if (choice == 2) {
		isplata_novca();
	}
	else if (choice == 3) {
		izbor_igara();
	}
}

void novac_ogranicenje() {
	cout << endl;
	cout << "Upisite broj novca s kojim ulazite: " << endl;
	cout << endl;
	int novac = 0;
	cin >> novac;
	if (novac > 10001) {
		cout << endl;
		cout << "Ogranicenje unesenog novca u Casino je 10,000" << endl;
		novac_ogranicenje();
	}
	else if (novac < 0) {
		cout << endl;
		cout << "Ne mozete uci u Casino bez novca" << endl;
		novac_ogranicenje();
	}
	else {
		kolicina_novca = novac;
		izbornik();
	}
}

int main() {
	cout << "Dobrodosli u igru Casino";
	cout << endl;
	cout << endl;
	cout << "Upisite svoje ime:" << endl;
	string name = " ";
	cout << endl;
	cin >> name;
	user_name = name;
	novac_ogranicenje();
}
