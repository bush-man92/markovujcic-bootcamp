#include <iomanip>
#include <iostream>

using namespace std;

void sortiranje(int polje[], int velicina) {
	bool provjera = false;
	do{
		for (int i = 0; i < velicina; i++) {
			if (polje[i] > polje [i + 1]) {
				int temp = 0;
				temp = polje[i];
				polje[i] = polje[i + 1];
				polje[i + 1] = temp;
			}
			else if (polje[i] < polje[i + 1]) {
				provjera = true;
			}
		}
	} while (provjera == false);
		for (int i = 0; i < 20; i++) {
		cout << polje[i] << endl;
	}
}

int main() {
	int polje[20] = {100, 521, 5, 62, 6, 55, 731, 75, 21, 56, 12, 17, 111, 29, 59, 90, 23, 89, 123, 921};
	sortiranje(polje, 20);
}
