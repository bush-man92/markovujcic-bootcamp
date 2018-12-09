#include <iostream>
#include <vector>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include <iomanip>
#include <cmath>


using namespace std;
struct iznos {
	int pare;
};

void kockica(int &pare) {

	int a;


	cout << "vas iznos je" << '\t' << pare << endl;
	int player1;
	int player2;

	do {


		srand(time(NULL));


		player1 = rand() % 6 + 1;
		cout << '\n' << player1 << endl;
		player2 = rand() % 6 + 1;
		cout << '\n' << player2 << endl;

		if (player1 > player2) {
			cout << '\n' << "pobjedili ste" << endl;
			cout << '\n' << "vas izons je " << '\t' << pare + 50 << endl;

		}
		else if (player1 < player2) {

			cout << '\n' << "izgubili ste" << endl;
			cout << '\n' << "vas iznos je" << '\t' << pare - 50 << endl;

		}
		else {
			cout << '\n' << "nerjeseno" << endl;

		}
		cout << "pristine 1 za nastavak igre" << endl;
		cout << "pristine 2 za prekid igre" << endl;
		cin >> a;
	}

	while (a == 1); {

	}





} 
void slot () {


int korisnik;
do{
srand(time(NULL));
int a =rand()  %4+1;;
int b =rand()  %4+1;;
int c =rand() %4+1;;
int d =rand() %4+1;;


	


	cout<<a;
	cout<<b;
	cout<<c;
	cout<<d;

if(a == b && a == c && a == d){
	cout<<"pobjedili ste"<<endl;
}
else {
	cout<<"igubili ste"<<endl;
}
	cout<<"pritsnite 1 za nastavak"<<endl;
	cout<<"pritsnite 2 za izlazak"<<endl;
    cin>>korisnik;
}
while (korisnik==1);{
}
}


int main()
{
	slot ();
	/*
	iznos iznos1;
	kockica(iznos1.pare=1000);
	
	iznos iznos1;
	cout << iznos1.pare;
	cout << "dobrodosli u casino" << endl;
	cout << "unesite vas iznos" << endl;
	cout << "pritisnite 1 za bacanje kockica" << endl;
	*/
}
