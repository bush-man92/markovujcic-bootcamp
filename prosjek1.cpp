#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int a = 1;
	int prosjek = 0;
	int counter = 0;
	bool cheker = false;
	
	for (int i = 0; i < a;){
		cin >> a;
		if (a == 1) {
			cheker = true;
		}
		counter += 1;
		prosjek += a;
	}
	if (cheker == false) {
		cout << setprecision(2) << fixed << float(prosjek) / (counter - 1);
	}
	else {
		cout << 1;
	}
}
