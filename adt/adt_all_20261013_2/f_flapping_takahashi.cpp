#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  rep(ti, T) {
    ll n, h;
    cin >> n >> h;
    ll t = 0;
    ll minh = h, maxh = h;

    bool flag = true;
    rep(ni, n) {
      ll ts, l, u;
      cin >> ts >> l >> u;
      ll dt = ts - t;

      ll lowest = max(1ll, minh - dt);
      ll highest = maxh + dt;

      if (highest < l || lowest > u) {
        flag = false;
      }

      // it can reach.
      minh = max(lowest, l);
      maxh = min(highest, u);
      t = ts;
    }

    if (flag)
      cout << "Yes\n";
    else
      cout << "No\n";
  }

  return 0;
}
