#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string dobitak = "";
	vector<string> listici;
	
	for (int i = 0; i < 6; i++) {
		string N = "";
		cin >> N;
		dobitak += N[N.size() - 1];
	}
	
	for (int i = 0; i < 3; i++) {
		string listic;
		cin >> listic;
		listici.push_back(listic);
	}
	
	for (int j = 0; j < 3; j++){
		int counter = 0;
		for (int i = 5; i >= 0; i--) {
			if (listici[j][i] == dobitak[i]) {
				counter += 1;
			}
			else{
				break;
			}
		}
		if (counter == 6) {
			cout << "I. vrsta" << endl;
		}
		else if (counter == 5) {
			cout << "II. vrsta" << endl;
		}
		else if (counter == 4) {
			cout << "III. vrsta" << endl;
		}
		else if (counter == 3) {
			cout << "IV. vrsta" << endl;
		}
		else if (counter == 2) {
			cout << "V. vrsta" << endl;
		}
		else {
			cout << "Nedobitan" << endl;
		}
		counter = 0;
	}
}
