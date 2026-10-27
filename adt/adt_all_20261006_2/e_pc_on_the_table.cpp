#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;
  vector<string> S(h);
  rep(i, h) cin >> S[i];

  bool replaced = true;

  while (replaced) {
    replaced = false;
    for (auto &s : S) {
      rep(j, s.length() - 1) {
        if (s[j] == 'T' && s[j + 1] == 'T') {
          s[j] = 'P';
          s[j + 1] = 'C';
          replaced = true;
        }
      }
    }
  }

  for (const auto &s : S)
    cout << s << "\n";

  return 0;
}
