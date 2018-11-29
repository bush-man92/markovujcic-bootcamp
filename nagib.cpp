#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    if (N/100 < N % 10) {
    	cout << "DESNI NAGIB";
	}
	else if (N/100 > N % 10) {
		cout << "LIJEVI NAGIB";
	}
	else {
		cout << "RAVNOTEZA";
	} }
