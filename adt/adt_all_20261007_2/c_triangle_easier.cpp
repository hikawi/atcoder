#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  unordered_map<int, unordered_set<int>> adjl;
  rep(i, m) {
    int u, v;
    cin >> u >> v;
    adjl[u].insert(v);
    adjl[v].insert(u);
  }

  int s = 0;
  for (int a = 1; a <= n; a++) {
    for (int b = a + 1; b <= n; b++) {
      for (int c = b + 1; c <= n; c++) {
        if (adjl[a].count(b) && adjl[b].count(c) && adjl[a].count(c)) {
          s++;
        }
      }
    }
  }

  cout << s << endl;

  return 0;
}
