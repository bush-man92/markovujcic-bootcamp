#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float a;
	float b;
	cin >> a;
	cin >> b;
	{
		cout << (a += b) << endl;
	}
	{
		cout << (a -= b) << endl;
	}
	{
		cout << (a *= b) << endl;
	}
	{
		cout << (a /= b) << endl;
	}
}
