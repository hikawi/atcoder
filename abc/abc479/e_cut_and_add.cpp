#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

vector<unordered_set<int>> adj;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  adj = vector<unordered_set<int>>(n);

  vector<pair<int, int>> edges(n - 1);
  vector<int> v(n, n * (n - 1) / 2);

  for (int i = 0; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a - 1].insert(b - 1);
    adj[b - 1].insert(a - 1);
    edges[i] = pair(a - 1, b - 1);
  }

  for (int i = 0; i < n - 1; i++) {
    auto &[a, b] = edges[i];

    // isolated tree
    if (adj[a].size() == 1) {
      v[a] -= i + 1;
    } else if (adj[b].size() == 1) {
      v[b] -= i + 1;
    } else {
      // find connected comps from a & b?
      // welp
    }
  }

  for (const auto p : v)
    cout << p << " ";
  cout << "\n";

  return 0;
}
