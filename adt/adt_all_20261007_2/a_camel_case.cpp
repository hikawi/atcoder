#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  for (const auto &[i, c] : s | views::enumerate) {
    if (c >= 'A' && c <= 'Z') {
      cout << i + 1 << endl;
      return 0;
    }
  }

  return 0;
}
