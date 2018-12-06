#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	int N = 0;
	cin >> N;
	vector<char> karte;
	int zbroj = 0;
	for (int i = 0; i < N * 13; i++) {
		char A = ' ';
		cin >> A;
		karte.push_back(A);
	}
	for (int i = 0; i < N * 13; i++) {
		if (karte[i] == 'A') {
			zbroj += 4;
		}
		else if (karte[i] == 'K') {
			zbroj += 3;
		}
		else if (karte[i] == 'Q') {
			zbroj += 2;
		}
		else if (karte[i] == 'J') {
			zbroj += 1;
		}
		else {
			continue;
		}
	}
	cout << zbroj;
}
