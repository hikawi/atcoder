#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m, k;
  cin >> n >> m >> k;
  vector<pair<int, bool>> cases(m);

  rep(i, m) {
    int cur = 0;
    char c;
    int l;
    cin >> l;
    rep(li, l) {
      int a;
      cin >> a;
      cur |= 1 << (a - 1);
    }

    cin >> c;
    cases[i] = make_pair(cur, c == 'o');
  }

  ll s = 0;
  rep(i, 1 << n) {
    int a = 1;
    for (const auto &[c, res] : cases) {
      auto r = __builtin_popcount(c & i);
      if (res && r < k)
        a = 0;
      if (!res && r >= k)
        a = 0;
    }
    s += a;
  }

  cout << s << endl;

  return 0;
}
