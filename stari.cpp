#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	bool stanje = true;
	vector<int> krajnji_brojevi;
	for (int i = 0; i < N; i++) {
		vector<int> brojevi;
		string ulaz;
		cin >> ulaz;
		for (int j = 0; j < ulaz.length(); j++) {
			char a = ulaz[j];
			int x = a - '0';
			brojevi.push_back(x);	
		}
		sort(brojevi.begin(), brojevi.end());
		krajnji_brojevi.push_back(brojevi[0]);
	}
	for(int i = 0; i < krajnji_brojevi.size(); i++) {
		if(krajnji_brojevi[i]>0 && stanje) {
			cout << krajnji_brojevi[i];	
			stanje=false;
		}
		else if(stanje==false){
			cout << krajnji_brojevi[i];	
		}
	}
}
