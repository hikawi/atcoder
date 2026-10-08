#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n, k;
  cin >> n >> k;

  ll sp = 0;
  map<ll, ll> rems; // end at day I, how many pills
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    sp += b;
    rems[a] += b;
  }

  if (sp <= k) {
    cout << 1 << endl;
    return 0;
  }

  ll t = 1;
  for (const auto &[d, v] : rems) {
    // stop v pills on this day.
    if (sp - v <= k) {
      t = d + 1;
      break;
    }

    sp -= v;
  }

  cout << t << endl;

  return 0;
}
