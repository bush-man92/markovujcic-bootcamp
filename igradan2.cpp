#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    int one = N / 1000;
    int two = N % 1000 / 100;
    int three = N / 10 % 10;
    int four = N % 10;
    if (one < 9) {
    	one += 1;
	}
    else if (two < 9) {
    	two += 1;
	}
	else if (three < 9) {
    	three += 1;
	}
    else if (four < 9){
    	four += 1;
	}
	cout << one * 1000 + two * 100 + three * 10 + four;
}
