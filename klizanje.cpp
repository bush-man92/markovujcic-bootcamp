#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int N, M, A, B;
	cin >> N >> M >> A >> B;
	
	if (N + M >= A + B) {
		cout << A + B;
	}
	else if (N + M < A + B) {
		cout << N + M;
	}
}
