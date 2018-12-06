#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	int N, X;
	vector<int> suma;
	cin >> N >> X;
	int zbroj = 0;
	for (int i = 0; i < N; i++) {
		int P1, P2;
		cin >> P1 >> P2;
		if (P1 > P2) {
			if (P1 - P2 <= X) {
				suma.push_back(P1);
			}
			else if (P1 - P2 > X) {
				int P3;
				cin >> P3;
				suma.push_back(P3);
			}
		}
		else {
			if (P2 - P1 <= X) {
				suma.push_back(P2);
			}
			else if (P2 - P1 > X) {
				int P3;
				cin >> P3;
				suma.push_back(P3);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		zbroj += suma[i];
	}
	cout << zbroj;
}
