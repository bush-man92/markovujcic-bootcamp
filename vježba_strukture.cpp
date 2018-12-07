#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Brod {
	int pos_x, pos_y;
	int svemir[20][20];
};

void pomak_broda(int &a, int &b) {
	int pomak_x = 0, pomak_y = 0;
	srand(time(NULL));
	pomak_x = (rand() % 4);
	pomak_y = (rand() % 4);
	random_plus_minus = (rand( % 2))
	if (random_plus_minus == 0) {
		
	}
	a += pomak_x;
	b += pomak_y;
}

void prikaz(int &a, int &b) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (j == a && i == b) {
				cout << "X" << " ";
			}
			else {
				cout << "O" << " ";
			}
		}
		cout << endl;
	}
}

void menu(int &a, int &b) {
	int choice;
	cout << "Pomaknite brod sa 1: " << endl;
	cin >> choice;
	if (choice == 1) {
		system("cls");
		pomak_broda(a, b);
		prikaz(a, b);
		cout << "Koordinate broda su:" << endl << a << " " << b << endl;
		menu(a, b);
		}
	else if (choice != 1) {
		exit(0);
	}
}

int main() {
	int x, y;
	cout << "Upiste koordinate broda:" << endl;
	cin >> x >> y;
	Brod(brod);
	brod.pos_x = x;
	brod.pos_y = y;
	prikaz(brod.pos_x, brod.pos_y);
	menu(brod.pos_x, brod.pos_y);
}
