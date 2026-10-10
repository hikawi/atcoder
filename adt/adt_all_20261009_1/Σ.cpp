#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n, k;
  cin >> n >> k;
  set<ll> A;

  ll total = k * (k + 1) / 2;
  rep(i, n) {
    ll a;
    cin >> a;
    if (A.find(a) == A.end()) {
      A.insert(a);
      if (a <= k)
        total -= a;
    }
  }

  cout << total << endl;

  return 0;
}
