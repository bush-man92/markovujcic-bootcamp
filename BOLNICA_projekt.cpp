#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <stdlib.h> 

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

void kartoteka_sort() {
	for (int i = 0; i < pacijenti.size();i++) {
		if (pacijenti[i].MBO > pacijenti[i + 4])
		for (int i = 0; i < pacijenti.size(); i++) {
			if(pacijenti[i].MBO > pacijenti[i + 5].MBO) {
				kartoteka pacijent_temp;
				pacijent_temp = pacijenti[i + 5];
				pacijent[i + 5] = pacijent[i];
			}
		}
	}
}

void upis_u_datoteku() {
	ofstream myfile;
	myfile.open ("lista_pacijenata.txt");
	for (int i = 0; i < pacijenti.size(); i++) {
		myfile << pacijenti[i].ime << endl << pacijenti[i].prezime << endl << pacijenti[i].MBO << endl;
		for (int j = 0; j < pacijenti[i].popis_lijekova.size(); j++) {
			myfile << pacijenti[i].popis_lijekova[j] << endl;
		}
		cout << endl;
	}
	myfile.close();
}

bool MBO_checker (int MBO) {
	bool checker = false;
	for (int i = 0; i < pacijenti.size(); i++) {
		if (MBO == pacijenti[i].MBO) {
			checker = true;
		}
	}
	return checker;
}

void iz_datoteke() {
	ifstream myfile;
	string line;
	myfile.open("lista_pacijenata.txt");
	vector<string> temp;
	vector<string> temp2;
	while(getline(myfile, line)) {
		temp.push_back(line);
	}
	myfile.close();
	for (int i = 0; i < temp.size(); i++) {
		vector<string> temp_lijekovi;
		if (temp[i] != "Q") {
			temp2.push_back(temp[i]);
		}
		else {
			for (int j = 0; j < 1; j++) {
				int MBO = atoi(temp2[2].c_str());
				if (MBO_checker(MBO) == true) {
					break;
				}
				kartoteka pacijent;
				pacijent.ime = temp2[0];
				pacijent.prezime = temp2[1];
				pacijent.MBO = MBO;
				for (int k = 3; k < temp2.size(); k++) {
					temp_lijekovi.push_back(temp2[k]);
				}
				temp_lijekovi.push_back("Q");
				pacijent.popis_lijekova = temp_lijekovi;
				pacijenti.push_back(pacijent);
				temp2.clear();
			}
		}
	}
}

void unos_pacijenata() {
	system("cls");
	prikaz("UNOS PACIJENATA U KARTOTEKU");
	kartoteka pacijent;
	cout << "MBO: " << endl;
	int MBO;
	cin >> MBO;
	if (MBO_checker(MBO) == true) {
		cout << "Taj pacijent vec postoji u kartoteci" << endl;
		char bla;
		cin >> bla;
		main();
	}
	else {
		pacijent.MBO = MBO;
	}
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
		temp.push_back(temp_lijekovi);
		if (temp_lijekovi == "Q") {
			break;
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
	if (pacijenti.size() > 0) {
		for (int i = 0; i < pacijenti.size(); i++) {
			cout << pacijenti[i].ime << " " << pacijenti[i].prezime << " " << pacijenti[i].MBO << endl;
			cout << endl;
			cout << "_____________________________________________________________" << endl;
			for (int j = 0; j < pacijenti[i].popis_lijekova.size(); j++) {
				if (pacijenti[i].popis_lijekova[j] != "Q") {
					cout << "LIJEK: " << " " << pacijenti[i].popis_lijekova[j] << " " << endl;
				}
			}
			cout << endl;
			cout << endl;
		}
	}
	int choice;
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
	iz_datoteke();
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
	else if (choice == 3) {
	}
}
