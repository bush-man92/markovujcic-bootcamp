#include <iomanip>
#include <iostream>

using namespace std;

int main() {
	int a = 5;
	cout << &a;
	int *p_a = &a;
	cout << "a = " << a << endl;
	cout << "p_a = " << p_a << endl;
	cout << "&a = " << &a << endl;
	cout << "*p_a = " << *p_a << endl;
	
	/*int *p_x = new int;
	*p_x = 10;
	cout << "Na adresi " << p_x << "upisana je vrijednost " << *p_x << endl;
	delete p_x;
	p_x = nullptr;*/
	
	int x;
	cout << "Unesite velicinu polja: ";
	cin >> x;
	
	int *polje = new int[x];
	
	for (int i = 0; i < x; i++) {
		cout << "Polje " << i << ": ";
		cout << polje[i];
	}
	
	delete polje;
	polje = NULL;
}
