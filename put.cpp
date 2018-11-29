#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int A1, A2, B1, B2;
	cin >> A1 >> A2 >> B1 >> B2;
	
	if (B1 > A2 || B1 < A1) {
		cout << B1;
	}
	else if (B2 > A2 || B2 < A1) {
		cout << B2;
	}
}
