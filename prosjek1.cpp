#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	int a = 1;
	vector<int> vektor;
	int prosjek = 0;
	
	for (int i = 0; i < a;){
		cin >> a;
		vektor.push_back(a);
	}
	for (int i = 0; i < vektor.size(); i++) {
		prosjek += vektor[i];
	}
	cout << setprecision(2) << fixed << float(prosjek) / (vektor.size() - 1);
	
	return 0;
	
}
