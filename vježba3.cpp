#include <iostream>
#include <string>

using namespace std;

int main()
{
	/*string s = "";
	getline(cin, s);
	cout << s << endl;*/
	
	string one = "welcome";
	string two = "w3resource";
	
	cout << "velicina stringa jedan je " << one.size() << endl;
	cout << "velicina stringa dva je " << two.size() << endl;
	
	cout << "na poziciji tri je " << one.at(3) << endl;
	cout << "na poziciji tri je " << two.at(3) << endl;
	
	cout << one.empty() << endl;
	cout << two.empty() << endl;
	
	cout << one.substr(3) << endl;
	cout << two.substr(3, 4) << endl;
	
	cout << one.replace(3, 4, "went") << endl;
	
	cout << one.append("einz") << endl;
	cout << two.append("einz") << endl;
	
	cout << one.insert(3, "ubacivanje") << endl;
	cout << two.insert(3, "ubacivanje") << endl;
	
	string rec = "";
	getline(cin, rec);
	cout << rec << endl;
}
