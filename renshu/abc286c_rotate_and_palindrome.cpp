#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll n, a, b;
  cin >> n >> a >> b;

  string st;
  cin >> st;
  st += st;

  ll ans = LONG_LONG_MAX;
  rep(i, n) {
    // rotate i times
    ll costa = a * i;
    ll costb = 0;
    string cur = st.substr(i, n);
    for (ll l = 0; l < cur.length() / 2; l++) {
      if (cur[l] != cur[cur.length() - l - 1])
        costb += b;
    }
    // for (ll l = i; l < (i + (i + n)) / 2; l++) {
    //   ll r = i + n - l;
    //   if (st[l] != st[r])
    //     costb += b;
    // }
    ans = min(costa + costb, ans);
  }
  cout << ans << "\n";

  return 0;
}
