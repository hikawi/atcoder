#include <iostream>
#include <utility>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
  while (b) {
    a %= b;
    if (a < b)
      swap(a, b);
  }
  return a;
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << (a * b) / gcd(a, b) << endl;
}
