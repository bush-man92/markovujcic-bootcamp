#include <iostream>
#include <iomanip>

using namespace std;

void zamjena(int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 1;
	int b = 3;
	cout << a << endl << b << endl;
	zamjena(a, b);
	cout << a << endl << b << endl;
}
