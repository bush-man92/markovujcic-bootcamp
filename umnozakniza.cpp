#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int a;
	int b= 1;
	int umnozak = 1 ;
	cin>> a;
	for (int i = 0; i< a; i++)
	{
		
		cin>>b;
		
		umnozak*=b;
		
		
	}
	
	cout<< umnozak;
}
