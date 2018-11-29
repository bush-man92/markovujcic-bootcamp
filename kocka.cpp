#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int M, S;
	cout << "Kocka je bacena.." << endl;
	cin >> M >> S;
	
	if (M <= 3) {
		M = 7 - M;
	}
	if (S <= 3) {
		S = 7 - S;
	}
	
	cout << M << endl << S << endl;
	
	if (M < S) {
		cout << "Slavko" << endl;
	}
	else if (M > S) {
		cout << "Mirko" << endl;
	}
	else if (M == S) {
		cout << "Nerijeseno" << endl;
	}
}
