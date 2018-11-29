#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int sjedalo;
	cout << "Upisi sjedalo: " << endl;
	cin >> sjedalo;
	if (sjedalo == 7 || sjedalo == 8) {
		cout << 1;
	}
	else if (sjedalo == 5 || sjedalo == 6) {
		cout << 4;
	}
	else if (sjedalo == 3 || sjedalo == 4) {
		cout << 5;
	}
	else if (sjedalo == 1 || sjedalo == 2) {
		cout << 8;
	}
}
