#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int q;
  cin >> q;
  ll n = 1048576;

  vector<ll> A(n, -1);
  set<ll> S;
  rep(i, n) S.insert(i);

  rep(i, q) {
    ll t, x;
    cin >> t >> x;

    if (t == 2) {
      cout << A[x % n] << endl;
      continue;
    }

    ll h = x % n;
    auto it = S.lower_bound(h);
    if (it != S.end()) {
      A[*it] = x;
      S.erase(it);
    } else {
      A[*S.begin()] = x;
      S.erase(S.begin());
    }
  }
}
