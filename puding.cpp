#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int N, A, B, C, D, E;
	cin >> N >> A >> B >> C >> D >> E;
	N = N - (A * 0.5) - (0.5 * B) - (0.5 * C);
	if (N >= (D * 0.5)) {
		cout << "PUDING OD COKOLADE";
	}
	else {
		cout << "PUDING OD VANILIJE";
	}
}
