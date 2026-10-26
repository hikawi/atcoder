#include <iostream>
using namespace std;
using ll = long long;
int main() {
  ll a, b;
  cin >> a >> b;

  while (b) {
    a %= b;
    if (a < b)
      swap(a, b);
  }

  cout << a << endl;
}
