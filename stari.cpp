#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> krajnji_brojevi;
	for (int i = 0; i < N; i++) {
		vector<int> brojevi;
		string ulaz;
		cin >> ulaz;
		for (int j = 0; j < ulaz.length(); j++) {
			char a = ulaz[j];
			if (i == 0 && a == '0') {
				break;
			}
			int x = a - '0';
			brojevi.push_back(x);
		}
		sort(brojevi.begin(), brojevi.end());
		krajnji_brojevi.push_back(brojevi[0]);
	}
	for(int i = 0; i < krajnji_brojevi.size(); i++) {
		cout << krajnji_brojevi[i];
	}
}
