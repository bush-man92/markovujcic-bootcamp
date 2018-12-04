#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N = 1;
	cin >> N;
	vector<string> pokemoni;
	vector<int> slatko;
	vector<int> slatko2;
	int najveci[N];
	int evolve = 0;
	for (int i = 0; i < N; i++) {
		string pokemon = "";
		int y = 0;
		cin >> pokemon;
		pokemoni.push_back(pokemon);
		int Ki, Mi;
		cin >> Ki >> Mi;
		y = Mi / Ki;
		Mi += y * 2;
		slatko.push_back(Ki);
		slatko2.push_back(Mi);
	}
	for (int i = 0; i < N; i++) {
		int x = 0;
		x = slatko2[i] / slatko[i];
		evolve += x;
		najveci[i] = x;
	}
	cout << evolve << endl;
	for (int i = 0; i < N; i++) {
		if (najveci[i] == *max_element(najveci, najveci + N)) {
			cout << pokemoni[i] << i;
			break;
		}
	}
}
