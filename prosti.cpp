#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	int a;
	cin>>a;
	bool provjera = false;
	
	if (a % 2 == 0) {
		provjera = false;
	}
	else {
		for (int i = 2; i < 100; i++)
		{
			if (a % i == 0)
			{
				provjera = false;
				break;
			}
			else
			{
				provjera = true;
			}
		}
	}
	if (provjera == true) {
		cout << "prost";
	}
	else {
		cout << "nije prost";
	}
}
	
    

