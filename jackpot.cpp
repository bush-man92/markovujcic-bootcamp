#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> dobitno;
	int N;
	
	for (int i = 0; i < 6; i++) {
		cin >> N;
		dobitno.push_back(N);
	}
	
	for (int i = 0; i < 6; i++) {
		dobitno[i] = dobitno[i] % 10;
		cout << dobitno[i];
	}

}
