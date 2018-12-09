#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int pos1, pos2;
	cin >> pos1 >> pos2;
	for (int i = 0; i < 5; i++) {
		int privremena1, privremena2;
		cin >> privremena1 >> privremena2;
		if (privremena1 == pos1) {
			pos1 = privremena2;
		}
		else if (privremena1 == pos2) {
			pos2 = privremena2;
		}
		else if (privremena2 == pos1) {
			pos1 = privremena1;
		}
		else if (privremena2 == pos2) {
			pos2 = privremena1;
		}
	}
	if (pos1 >= pos2) {
		cout << pos2 << " " << pos1;
	}
	else {
		cout << pos1 << " " << pos2;
	}
}
