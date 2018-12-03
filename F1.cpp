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

	int bolid1, bolid2;
	cin >> bolid1 >> bolid2;
	cout << vektor[vektor.size() - bolid2] - vektor[vektor.size() - bolid1];
}
