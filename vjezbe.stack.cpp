#include <iostream>
#include <iomanip>
#include <stack>
#include <string>

using namespace std;

int main () {
	stack <char> palindrom;
	string rijec = "";
	cin >> rijec;
	bool pal = true;
	for (int i = 0; i < rijec.length(); i++) {
		palindrom.push(rijec[i]);
	}
	for (int i = 0; i < rijec.length(); i++, palindrom.pop()) {
		if (rijec[i] != palindrom.top()) {
			pal = false;
			break;
		}
	}
	if (pal) {
		cout << "rijec je palindrom";
	}
	else{
		cout << "rijec nije palindrom";
	}
}
