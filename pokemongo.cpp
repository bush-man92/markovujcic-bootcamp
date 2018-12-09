#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	int evolucije_ukupno = 0;
	int evolucija_maximalna = 0;
	string name_max = "";
	int N = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int evolucija_trenutna = 0;
		string name = "";
		cin >> name;
		int K = 0;
		cin >> K;
		int M = 0;
		cin >> M;
		while (M >= K) {
			evolucije_ukupno += 1;
			evolucija_trenutna += 1;
			M -= K;
			M += 2;
		}
		if (evolucija_trenutna > evolucija_maximalna) {
			evolucija_maximalna = evolucija_trenutna;
			name_max = name;
		}
	}
	
	cout << evolucije_ukupno << endl;
	cout << name_max;
}

