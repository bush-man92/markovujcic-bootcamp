#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  int N ;
  int rezultat;
  cin>> N;
  
  for (int i = 0; i < N; i++) {
  	int a;
  	cin>>a;
  	rezultat += a;
  	
  }
  cout<< rezultat;

  return 0;
}
