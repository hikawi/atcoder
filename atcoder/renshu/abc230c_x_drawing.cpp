#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n, a, b, p, q, r, s;
  cin >> n >> a >> b >> p >> q >> r >> s;

  for (ll y = p; y <= q; y++) {
    for (ll x = r; x <= s; x++) {
      if (abs(x - b) == abs(y - a))
        cout << '#';
      else
        cout << '.';
    }
    cout << "\n";
  }

  return 0;
}
