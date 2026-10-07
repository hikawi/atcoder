#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  unordered_map<char, vector<int>> p;
  for (auto [i, c] : s | views::enumerate)
    p[c].push_back(i);

  int bl = p['B'][0];
  int br = p['B'][1];
  if (bl % 2 == br % 2) {
    cout << "No\n";
    return 0;
  }

  int rl = p['R'][0];
  int rr = p['R'][1];
  int k = p['K'][0];
  if (k < min(rl, rr) || k > max(rl, rr)) {
    cout << "No\n";
    return 0;
  }

  cout << "Yes\n";

  return 0;
}
