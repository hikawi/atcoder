#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;
  unordered_set<char> S;
  bool upper = false, lower = false;

  for (auto c : s) {
    if (S.find(c) != S.end()) {
      cout << "No\n";
      return 0;
    }

    S.insert(c);
    if (c >= 'A' && c <= 'Z')
      upper = true;
    if (c >= 'a' && c <= 'z')
      lower = true;
  }

  if (upper && lower)
    cout << "Yes\n";
  else
    cout << "No\n";

  return 0;
}
