#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

int main() {
	string barkod = "";
	cin >> barkod;
	int ukupno = 0;
	for (int i = 0; i < 5; i++) {
		char trenutni = barkod[i];
		char kod = ' ';
		cin >> kod;
		if (kod == 'D') {
			int i_from_barkod = trenutni - '0';
			ukupno += i_from_barkod;
		}
	}
	cout << ukupno;
}
