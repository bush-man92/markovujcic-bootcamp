#include <iostream>
#include <iomanip>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

int main() {
	int N = 0;
	cin >> N;
	int broj_skokova = N;
	vector<int> skokovi;
	for (int i = 0; i < N; i++) {
		int segment_skoka = 0;
		cin >> segment_skoka;
		skokovi.push_back(segment_skoka);
	}
	sort(skokovi.begin(), skokovi.end());
	int dugi_skok = 0;
	int prvi_dugi_skok = 0;
	for (int i = 0; i < N; i++) {
		if (skokovi[i] + 1 == skokovi[i + 1]) {
			if (skokovi[i] + 2 != skokovi[i + 2]) {
				broj_skokova -= 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		int privremena = 0;
		if (skokovi[i] + 1 == skokovi[i + 1]) {
			prvi_dugi_skok = skokovi[i];
			privremena = 2;
			if (skokovi[i] + 2 == skokovi[i + 2]) {
				privremena += 1;
			}
		}
		if (privremena > dugi_skok) {
			dugi_skok = privremena;
		}
	}	
	cout << broj_skokova << " " << dugi_skok << " " << prvi_dugi_skok;
}
