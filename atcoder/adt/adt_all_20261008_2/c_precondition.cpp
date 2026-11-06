#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  string t;
  cin >> s >> t;

  for (const auto &[i, c] : s | views::enumerate | views::drop(1) |
                                views::filter([](const auto p) { return get<1>(p) >= 'A' && get<1>(p) <= 'Z'; })) {
    if (!t.contains(s[i - 1])) {
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";

  return 0;
}
