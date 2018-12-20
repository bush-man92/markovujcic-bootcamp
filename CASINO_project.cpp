#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

void izbornik();
void uplata_novca();
void uplata_povratak();
void prikaz_stanja();
void isplata_novca();
void izbor_igara();
void menu_jednoruki_jack();
void provjera_chipova(int, int);
void kockice(int);
void kockice_menu();
void kockice_povratak(int);

string user_name = "";
int broj_chipova = 0;
int kolicina_novca = 0;


void duplo_ili_nista() {
	system("cls");
	prikaz_stanja();
	string boje[4] = {"PIK", "HERC", "TREF", "KARO"};
	int karte [13];
	srand(time(NULL));
	int boja = rand() % 4;
	int karta = rand() % 13;
	cout << endl;
	cout << "Stisnite 1 za duplo ili nista" << endl;
	cout << "Stisnite 2 za povratak na izbornik" << endl;
	cout << endl;
	int choice;
	cin >> choice;
	for (int i = 0; i < 26; i++){
		if (choice == 1) {
			duplo_ili_nista();
		}
		else if (choice ==  2) {
			izbornik();
		}
	}
}

void kockice_menu() {
	system("cls");
	prikaz_stanja();
	cout << endl;
	cout << "Upisite ulog :" << endl;
	int ulog = 0;
	cin >> ulog;
	provjera_chipova(ulog, 2);
	int choice;
	cout << endl;
	cout << "Stisnite 1 za igranje kocka" << endl;
	cout << "Stisnite 2 za povratak na menu" << endl;
	cout << endl;
	cin >> choice;
	if (choice == 1) {
		kockice(ulog);
	}
	else if(choice == 2) {
		izbornik();
	}
}

void kockice(int ulog) {
	system("cls");
	provjera_chipova(ulog, 2);
	prikaz_stanja();
	int A, B, C, D, bacanje;
	cout << endl;
	srand(time(NULL));
	A = rand() % 6 + 1;
	B = rand() % 6 + 1;
	C = rand() % 6 + 1;
	D = rand() % 6 + 1;
	cout << endl;
	for (int i = 0; i < 4; i++) {
		if (i == 1 || i == 3) {
			cout << endl;
			cout << "Protivnik baca kocku" << endl;
			if (i == 1)	{
				cout << endl;
				cout << "_____" << "   " << endl;
				cout << "|_" << B << "__|" << "   ";
				cout << endl;
			}
			else {
				cout << endl;
				cout << "_____" << "   " << endl;
				cout << "|_" << D << "__|" << "   ";
				cout << endl;
			}
		}
		else if (i == 0 || i == 2) {
			if (i == 0) {
				cout << endl;
				cout << "Bacite kocku(1)";
				int choice;
				cin >> choice;
				if (choice == 1) {
					cout << endl;
					cout << "_____" << "   " << endl;
					cout << "|_" << A << "__|" << "   ";
					cout << endl;
				}
			}
			else {
				cout << endl;
				cout << "Bacite kocku(1)";
				int choice;
				cin >> choice;
				if (choice == 1) {
					cout << endl;
					cout << "_____" << endl;
					cout << "|_" << C << "__|" << "   ";
					cout << endl;
				}	
			}
		}
	}
	if (A + C > B + D) {
		cout << endl;
		cout << "Vas broj " << A + C << " je veci od " << B + D << endl;
		cout << endl;
		broj_chipova += ulog * 3;
		cout << "Dobili ste " << ulog * 3 << " zetona" << endl;
	}
	else if (A + C < B + D) { 
		cout << endl;
		cout << "Vas broj " << A + C << " je manji od " << B + D << endl;
		cout << endl;
		broj_chipova -= ulog;
		cout << "Izgubili ste " << ulog << " zetona" << endl;
	}
	else {
		cout << endl;
		cout << "Izjednaceno " << A + C << endl;
	}
	kockice_povratak(ulog);
}

void kockice_povratak(int ulog) {
	cout << endl;
	cout << "Stisnite 1 za ponovo" << endl;
	cout << "Stisnite 2 za promjenu uloga" << endl;
	cout << "Stisnite 3 za izlaz na izbornik" << endl;
	cout << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		kockice(ulog);
	}
	else if(choice == 2) {
		kockice_menu();
	}
	else if (choice == 3) {
		izbornik();
	}
	else {
		kockice(ulog);
	}
}

void provjera_chipova(int ulog, int funkcija) {
	system("cls");
	if (broj_chipova <= 0 && kolicina_novca > 4) {
		cout << endl;
		cout << "Nemate vise chipova" << endl;
		cout << endl;
		cout << "Morate kupiti jos" << endl;
		cout << endl;
		cout << "Stisnite 1 za povrat na kupovinu chipova" << endl;
		int povrat;
		cin >> povrat;
		if (povrat = 1) {
			uplata_novca();
		}
		else {
			provjera_chipova(ulog, funkcija);
		}
	}
	else if(ulog > broj_chipova) {
		if (funkcija == 1) {
			menu_jednoruki_jack();
		}
		else if(funkcija == 2) {
			kockice_menu();
		}
	}
}

void prikaz_stanja() {
	cout << endl;
	cout << "\t" << user_name << "\t" "\t" << "chips " << broj_chipova << "\t" "\t" << "novac " << kolicina_novca << endl;
	cout << "____________________________________________________________________";
	cout << endl;
}

void jednoruki_jack (int ulog) {
	system("cls");
	provjera_chipova(ulog, 1);
	prikaz_stanja();
	srand(time(NULL));
	int A, B, C, D;
	char ikone[4] = {'X', 'O', '*', '+'};
	char prvi, drugi, treci, cetvrti;
	A = rand() % 4;
	B = rand() % 4;
	C = rand() % 4;
	D = rand() % 4;
	for (int i = 0; i < 4; i++) {
		if (A == i) {
			prvi = ikone[i];
		}
		if (B == i) {
			drugi = ikone[i];
		}
		if (C == i) {
			treci = ikone[i];
		}
		if (D == i) {
			cetvrti = ikone[i];
		}
	}
	cout << "_____ _____ _____ _____ " << endl;
	cout << "|_" << prvi << "_|" << " " <<  "|_" << drugi << "_|" << " " << "|_" << treci << "_|" << " " << "|_" << cetvrti << "_|" << endl;
	if (prvi == drugi && B == C && C == D) {
		cout << endl;
		cout << "POBJEDILI STE" << endl;
		broj_chipova += ulog * 5;
		cout << endl;
		cout << "Dobili ste " << ulog * 5 << " chipova";
	}
	else {
		cout << endl;
		cout << "Izgubili ste " << ulog << " chipova" << endl;
		broj_chipova -= ulog;
	}
	int choice;
	cout << endl;
	cout << "Stisnite 1 za ponovo" << endl;
	cout << "Stisnite 2 za promjenu uloga" << endl;
	cout << "Stisnite 3 za izlaz na izbornik" << endl;
	cout << endl;
	cin >> choice;
	if (choice == 1) {
		jednoruki_jack(ulog);
	}
	else if(choice == 2) {
		menu_jednoruki_jack();
	}
	else if (choice == 3) {
		izbornik();
	}
	else {
		jednoruki_jack(ulog);
	}
}

void menu_jednoruki_jack() {
	system("cls");
	prikaz_stanja();
	int choice, ulog, funkcija = 1;
	cout << endl;
	cout << "Unesite ulog chipova" << endl;
	cin >> ulog;
	provjera_chipova(ulog, funkcija);
	cout << endl;
	cout << "Stisnite 1 da pokrenete Jednorukog Jacka" << endl;
	cout << "Stisnite 2 za povratak na izbronik" << endl;
	cout << endl;
	cin >> choice;
	if (choice == 1) {
		jednoruki_jack(ulog);
	}
	else if (choice == 2) {
		izbornik();
	}
	else {
		menu_jednoruki_jack();
	}
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
	if (choice == 1) {
		menu_jednoruki_jack();
	}
	else if (choice == 2) {
		kockice_menu();
	}
	else if (choice == 3) {
		duplo_ili_nista();
	}
	else if (choice == 4) {
		izbornik();
	}
}

void isplata_povratak() {
	system("cls");
	prikaz_stanja();
	cout << endl;
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
	cout << endl;
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
			kolicina_novca += (broj_chipova + 1) * 5;
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
	cout << endl;
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
	cout << endl;
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
	cout << endl;
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
	else if (choice == 5) {
		exit(0);
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
