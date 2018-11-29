#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	int num, num2;
    do {
    	cin >> num >> num2;
    	cout << num + num2 << endl;
	} while (num != 0 && num2 != 0);
}
