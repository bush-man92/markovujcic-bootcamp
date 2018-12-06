#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int A, B, C, x;
	cout << &A << endl << &B << endl << &C;
	
	int *polje = new int[x];
	
	if ( == x) {
		int *polje2 = new int[x + (x/2)];
		for (int i = 0; i < x; i++) {
			polje[i] = polje2[i];
		}
	}
	
	delete polje;
	polje = NULL;
	
	delete polje2;
	polje2 = NULL;
}
