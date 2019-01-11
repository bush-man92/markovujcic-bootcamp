#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

void upis(string, int);
bool provjera(string, string, string, string);
void create_user(string, string, string, string);
bool racuni_provjera(string);
void save_racun();

vector<string> vector_korisnici;
vector<string> vector_racuni;

class Racun{
	
	protected:
		int broj_racuna;
		int stanje_racuna;
		
	public:
		
		static Racun novi_racun(){
			return Racun();
		}
		int get_stanje_racuna() {
			return stanje_racuna;
		}
		int get_broj_racuna() {
			return broj_racuna;
		}
		string get_stanje_racuna_str() {
			ostringstream str1;
			str1 << stanje_racuna;
			string stanje = str1.str();
			return stanje;
		}
		string get_broj_racuna_str() {
			ostringstream str1;
			str1 << broj_racuna;
			string broj = str1.str();
			return broj;
		}
		void uplata(int uplata) {
			set_stanje_racuna(get_stanje_racuna() + uplata);
		}
		void isplata(int isplata) {
			set_stanje_racuna(get_stanje_racuna() - isplata);
		}
		void set_stanje_racuna(int iznos) {
			stanje_racuna = iznos;
		}
		void set_broj_racuna(int broj) {
			broj_racuna = broj;
		}
};

class Korisnik {
	
	private:
		string name;
		string surname;
		string id;
		string lozinka;
		
		
	public:
		Korisnik (string ime, string prezime, string lozinka, string id) {
			set_name(ime);
			set_surname(prezime);
			set_lozinka(lozinka);
			set_id(id);
		}
		
		Racun create_account() {
			Racun racun1 = Racun::novi_racun();
			return racun1;
		}

		string get_name() {
			return name;
		}
		string get_surname() {
			return surname;
		}
		string get_id() {
			return id;
		}
		int get_id_int() {
			string id = get_id();
			stringstream broj2(id);
			int broj = 0;
			broj2 >> broj;
			return broj;
		}
		string get_lozinka() {
			return lozinka;
		}
		
	protected:
		void set_name(string ime) {
			name = ime;
		}
		void set_surname(string prezime) {
			surname = prezime;
		}
		void set_id(string id_num) {
			id = id_num;
		}
		void set_lozinka(string password) {
			lozinka = password;
		}
};

void account_menu(Korisnik);

void top(string str) {
	system("cls");
	cout << endl;
	cout << "\t" "\t" << str << endl;
	cout << endl;
	cout << "__________________________________________________________________________________________" << endl;
	cout << endl;
}

void entry(string welcome) {
	top(welcome);
	cout << "Upisite 1 za logiranje" << endl;
	cout << "Upisite 2 za registriranje" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		upis(welcome, 1);
	}
	else if (choice == 2) {
		upis(welcome, 2);
	}
	else {
		entry(welcome);
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

void load_racuni() {
	ifstream myfile;
	myfile.open("racuni.txt");
	string line;
	while(getline (myfile, line)) {
		vector_racuni.push_back(line);
	}
}

void save_racun(){
	ofstream myfile;
	myfile.open("racuni.txt");
	for (int i = 0; i < vector_racuni.size(); i++) {
		myfile << vector_racuni[i] << endl;
	}
}

void upis(string welcome, int check) {
	string ime, prezime, lozinka;
	top(welcome);
	cout << "Upisite ime i prezime" << endl;
	cin >> ime >> prezime;
	top(welcome);
	cout << "Upisite lozinku" << endl;
	cin >> lozinka;
	if (provjera(ime, prezime, lozinka, welcome) == false && check == 1) {
		top(welcome);
		cout << "Vaseg korisnika nema u bazi, morate se registrirati!" << endl;
		system("pause");
		entry(welcome);
	}
	else if (provjera(ime, prezime, lozinka, welcome) == true && check == 2) {
		top(welcome);
		cout << "Vas korisnik vec postoji, morate se ulogirati" << endl;
		system("pause");
		entry(welcome);
	}
	else if (provjera(ime, prezime, lozinka, welcome) == false && check == 2) {
		ofstream myfile;
		myfile.open("korisnici.txt");
		vector_korisnici.push_back(ime);
		vector_korisnici.push_back(prezime);
		vector_korisnici.push_back(lozinka);
		ostringstream str1;
		str1 << vector_korisnici.size();
		string id = str1.str();
		vector_korisnici.push_back(id);
		for (int i = 0; i < vector_korisnici.size(); i++) {
			myfile << vector_korisnici[i] << endl;
		}
		create_user(ime, prezime, lozinka, id);
	}
	else if(provjera(ime, prezime, lozinka, welcome) == true && check == 1) {
		string id = "";
		for (int i = 2; i < vector_korisnici.size(); i+3) {
			if (lozinka == vector_korisnici[i]) {
				id = vector_korisnici[i + 1];
				break;
			}
		}
		create_user(ime, prezime, lozinka, id);
	}
}

void create_user(string ime, string prezime, string lozinka, string id) {
	Korisnik korisnik1(ime, prezime, lozinka, id);
	account_menu(korisnik1);
}

bool provjera(string ime, string prezime, string lozinka, string welcome) {
	if (vector_korisnici.size() > 3) {
		for (int i = 0; i < vector_korisnici.size(); i+4){
			if (ime == vector_korisnici[i] && prezime == vector_korisnici[i + 1]) {
				if (lozinka == vector_korisnici[i + 2]) {
					return true;
				}
				else {
					cout << "Upisali ste krivu lozinku!" << endl;
					upis(welcome, 1);
				}
			}
			else {
				return false;		
			}
		}
	}
	else {
		return false;
	}
}

bool racuni_provjera(string id) {
	if (vector_racuni.size() > 2) {
		for (int i = 0; i < vector_racuni.size(); i+3) {
			if (vector_racuni[i] == id) {
				return true;
			}
			else {
				return false;
			}
		}
	}
	else {
		return false;
	}
}

void account_menu(Korisnik korisnik1) {
	string top2 = korisnik1.get_name() + " " + korisnik1.get_surname();
	top(top2);
	if (racuni_provjera(korisnik1.get_id()) == false) {
		cout << "Nemate ziro racun u banci" << endl;
		cout << endl;
		cout << endl;
		cout << "Nemate tekuci racun u banci" << endl;
		cout << endl;
		cout << endl;
		cout << "Zelite li stvoriti novi racun? (y/n)" << endl;
		char choice;
		cin >> choice;
		if (choice == 'y' || choice == 'Y') {
			top(top2);
			cout << "Stisnite 1 za stvaranje ziro racuna" << endl;
			cout << "Stisnite 2 za stvaranje tekuceg racuna" << endl;
			int choice3;
			cin >> choice3;
			if (choice3 == 1) {
				Racun racun1 = korisnik1.create_account();
				top(top2);
				cout << "Stanje na vasem racunu je " << racun1.get_stanje_racuna();
				vector_racuni.push_back(korisnik1.get_id());
				racun1.set_broj_racuna(vector_racuni.size());
				vector_racuni.push_back(racun1.get_broj_racuna_str());
				vector_racuni.push_back(racun1.get_stanje_racuna_str());
				cout << endl;
				save_racun();
				system("pause");
				account_menu(korisnik1);
			}
			else if (choice3 == 2) {
				Racun racun1 = korisnik1.create_account();
				top(top2);
				cout << "Stanje na vasem racunu je " << racun1.get_stanje_racuna();
				vector_racuni.push_back(korisnik1.get_id());
				racun1.set_broj_racuna(vector_racuni.size() + 1);
				vector_racuni.push_back(racun1.get_broj_racuna_str());
				vector_racuni.push_back(racun1.get_stanje_racuna_str());
				cout << endl;
				save_racun();
				system("pause");
				account_menu(korisnik1);
			}
			else {
				account_menu(korisnik1);
			}
		}
		else if (choice == 'n' || choice == 'N') {
			top(top2);
			cout << "Zelite li izaci iz applikacije? (y/n)" << endl;
			char choice2;
			cin >> choice2;
			if (choice2 == 'y' || choice2 == 'Y') {
			}
			else if (choice2 == 'n' || choice2 == 'N') {
				account_menu(korisnik1);
			}
		}
		else {
			account_menu(korisnik1);
		}
	}
	else {
		top(top2);
		for (int i = 0; i < vector_racuni.size(); i+3) {
			if (korisnik1.get_id() == vector_racuni[i]) {
				cout << "Broj racuna: " << "\t" << vector_racuni[i+1] << "\t" << "Stanje: " << "\t" << vector_racuni[i+2];
				break;
			}
		}
	}
}

int main() {
	string welcome =  "Dobrodosli u Banka.app";
	load();
	load_racuni();
	top(welcome);
	entry(welcome);
}
