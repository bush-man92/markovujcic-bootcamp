#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	vector<int> pelud_na_putu;
	int cijeli_put = 50;

	for (int i = 0; i < 8; i++) {
		int broj_peludi = 0;
		cin >> broj_peludi;
		pelud_na_putu.push_back(broj_peludi);
	}
	int pet_cetri_devet = 50;
	int put1[2] = {pelud_na_putu[4], pelud_na_putu[3]};
	int tri_cetri_devet = 50;
	int put2[4] = {pelud_na_putu[0], pelud_na_putu[1], pelud_na_putu[2], pelud_na_putu[3]};
	int pet_sest = 50;
	int put3[4] = {pelud_na_putu[4], pelud_na_putu[5], pelud_na_putu[6], pelud_na_putu[7]};
	
	for (int i = 0; i < 8; i++) {
		cijeli_put += pelud_na_putu[i];
		if (cijeli_put < 0) {
			break;
		}
	}
	for (int i = 0; i < 2; i++) {
		pet_cetri_devet += put1[i];
		if (pet_cetri_devet < 0) {
			break;
		}
	}
	for (int i = 0; i < 4; i++) {
		tri_cetri_devet += put2[i];
		if (tri_cetri_devet < 0) {
			break;
		}
	}
	for (int i = 0; i < 4; i++) {
		pet_sest += put3[i];
		if (pet_sest < 0) {
			break;
		}
	}
	if (cijeli_put > pet_cetri_devet && cijeli_put > tri_cetri_devet && cijeli_put > pet_sest) {
		for (int i = 0; i < 10; i++) {
			cout << i << " ";
		}
		cout << endl;
		cout << cijeli_put;
	}
	else if(pet_cetri_devet > cijeli_put && pet_cetri_devet > tri_cetri_devet && pet_cetri_devet > pet_sest) {
		cout << 0 << " " << 5 << " " << 4 << " " << 9 << endl;
		cout << pet_cetri_devet;
	}
	else if(tri_cetri_devet > cijeli_put && tri_cetri_devet > pet_cetri_devet && tri_cetri_devet > pet_sest) {
		cout << 0 << " " << 1 << " " << 2 << " " << 3 << " " << 4 << " " << 9 << endl;
		cout << tri_cetri_devet;
	}
	else if(pet_sest > cijeli_put && pet_sest > tri_cetri_devet && pet_sest > pet_cetri_devet) {
		cout << 0 << " " << 5 << " " << 6 << " " << 7 << " " << 8 << " " << 9 << endl;
		cout << pet_sest;
	}
}
