#include <iostream>
#include <iomanip>

using namespace std;

class Racun{
	protected:
		int broj_racuna;
		int stanje_racuna;
		int get_stanje_racuna() {
			return stanje_racuna;
		}
		void set_stanje_racuna(int iznos) {
			stanje_racuna = iznos;
		}
	public:
		Racun() {
			set_stanje_racuna(0);
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

int main() {
	Racun racun1;
	racun1.stanje();
	racun1.uplata(100);
	racun1.stanje();
}

