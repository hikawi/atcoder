#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll d;
  cin >> d;

  ll ans = d;
  for (ll x = 0; x <= 2000000; x++) {
    ll c = d - x * x;
    if (c <= 0) {
      // y = 0
      ans = min(ans, -c);
    } else {
      ll y = sqrt(c);
      ans = min(ans, abs(x * x + y * y - d));
      y++;
      ans = min(ans, abs(x * x + y * y - d));
    }
  }
  cout << ans << "\n";

  return 0;
}
