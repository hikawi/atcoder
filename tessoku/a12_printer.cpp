#include <iostream>
#include <vector>
using ll = long long;

int main() {
  using namespace std;
  ll n, k;
  cin >> n >> k;
  vector<ll> A(n);
  for (int i = 0; i < n; i++)
    cin >> A[i];

  ll l = 1, r = 1000000000;
  while (l < r) {
    ll m = (l + r) / 2;

    // count how many printed
    ll p = 0;
    for (auto a : A)
      p += m / a;

    if (p < k)
      l = m + 1;
    else
      r = m;
  }

  cout << l << "\n";
}
