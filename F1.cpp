#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main (){
	float S = 1;
	vector<float> vektor;
	
	for (int i = 0; S > i;) {
		cin >> S;
		vektor.push_back(S);
	}

	float bolid1, bolid2;
	cin >> bolid1 >> bolid2;
	float A = float(vektor[vektor.size() - bolid2]) - vektor[vektor.size() - bolid1];
	if ( A == 10) {
		cout << setprecision(1) << fixed << A;
	}
	else {
		cout << A;
	}
}
