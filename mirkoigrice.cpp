#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int A0, B0, AC1, AC2, BC1, BC2;
	cin >> A0 >> B0 >> AC1 >> AC2 >> BC1 >> BC2;
	
	if (A0 > B0) {
		if (AC1 > AC2) {
			cout << AC2;
		}
		else {
			cout << AC1;
		}
	}
	else {
		if (BC1 > BC2) {
			cout << BC2;
		}
		else {
			cout << BC1;
		}
	}
}
