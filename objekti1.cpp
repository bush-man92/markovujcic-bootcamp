#include <iostream>
#include <iomanip>

using namespace std;

class Racun{
	protected:
		int broj_racuna = 0;
		int stanje_racuna = 0;
		int get_stanje_racuna() {
			return stanje_racuna;
		}
		void set_stanje_racuna(int iznos) {
			stanje_racuna = iznos;
		}
	public:
		Racun() {
		}
		void uplata(int uplata) {
			set_stanje_racuna(get_stanje_racuna() + uplata);
		}
		void isplata(int isplata) {
			set_stanje_racuna(get_stanje_racuna() - isplata);
		}
		void stanje() {
			cout << get_stanje_racuna() << endl;
		}
};

int main {
	Racun racun1;
}

