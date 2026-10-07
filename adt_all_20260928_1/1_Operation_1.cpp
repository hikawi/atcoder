#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll x, a, d, n;
  cin >> x >> a >> d >> n;

  if (d == 0) {
    cout << abs(x - a) << endl;
    return 0;
  }

  if (d < 0) {
    a = a + d * (n - 1);
    d = -d;
  }

  ll st = a;
  ll fi = a + d * (n - 1);
  if (x <= st) {
    cout << st - x << endl;
    return 0;
  }
  if (x >= fi) {
    cout << x - fi << endl;
    return 0;
  }

  cout << min((x - a) % d, d - (x - a) % d) << endl;

  return 0;
}
