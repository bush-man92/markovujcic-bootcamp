#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main () {
    float A, B, C, D, E;
    cin >> A >> B >> C >> D >> E;
    float zbr = A + B + C + D + E;
    float xi = zbr / 5;
    float dev = sqrt(0.2 * (pow(A - xi, 2) + pow(B -xi, 2) + pow(C -xi, 2) + pow(D - xi, 2) + pow(E - xi, 2)));
    cout << setprecision(2) << fixed << xi << endl;
    cout << setprecision(2) << fixed << dev;
    return 0;
}
