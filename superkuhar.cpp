#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	int edi = 0;
	int tin = 0;
	
	for (int i = 1; i <= 18; i++) {
		int N;
		cin >> N;
		if (i <= 9) {
			edi += N;
		}
		else {
			tin += N;
		}
	}
	if (edi > tin) {
		cout << "Edi " << edi;
	}
	else if (tin > edi) {
		cout << "Tin " << tin;
	}
	else {
		cout << "Nema pobjednika " << edi;
	}
}
