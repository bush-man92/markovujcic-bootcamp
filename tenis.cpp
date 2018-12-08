#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
	int A_gem, B_gem, N;
	cin >> A_gem >> B_gem;
	cin >> N;
	vector<char> points;
	int A_points = 0, B_points = 0;
	for (int i = 0; i < N; i++) {
		char point = ' ';
		cin >> point;
		points.push_back(point);
	}
	for (int i = 0; i < N; i++) {
		if (points[i] == 'A') {
			A_points += 15;
		}
		else if (points[i] == 'B') {
			B_points += 15;
		}
	}
	if (A_points == 45) {
		A_points = 40;
	}
	else if (B_points == 45) {
		B_points = 40;
	}
	if (A_points - B_points == 30) {
		A_gem += 1;
		A_points = 0;
		B_points = 0;
	}
	else if (B_points - A_points == 30) {
		B_gem += 1;
		A_points = 0;
		B_points = 0;
	}
	if (A_points <= 40 && B_points <= 40) {
		cout << A_gem << ':' << B_gem << " " << A_points << ':' << B_points;
	}
	else if(A_points > 40 && A_points - B_points == 15) {
		cout << A_gem << ':' << B_gem << " " << "AD-A";
	}
	else if(B_points > 40 && B_points - A_points == 15) {
		cout << A_gem << ':' << B_gem << " " << "AD-B";
	}
	else if(A_points > 40 && B_points > 40 && A_points - B_points == 0) {
		cout << A_gem << ':' << B_gem << " " << "deuce";
	}
}
