#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  unordered_map<char, int> a;
  for (const char c : s)
    a[c]++;

  for (const auto &[k, v] : a)
    if (v == 1)
      cout << k << "\n";

  return 0;
}
