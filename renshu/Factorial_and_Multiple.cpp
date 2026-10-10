#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

map<ll, int> factorize(int n) {
  map<ll, int> factors;
  while (n % 2 == 0) {
    factors[2]++;
    n = n / 2;
  }
  for (int i = 3; i * i <= n; i = i + 2) {
    while (n % i == 0) {
      factors[i]++;
      n = n / i;
    }
  }
  if (n > 2)
    factors[n]++;
  return factors;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;

  auto factors = factorize(n);
  if (factors.empty()) {
    cout << n << "\n";
    return 0;
  }

  for (const auto &p : factors) {
    // find minimum n so that n! covers p.first ^ p.second
  }

  return 0;
}
