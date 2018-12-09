#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	int sat = 0, minuta = 0, N;
	cin >> sat >> minuta >> N;
	int najveca_temp = 0;
	int vrijeme_najvece = 0;
	for (int i = 1; i < N + 1; i++) {
		int temperatura = 0;
		cin >> temperatura;
		if (temperatura > najveca_temp) {
			najveca_temp = temperatura;
			vrijeme_najvece = i;
		}
	}
	for (int i = 0; i < vrijeme_najvece;) {
		minuta += 30;
		vrijeme_najvece -= 1;
		}
	for (int i = 59; i < minuta;) {
		sat += minuta / 60;
		minuta = minuta % 60;
	}
	cout << najveca_temp << endl;
	cout << sat << endl;
	cout << minuta;
}
