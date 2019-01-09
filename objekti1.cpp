#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <stdlib.h> 

using namespace std;

class Racun{
	friend class Korisnik;
	protected:
		int broj_racuna;
		int stanje_racuna;
		Racun() {
			broj_racuna = 
			stanje_racuna = 0;
		}
		int get_stanje_racuna() {
			return stanje_racuna;
		}
		void set_stanje_racuna(int iznos) {
			stanje_racuna = iznos;
		}
	public:
		void uplata(int uplata) {
			set_stanje_racuna(get_stanje_racuna() + uplata);
		}
		void isplata(int isplata) {
			set_stanje_racuna(get_stanje_racuna() - isplata);
		}
};

class Korisnik{
	friend class Entry;
	friend class Racun;
	protected:
		Korisnik (string name, string surname, int id) {
			set_name(name);
			set_surname(surname);
			set_id(id);
			show_info(name, surname);
			menu_racuni(name, surname);
		}
		Korisnik (string name, string surname, int id, int reg) {
			set_name(name);
			set_surname(surname);
			set_id(id);
			show_info(name, surname);
			create_racun();
		}
		string name;
		string surname;
		int id;
		string get_name() {
			return name;
		}
		string get_surname() {
			return surname;
		}
		void set_name(string ime) {
			ime = name;
		}
		void set_surname(string prezime) {
			prezime = surname;
		}
		void set_id(int id_num) {
			id_num = id;
		}
	public:
		void show_info(string name, string surname) {
			system("cls");
			cout << endl;
			cout << "\t" << name << " " << surname;
			cout << endl;
			cout << "___________________________________________________________________" << endl; 
		}
		void menu_racuni(string name, string surname) {
			cout << endl;
			cout << "Odaberite racun: " << endl;
			cout << endl;
			cout << "1 za ziro racun " << endl;
			cout << "2 za tekuci racun " << endl;
			string choice;
			cin >> choice;
			if (choice == "1") {
				Racun racun_ziro;
				show_info(name, surname);
				cout << racun_ziro.get_stanje_racuna();
			}
			else if (choice == "2") {
				Racun racun_tekuci;
			}
		}
		void create_racun() {
			cout << "Nemate otvorenih racuna u banci!" << endl;
			cout << endl;
			cout << "Stisnite 1 za otvaranje ziro racuna " << endl;
			cout << "Stisnite 2 za otvaranje tekuceg racuna " << endl;
			string choice;
			cin >> choice;
			if (choice == "1") {
				Racun racun_ziro;
			}
			else if (choice == "2") {
				Racun racun_tekuci;
			}
		}
};

class Entry {
	friend class Korisnik;
	protected:
		vector<string> vector_korisnici;
	public:
		void login() {
			cout << "Upisite ime i prezime: " << endl;
			string ime, prezime, lozinka;
			cin >> ime >> prezime;
			cout << "Upisite lozinku: " << endl;
			cin >> lozinka;
			if (provjera(ime, prezime, lozinka) == false) {
				registracija(ime, prezime, lozinka);
			}
			else {
				create_user(ime, prezime, 1);
			}
		}
		void create_user (string ime, string prezime, int reg) {
			if (reg == 1) {
				Korisnik korisnik1(ime, prezime, vector_korisnici.size());
			}
			else if (reg == 2) {
				Korisnik korisnik1(ime, prezime, vector_korisnici.size(), reg);
			}
		}
		void registracija(string name,string surname,string password) {
			cout << "Zelite li se registrirati? (y/n)" << endl;
			char choice;
			cin >> choice;
			if (choice == 'y') {
				ofstream myfile;
				myfile.open("korisnici.txt");
				vector_korisnici.push_back(name);
				vector_korisnici.push_back(surname);
				vector_korisnici.push_back(password);
				int korisnik_id = atoi(vector_korisnici.size().c_str());
				string id = korisnik_id;
				vector_korisnici.push_back(id);
				for (int i = 0; i < vector_korisnici.size(); i++) {
					myfile << vector_korisnici[i] << endl;
				}
				create_user(name, surname, 2);
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
		bool provjera(string ime,string prezime,string lozinka) {
			if (vector_korisnici.size() > 3) {
				for (int i = 0; i < vector_korisnici.size(); i+4){
					if (ime == vector_korisnici[i] && prezime == vector_korisnici[i + 1]) {
						if (lozinka == vector_korisnici[i + 2]) {
							return true;
						}
						else {
							cout << "Upisali ste krivu lozinku!" << endl;
							login();
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
};

int main() {
	Entry entry1;
	entry1.load();
	entry1.login();
}

