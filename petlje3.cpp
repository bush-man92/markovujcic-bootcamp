#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	string lozinka = "password";
	string pokusaj = "";
	
	for (int i = 1; i <= 3; i++) {
		cout << "Unesite lozinku: " << endl;
		cin >> pokusaj;
		if (pokusaj == lozinka) {
			cout << "Tocna lozinka" << endl;
			break;
		}
		else {
			cout << "Kriva lozinka." << endl;
		}
	}
}
