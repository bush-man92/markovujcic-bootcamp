#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;
	
	if (A + B + C + D + E == F) {
		cout << A << '+' << B << '+' << C << '+' << D << '+' << E << '=' << F;
	}
	else if (A - B - C - D - E == F) {
		cout << A << '-' << B << '-' << C << '-' << D << '-' << E << '=' << F;
	}
	else if (A * B * C * D * E == F) {
		cout << A << '*' << B << '*' << C << '*' << D << '*' << E << '=' << F;
	}
	else if (A / B / C / D / E == F) {
		cout << A << '/' << B << '/' << C << '/' << D << '/' << E << '=' << F;
	}
}
