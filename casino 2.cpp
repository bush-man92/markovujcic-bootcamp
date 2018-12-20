#include <iostream>
#include <vector>
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h> 
#include <iomanip>
#include <cmath>
#include <string>


using namespace std;
int pare;
int chip;
string ime;

void menu(int & pare, int &chip);
void uplata(int & pare, int& chip);
void korisnik(int & pare, string & ime);
void isplata(int & pare ,int &chip);
void isplata(int & pare, int &chip);
void slot(int & pare, int & chip);
void menu2(int &pare,int&chip);


void menu(int & pare, int &chip) {
	system("cls");
	cout << "pritsnite 1 za uplatu chipova" << endl << "pritisnite 2 za isplatu chipova" << endl<<"pritisnite 3 za igirice"<<endl;
	int a;
	cin >> a;
	if (a == 1) {
		uplata(pare,  chip);
	}
	else if (a == 2) {

		isplata(pare,  chip);


	}
	else if (a==3){
	
	slot(pare,chip);
	}


}

void menu2(int &pare,int&chip){

}


void korisnik(int & pare, string & ime) {
	system("cls");
	cout << "DOBRODOSLI U CASINO SMOKEY" << endl;
	cout << "unesite vase ime" << endl;
	cin >> ime;
	cout << "unesite vase pare" << endl;
	cin >> pare;
}



void uplata(int & pare,  int &chip) {
	system("cls");
	cout << "iznos vasih para je" << '\t' << pare << endl;
	cout << "koliko para zelite ulozit" << endl;
	int ulog = 0;
	cin >> ulog;
	chip += ulog / 5;
	if (pare - ulog < 0) {
		ulog = 0;
		uplata(pare,  chip);
	}
	else {
		pare -= ulog;

		cout << "iznos vasih chipova je" << '\t' << chip << endl;
		cout << "ostalo vam je " << pare  << " para" << endl;
	}
	cout << "pritisnite 3 za natrag na menu" << endl;

	int b;
	cin >> b;
	if (b == 3) {
		menu(pare, chip);
	}
}



void isplata(int & pare,  int &chip) {
	system("cls");
	cout << "iznos vasih chipova je" << '\t' << chip << endl;
	int ulog = 0;
	chip = ulog * 5;
   
	cout << "dali zelite isplatiti sve cipove pritisnite 1 za da" << endl<<" pritisnite 2 za natrag na menu" << endl;
	int a;
	cin >> a;
	if (a == 1) {
		cout  << "para na racunu jos imate" << '\t' << pare << endl;

	}
	if (a == 2) {
		menu(chip,  pare);
	}
}
void slot(int & pare, int & chip) {

	srand(time(NULL));
	cout << chip<<endl;
    char polje [4] = {'+','*','X','O'};
    int provjera [3][4];
    bool pobjeda = false;
    int counter = 0;
    
	
    for (int i = 0; i<3; i++){
    		for (int j = 0; j<4; j++){
    			int A = rand() % 4;
    			provjera[i][j] = A;
    			cout<<polje [A] << "\t" ;
    		}
    	cout << endl;
    	
	}

	for (int i=0;  i < 1; i++){
		
		for (int j=0; j < 4; j++){
			if (provjera [j][i] == provjera [j][i + 1] && provjera[j][i] == provjera[j][i + 2] && provjera[j][i] == provjera[j][i + 3]){
				pobjeda = true;
				counter += 1;
				cout << "pobjeda u " << j << " vodoravno" << endl;
			}
		}
		for (int k = 0; k < 4; k++) {
			if (provjera[i][k] == provjera[i + 1][k] && provjera[i][k] == provjera[i + 2][k]){
				pobjeda = true;
				counter += 1;
				cout << "pobjeda u " << k << " okomito" << endl;
			}
		}
	}
	for (int i=0; i<3; i++){
	
		for(int j=0; j<4; j++){
		
	}
	}
	if (pobjeda == true && counter == 1) {
		cout << "pobjeda"<<endl;
		chip +=5;
	}
	else if (pobjeda == true && counter == 2){
		cout << "double" <<endl;
	chip +=25;
	}
	else if (pobjeda ==  true && counter == 3) {
		cout << "triple KILL" <<endl;
		chip +=100;
	}
	else if (pobjeda == true && counter >= 4) {
		cout << "JACKPOT" <<endl;
	 chip +=1000;
	}
	else {
		cout << "loser" <<endl;
		chip -=1;
	}
	cout << chip << endl;
	cout<<"pritisnite 1 za slot " <<endl<<"pritisnite 2 za natrag na menu"<<endl;
	counter = 0;
	int a;
	cin>>a;
	if (a==1){
		system("cls");
		slot(pare,chip);
	}
	else if (a==2){
		menu(pare,chip);
	}
}
	
	

int main() {
	korisnik(pare, ime);
	menu (pare, chip);




}
