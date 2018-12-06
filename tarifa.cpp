#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int mega, mjeseci, N = 0;
	cin >> mega >> mjeseci;
	
	for (int i = 0; i < mjeseci; i++) {
		int potrosnja;
		cin >> potrosnja;
		N += mega - potrosnja;
		}
	cout << N + mega;
}
