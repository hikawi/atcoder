#include <iostream>
using namespace std;
int main() {
  int mod = 1000000007;
  int n;
  cin >> n;
  int a = 1, b = 1, c = 2;
  for (int i = 4; i <= n; i++) {
    a = b;
    b = c;
    c = (a + b) % mod;
  }
  cout << c << endl;
}
