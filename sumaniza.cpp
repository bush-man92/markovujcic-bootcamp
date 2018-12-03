#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int N ;
  int rezultat = 0;
  cin >> N;
  
  for (int i = 0; i < N; i++) {
  	int a;
  	cin >> a;
  	rezultat += a;
  	
  }
  cout<< rezultat;

  return 0;
}
