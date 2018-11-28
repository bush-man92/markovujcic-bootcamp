#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int choice;
	cout << "Odaberite broj 1 za unos i ispis broja." << endl;
	cout << "Odaberite broj 2 za ispis \"Dobar dan\"" << endl;
	cout << "Odaberite broj tri za izlaz iz programa." << endl;
	cin >> choice;
	
	switch (choice) {
		case 1:
			int one;
			cout << "Unesite broj: " << endl;
			cin >> one;
			cout << one << endl;
			break;
			
		case 2:
			cout << "Dobar dan" << endl;
			break;
			
		case 3:
			break;
			
		default:
			cout << "Brate jel ti citas bre?";
	}
}
