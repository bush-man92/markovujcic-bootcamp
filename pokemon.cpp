#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> pokemoni;
	vector<int> slatko;
	for (int i = 0; i < N; i++) {
		string pokemon = "";
		cin >> pokemon;
		pokemoni.push_back(pokemon);
		for (int j = 0; j < N; j++) {
			int Ki, Mi;
			cin >> Ki >> Mi;
			slatko.push_back(Ki);
			slatko.push_back(Mi);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N * 2; j+=2) {
			cout << pokemoni[i] << endl;
			cout << slatko[j] << '\t' << slatko[j+1];
		}
	}
	return 0;
} 
