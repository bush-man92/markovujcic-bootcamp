#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int N;
	cin >> N;
	int counter = 0;
	
	for (int i = 1; i <= N; i++) {
		int B;
		cin >> B;
		if (B >= i) {
			counter += 1;
		}
	}
	
	cout << counter;
	
}
