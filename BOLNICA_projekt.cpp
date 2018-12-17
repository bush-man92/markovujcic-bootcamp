#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

using namespace std;

struct kartoteka {
	int MBO;
	string ime;
	string prezime;
	vector<string> popis_lijekova;
};

vector<kartoteka> pacijenti;

int main();

void prikaz(string name) {
	cout << endl;
	cout << "\t" "\t" << name;
	cout << endl;
	cout << "___________________________________________________________" << endl;
	cout << endl;
}

void upis_u_datoteku() {
	ofstream myfile;
	myfile.open ("lista_pacijenata.txt");
	for (int i = 0; i < pacijenti.size(); i++) {
		myfile << pacijenti[i].ime << "\t" << pacijenti[i].prezime << "\t" << pacijenti[i].MBO;
		for (int j = 0; j < pacijenti[i].popis_lijekova.size(); j++) {
			myfile << "\t" << pacijenti[i].popis_lijekova[j];
		}
		cout << endl;
	}
	myfile.close();
}

void iz_datoteke() {
	ifstream myfile;
	myfile.open ("lista_pacijenata.txt");
	getline(myfile, line)
}

void unos_pacijenata() {
	system("cls");
	prikaz("UNOS PACIJENATA U KARTOTEKU");
	kartoteka pacijent;
	cout << "MBO: " << endl;
	cin >> pacijent.MBO;
	cout << endl;
	cout << "Ime: " << endl;
	cin >> pacijent.ime;
	cout << endl;
	cout << "Prezime: " << endl;
	cin >> pacijent.prezime;
	cout << endl;
	cout << "Za kraj popisa lijekova upisite Q" << endl;
	cout << "Popis lijekova: " << endl;
	cout << endl;
	vector<string> temp;
	for (int j = 0; j < 1;) {
		string temp_lijekovi = "";
		cin >> temp_lijekovi;
		if (temp_lijekovi == "Q") {
			break;
		}
		else {
			temp.push_back(temp_lijekovi);
		}
	}
	pacijent.popis_lijekova = temp;
	pacijenti.push_back(pacijent);
	upis_u_datoteku();
	main();
}

void ispis() {
	system("cls");
	prikaz("ISPIS PACIJENATA");
	cout << "1 za povratak na izbornik" << endl;
	cout << endl;
	for (int i = 0; i < pacijenti.size(); i++) {
		cout << pacijenti[i].ime << "\t" << pacijenti[i].prezime << "\t" << pacijenti[i].MBO << endl;
		for (int j = 0; j < pacijenti[i].popis_lijekova.size(); j++) {
			cout << "LIJEK: " << "\t" << pacijenti[i].popis_lijekova[j] << "\t" << endl;
		}
		cout << endl;
	}
	int choice = 0;
	cin >> choice;
	if (choice == 1) {
		main();
	}
	else {
		ispis();
	}
}

int main() {
	system("cls");
	prikaz("IZBORNIK");
	cout << "1 za unos pacijenata u kartoteku" << endl;
	cout << "2 za ispis pacijenata" << endl;
	cout << "3 pretraga pacijenata po MBO" << endl;
	cout << "4 za sustav cekaonice" << endl;
	cout << "5 za dodavanje recepata za lijekove na korisnicki racun pacijenta" << endl;
	cout << "6 za izlaz" << endl;
	
	int choice = 0;
	cin >> choice;
	if (choice == 1) {
		unos_pacijenata();
	}
	else if (choice == 2) {
		ispis();
	}
}
