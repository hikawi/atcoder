#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

vector<vector<int>> adj;
vector<bool> black;
vector<bool> visited;

void dfs(int v) {
  if (visited[v])
    return;
  black[v] = 1;
  visited[v] = 1;
  for (const auto next : adj[v]) {
    if (!visited[next] && !black[next])
      dfs(next);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  adj = vector<vector<int>>(n);
  visited = vector<bool>(n);
  black = vector<bool>(n);

  rep(mi, m) {
    int x, y;
    cin >> x >> y;
    adj[y - 1].push_back(x - 1);
  }

  int q;
  cin >> q;
  rep(qi, q) {
    int i, v;
    cin >> i >> v;

    if (i == 1) {
      if (!visited[v - 1] || !black[v - 1])
        dfs(v - 1);
    } else {
      cout << (black[v - 1] ? "Yes\n" : "No\n");
    }
  }

  return 0;
}
