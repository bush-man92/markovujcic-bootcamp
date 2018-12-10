#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int osvojeni_iznos = 0;
	int igraci = 100;

	for (int i = 0; i < 1;) {
		int novac = 100000 / igraci;
		char odgovor = ' ';
		int ispali = 0;
		cin >> odgovor >> ispali;
		if (odgovor == 'T') {
			igraci -= ispali;
			osvojeni_iznos += novac * ispali;
		}
		else if(odgovor == 'P') {
			igraci -= ispali;
		}
		else if (odgovor == 'F') {
			osvojeni_iznos = 0;
			break;
		}
		if (igraci == 0) {
			break;
		}
	}
	cout << osvojeni_iznos << endl;
}
