#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	int a = 1;
	int prosjek = 0;
	int counter = 0;
	
	for (int i = 0; i < a;){
		cin >> a;
		counter += 1;
		prosjek += a;
	}
	
	cout << setprecision(2) << fixed << float(prosjek) / (counter - 1);
	
	return 0;
	
}
