#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];

  ll M = 0;
  for (ll l = 0; l < n; l++) {
    ll x = A[l];
    for (ll r = l; r < n; r++) {
      x = min(x, A[r]);
      M = max(M, x * (r - l + 1));
    }
  }

  cout << M << endl;

  return 0;
}
