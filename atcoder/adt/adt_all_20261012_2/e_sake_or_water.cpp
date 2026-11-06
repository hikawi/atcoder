#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n, k, x;
  cin >> n >> k >> x;
  vector<ll> A(n), S(n + 1);
  rep(i, n) cin >> A[i];
  sort(A.begin(), A.end());
  partial_sum(A.begin(), A.end(), S.begin() + 1);

  for (int i = 1; i <= n; i++) {
    // we take i max cups, so leftovers are n - i
    // there are k sake cups, so at least, we would have taken max(k - (n - i), 0) cups.
    // if taken = 0 then welp.
    ll taken = max(k - (n - i), 0ll);
    if (taken == 0)
      continue;
    ll sake = S[n - i + taken] - S[n - i];
    if (sake >= x) {
      cout << i << "\n";
      return 0;
    }
  }

  cout << -1 << "\n";
  return 0;
}
