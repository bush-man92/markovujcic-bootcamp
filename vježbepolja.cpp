#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	int polje[10][10];
	
	for (int i = 1; i <= 10; i++){
		for (int j = 1; j <= 10; j++){
			polje[i - 1][j - 1] = i * j;
		}
	}
	
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cout << polje[i - 1][j - 1] << '\t';
		}
		cout << endl;
	}
	
	/*int polje2[2][2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++){
				cin >> i >> j >> k;
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++){
				cout << "test[" << i << "]" << "[" << j << "]" << "[" << k << "]" << endl;
			}
		}
	}*/
	
	char polje3[3][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == j || i + j == 2) {
				polje3[i][j] = 'X';
			}
			else {
				polje3[i][j] = 'O';
			}
			
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << polje3[i][j] << '\t';
		}
		cout << endl;
	}
	
	vector <vector <int> > v;
	int x;
	
	for (int i = 0; i < 2; i++) {
		vector <int> temp;
		for (int j = 0; j < 2; j++) {
			cin >> x;
			temp.push_back(x);
		}
		v.push_back(temp);
	}
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cout << v[i][j] << '\t';
		}
	}
}
