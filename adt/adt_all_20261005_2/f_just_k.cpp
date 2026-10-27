#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

ll count(vector<string> &sel, int k) {
  vector<int> chars(28);
  for (const string &s : sel) {
    for (const char c : s) {
      chars[c - 'a']++;
    }
  }

  ll c = 0;
  rep(i, 28) {
    if (chars[i] != k) {
      return -1;
    }
    if (chars[i] > 0)
      c++;
  }
  return c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<string> S(n);
  rep(i, n) cin >> S[i];

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    vector<bool> mask(i, true);
    mask.resize(n, false);

    do {
      vector<string> sel;
      sel.reserve(i);
      rep(j, n) {
        if (mask[j])
          sel.push_back(S[j]);
      }

      ans = max(ans, count(sel, k));
    } while (prev_permutation(mask.begin(), mask.end()));
  }

  cout << ans << endl;

  return 0;
}
