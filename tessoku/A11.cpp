#include <iostream>
#include <vector>
int main() {
  using namespace std;
  using ll = long long;
  ll n, x;
  cin >> n >> x;
  vector<ll> A(n);
  for (auto &&a : A)
    cin >> a;

  ll l = 0, r = n - 1;
  while (l < r) {
    ll m = (l + r) / 2;
    if (A[m] < x) {
      l = m + 1;
    } else if (A[m] == x) {
      l = m;
      break;
    } else {
      r = m - 1;
    }
  }
  cout << l + 1 << "\n";
}
