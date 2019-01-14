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
		string tip_racuna;
		
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
		string get_tip_racuna() {
			return tip_racuna;
		}
		void uplata(int uplata) {
			set_stanje_racuna(get_stanje_racuna() + uplata);
			for (int i = 2; i < vector_racuni.size(); i += 4) {
				if (vector_racuni[i] == get_broj_racuna_str()) {
					vector_racuni[i + 1] = get_stanje_racuna_str();
				}
			}
			save_racun();
		}
		void isplata(int isplata) {
			set_stanje_racuna(get_stanje_racuna() - isplata);
			for (int i = 2; i < vector_racuni.size(); i += 4) {
				if (vector_racuni[i] == get_broj_racuna_str()) {
					vector_racuni[i + 1] = get_stanje_racuna_str();
				}
			}
			save_racun();
		}
		void set_tip_racuna(string tip) {
			tip_racuna = tip;
		}
		void set_stanje_racuna(int iznos) {
			stanje_racuna = iznos;
		}
		void set_broj_racuna(int broj) {
			broj_racuna = broj;
		}
		void set_stanje_racuna_str(string iznos) {
			stringstream stanje_broj(iznos);
			int broj = 0;
			stanje_broj >> broj;
			stanje_racuna = broj;
		}
		void set_broj_racuna_str(string broj_racuna_str) {
			stringstream broj_racuna_1(broj_racuna_str);
			int broj = 0;
			broj_racuna_1 >> broj;
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
	cout << "Upisite 3 za izlazak" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		upis(welcome, 1);
	}
	else if (choice == 2) {
		upis(welcome, 2);
	}
	else if (choice == 3) {
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
		for (int i = 2; i < vector_korisnici.size(); i += 4) {
			if (lozinka == vector_korisnici[i]) {
				id = vector_korisnici[i + 1];
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
		for (int i = 0; i < vector_korisnici.size(); i += 4){
			if (vector_korisnici[i] == ime && vector_korisnici[i + 1] == prezime) {
				if (vector_korisnici[i+2] == lozinka) {
					return true;
				}
				else {
					top(welcome);
					cout << "Unijeli ste pogresnu lozinku!" << endl;
					cout << endl;
					system("pause");
					upis(welcome, 1);
				}
			}
			else {
				continue;
			}
		}
	}
	else {
		return false;
	}
}

bool racuni_provjera(string id) {
	if (vector_racuni.size() > 3) {
		for (int i = 0; i < vector_racuni.size(); i += 4) {
			if (vector_racuni[i] == id) {
				return true;
			}
			else {
				continue;
			}
		}
	}
	else {
		return false;
	}
}

void stvaranje_racuna_ziro(Korisnik korisnik1) {
	Racun racun1 = korisnik1.create_account();
	vector_racuni.push_back(korisnik1.get_id());
	vector_racuni.push_back("ziro");
	int broj_racuna = korisnik1.get_id_int() * 10 + 1;
	racun1.set_broj_racuna(broj_racuna);
	vector_racuni.push_back(racun1.get_broj_racuna_str());
	vector_racuni.push_back(racun1.get_stanje_racuna_str());
	save_racun();
	account_menu(korisnik1);
}

void stvaranje_racuna_tekuci(Korisnik korisnik1) {
	Racun racun1 = korisnik1.create_account();
	vector_racuni.push_back(korisnik1.get_id());
	vector_racuni.push_back("tekuci");
	int broj_racuna = korisnik1.get_id_int() * 10 + 2;
	racun1.set_broj_racuna(broj_racuna);
	vector_racuni.push_back(racun1.get_broj_racuna_str());
	vector_racuni.push_back(racun1.get_stanje_racuna_str());
	save_racun();
	account_menu(korisnik1);
}

void stvaranje_racuna_meni(Korisnik korisnik1, string top2) {
	top(top2);
	cout << "Stisnite 1 za stvaranje ziro racuna" << endl;
	cout << "Stisnite 2 za stvaranje tekuceg racuna" << endl;
	int choice2;
	cin >> choice2;
	if (choice2 == 1) {
		stvaranje_racuna_ziro(korisnik1);
	}
	else if (choice2 == 2) {
		stvaranje_racuna_tekuci(korisnik1);
	}
	else {
		stvaranje_racuna_meni(korisnik1, top2);
	}
}

void stvaranje_racuna(Korisnik korisnik1, string top2) {
	top(top2);
	cout << "Nemate racun u banci" << endl;
	cout << endl;
	cout << endl;
	cout << "Zelite li stvoriti novi racun? (y/n)" << endl;
	char choice;
	cin >> choice;
	if (choice == 'y' || choice == 'Y') {
		stvaranje_racuna_meni(korisnik1, top2);
	}
	else if (choice == 'n' || choice == 'N') {
		top(top2);
		cout << "Zelite li izaci iz applikacije? (y/n)" << endl;
		char choice3;
		cin >> choice3;
		if (choice3 == 'y' || choice3 == 'Y') {
			}
		else if (choice3 == 'n' || choice3 == 'N') {
			stvaranje_racuna(korisnik1, top2);
		}
		else {
			stvaranje_racuna(korisnik1, top2);
		}
	}
	else {
		stvaranje_racuna(korisnik1, top2);
	}
}

void special_account_menu(Racun racun1, Korisnik korisnik1) {
	string top3 = racun1.get_broj_racuna_str() + "    " + racun1.get_tip_racuna() + "     " + racun1.get_stanje_racuna_str();
	top(top3);
	cout << "Stisnite 1 za uplatu na racun" << endl;
	cout << "Stisnite 2 za isplatu s racuna" << endl;
	cout << "Stisnite 3 za povratak na izbornik racuna" << endl;
	int choice;
	cin >> choice;
	if (choice == 1) {
		top(top3);
		cout << "Koliko zelite uplatiti?" << endl;
		int uplata;
		cin >> uplata;
		racun1.uplata(uplata);
		special_account_menu(racun1, korisnik1);
	}
	else if (choice == 2) {
		top(top3);
		cout << "Koliko zelite da Vam se isplati?" << endl;
		int isplata;
		cin >> isplata;
		racun1.isplata(isplata);
		special_account_menu(racun1, korisnik1);
		
	}
	else if (choice == 3) {
		account_menu(korisnik1);
	}
	else {
		special_account_menu(racun1, korisnik1);
	}
}

void account_menu(Korisnik korisnik1) {
	string top2 = korisnik1.get_name() + " " + korisnik1.get_surname();
	top(top2);
	if (racuni_provjera(korisnik1.get_id()) == false) {
		stvaranje_racuna(korisnik1, top2);
	}
	else {
		vector<Racun> racuni_korisnika;
		for (int i = 0; i < vector_racuni.size(); i += 4) {
			if (vector_racuni[i] == korisnik1.get_id()) {
				Racun racun1 = korisnik1.create_account();
				racun1.set_tip_racuna(vector_racuni[i + 1]);
				racun1.set_broj_racuna_str(vector_racuni[i + 2]);
				racun1.set_stanje_racuna_str(vector_racuni[i + 3]);
				racuni_korisnika.push_back(racun1);
			}
			else {
				continue;
			}
		}
		for (int i = 0; i < racuni_korisnika.size(); i++) {
			cout << i + 1 << "     " << " Tip racuna: " << racuni_korisnika[i].get_tip_racuna() << "    ";
			cout << " Broj racuna: " << racuni_korisnika[i].get_broj_racuna() << "     ";
			cout << " Stanje racuna: " << racuni_korisnika[i].get_stanje_racuna() << endl;
			cout << endl;
		}
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "Odaberite racun kojim zelite poslovati" << endl;
		cout << "Stisnite 0 za stvaranje novog racuna" << endl;
		cout << "Stisnite 99 za vracanje logout" << endl;
		int choice;
		cin >> choice;
		if (choice == 0) {
			stvaranje_racuna_meni(korisnik1, top2);
		}
		else if(choice < racuni_korisnika.size()) {
			special_account_menu(racuni_korisnika[choice - 1], korisnik1);
		}
		else if (choice == 99) {
			string welcome =  "Dobrodosli u Banka.app";
			entry(welcome);
		}
		else {
			account_menu(korisnik1);
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
