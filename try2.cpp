#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float x;
	float y;
	cout << "Napisi broj x: " << endl;
	cin >> x;
	cout << "Napisi broj y: " << endl;
	cin >> y;
	cout << "x = " << x;
	cout << ", y = " << y << endl;
	cout << "Zbroj je " << x + y << endl;
	cout << "Razlika je " << x - y << endl;
	cout << "Produkt je " << x * y << endl;
	cout << "Kvocijent je " << x / y << setprecision(2) << fixed << endl;
	
	int z;
	cout << "Napisi cetveroznamenkasti broj:" << endl;
	cin >> z;
	cout << z / 1000 * 1000 << endl;
	cout << z % 1000 / 100 * 100 << endl;
	cout << z % 100 / 10 * 10 << endl;
	cout << z % 10;

	
	
	
}
