#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
	int zbroj = 0, broj = 0;
    do {
    	cin >> broj;
    	zbroj += broj;
    	cout << zbroj << endl;
	} while (broj != 0);
}
