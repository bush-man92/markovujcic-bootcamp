#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int U, P;
	cin >> U >> P;
	
	if (P < 30) {
		cout << 8400;
	}
	else if (P >= 30 && P < 50) {
		cout << (U - P) * 140;
	}
	else {
		cout << 0;
	}
}
