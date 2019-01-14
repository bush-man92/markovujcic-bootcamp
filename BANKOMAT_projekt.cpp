#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>

using namespace std;

class Korisnik {
	private:
		string name;
		string surname;
		string password;
		string id;
		
	protected:
		void set_name(string ime) {
			name = ime;
		}
		void set_surname(string prezime) {
			surname = prezime;
		}
		void set_password(string lozinka) {
			password = password;
		}
		void set_id(string id_num) {
			id = id_num;
		}
		
	public:
		Korisnik(string ime, string prezime, string lozinka, string id) {
			set_name(ime);
			set_surname(prezime);
			set_password(lozinka);
			set_id(id);
		}
		string get_name() {
			return name;
		}
		string get_surname() {
			return surname;
		}
		string get_password() {
			return password;
		}
		string get_id() {
			return id;
		}
};

void top(string);
Korisnik login();
bool provjera(string, string, string);
void upis(int);
vector<string> vector_korisnici;
string welcome = "Dobrodosli u Banka.app";
void entry();

class Racun {
	private:
		int broj_racuna;
		int stanje_racuna;
		
	protected:
		int get_stanje_racuna() {
			return stanje_racuna;
		}
		void set_stanje_racuna(int iznos) {
			stanje_racuna = iznos;
		}
		int get_broj_racuna() {
			return broj_racuna;
		}
		void set_broj_racuna(int broj) {
			broj_racuna = broj;
		}
		
	public:
		void uplata(int uplata) {
			set_stanje_racuna(get_stanje_racuna() + uplata);
		}
		void isplata(int isplata) {
			set_stanje_racuna(get_stanje_racuna() - isplata);
		}
};

Korisnik registracija(string ime, string prezime, string lozinka) {
	if (provjera(ime, prezime, lozinka) == true) {
		top(welcome);
		cout << "Vase korisnicko ime vec postoji, ulogirajte se!" << endl;
		system("pause");
		entry();
	}
	else {
		ofstream myfile;
		myfile.open("korisnici.txt");
		vector_korisnici.push_back(ime);
		vector_korisnici.push_back(prezime);
		vector_korisnici.push_back(lozinka);
		int int_id = vector_korisnici.size();
		ostringstream str1;
		str1 << int_id;
		string id = str1.str();
		vector_korisnici.push_back(id);
		for (int i = 0; i < vector_korisnici.size(); i++) {
			myfile << vector_korisnici[i] << endl;
		}
		Korisnik korisnik1(ime, prezime, lozinka, id);
		return korisnik1;
	}
}
	
void entry() {
	top(welcome);
	cout << " Upisite 1 za logiranje" << endl;
	cout << " Upisite 2 za registraciju" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		upis(1);
	}
	else if (choice == 2) {
		upis(2);
	}
	else {
		entry();
	}
}

void load() {
	ifstream myfile;
	myfile.open("korisnici.txt");
	string line;
	while(getline (myfile, line)) {
		vector_korisnici.push_back(line);
	}
}

Korisnik login(string ime, string prezime, string lozinka) {
	if (provjera(ime, prezime, lozinka) == false) {
		top(welcome);
		cout << "U bazi podataka nema vaseg korisnika, registrirajte se!" << endl;
		system("pause");
		entry();
	}
	else {
		string id = "";
		for (int i = 2; i < vector_korisnici.size(); i+3) {
			if (lozinka == vector_korisnici[i]) {
				id = vector_korisnici[i + 1];
				break;
			}
		}
		Korisnik korisnik1(ime, prezime, lozinka, id);
		return korisnik1;
	}
}

bool provjera(string ime, string prezime, string lozinka) {
	if (vector_korisnici.size() > 3) {
		for (int i = 0; i < vector_korisnici.size(); i+4){
			if (ime == vector_korisnici[i] && prezime == vector_korisnici[i + 1]) {
				if (lozinka == vector_korisnici[i + 2]) {
					return true;
				}
				else {
					top(welcome);
					cout << " Upisali ste krivu lozinku!" << endl;
					system("pause");
					upis(1);
					break;
				}
			}
			else {
				false;		
			}
		}
	}
	else {
		false;
	}
}

void upis(int prekidac) {
	top(welcome);
	cout << " Upisite ime i prezime: " << endl;
	string ime, prezime, lozinka;
	cin >> ime >> prezime;
	top(welcome);
	cout << " Upisite lozinku: " << endl;
	cin >> lozinka;
	if (prekidac == 1) {
		login(ime, prezime, lozinka);
	}
	else if (prekidac == 2) {
		registracija(ime, prezime, lozinka);
	}
}

void top(string ispis) {
	system("cls");
	cout << endl;
	cout << "\t" "\t" << ispis << endl;
	cout << "_____________________________________________________________________________________________" << endl;
	cout << endl;
}

int main() {
	load();
	top(welcome);
	entry();
	cout << "OK";
}

