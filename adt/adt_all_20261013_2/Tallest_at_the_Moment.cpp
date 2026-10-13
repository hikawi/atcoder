#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<ll> H(n + 1), T(n + 1);
  rep(ni, n) cin >> H[ni + 1] >> T[ni + 1];

  for (int i = n - 1; i >= 0; i--)
    H[i] = max(H[i], H[i + 1]);

  int q;
  cin >> q;
  rep(qi, q) {
    ll t;
    cin >> t;

    auto it = upper_bound(T.begin(), T.end(), t);
    cout << H[it - T.begin()] << "\n";
  }

  return 0;
}
