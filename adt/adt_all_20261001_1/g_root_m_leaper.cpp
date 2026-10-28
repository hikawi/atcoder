#include <cmath>
#include <ios>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> G(n, vector<int>(n, -1));

  // find all combinations of (a,b) that a^2+b^2=m
  vector<pair<int, int>> dirs;
  for (int a = 0; a <= m; a++) {
    int b = sqrt(m - a * a);
    if (b * b + a * a == m)
      dirs.emplace_back(a, b);
  }

  queue<tuple<int, int, int>> q; // (x, y, cost)
  q.emplace(0, 0, 0);
  G[0][0] = 0;
  while (!q.empty()) {
    auto [x, y, cost] = q.front();
    q.pop();
    for (auto &[dx, dy] : dirs) {
      int mulx[4] = {1, -1, 1, -1};
      int muly[4] = {1, 1, -1, -1};
      for (int i = 0; i < 4; i++) {
        int nx = x + dx * mulx[i], ny = y + dy * muly[i];
        if (nx < 0 || ny < 0 || nx >= n || ny >= n || G[ny][nx] >= 0) {
          continue;
        }
        G[ny][nx] = cost + 1;
        q.emplace(ny, nx, cost + 1);
      }
    }
  }

  for (auto &v : G) {
    for (auto a : v)
      cout << a << " ";
    cout << "\n";
  }

  return 0;
}
