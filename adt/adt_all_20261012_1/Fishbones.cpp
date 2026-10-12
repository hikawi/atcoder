#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<pair<int, int>> A(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    A[i] = pair(a, b);
  }

  int m;
  cin >> m;
  vector<string> B(m);

  // length -> (char -> indices)
  unordered_map<int, unordered_map<char, unordered_set<int>>> idx;
  rep(i, m) {
    cin >> B[i];
    int len = B[i].size();
    for (const auto &[j, c] : B[i] | views::enumerate) {
      idx[len][c].insert(j + 1);
    }
  }

  for (int j = 0; j < m; j++) {
    if (B[j].length() != n) {
      cout << "No\n";
      continue;
    }

    bool ans = true;
    for (int i = 0; i < n; i++) {
      auto &[a, b] = A[i];

      // is there a string that has length a?
      // AND its s[b-1] == B[j][i]
      if (!idx.contains(a)) {
        ans = false; // no string of that length, impossible
        break;
      }

      // amongst those strings, is there a mapping B[j][i] to a set that contains b?
      if (!idx[a][B[j][i]].contains(b)) {
        ans = false; // no, impossible
        break;
      }
    }

    cout << (ans ? "Yes\n" : "No\n");
  }

  return 0;
}
