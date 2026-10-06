#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int h, w;
  cin >> h >> w;
  vector<vector<char>> grid(h);
  vector<int> lines(w);
  rep(i, h) {
    grid[i].reserve(w);
    rep(j, w) {
      cin >> grid[i][j];
      lines[j] += (grid[i][j] == '#');
    }
  }

  rep(i, w) {
    cout << lines[i] << (i == w - 1 ? "\n" : " ");
  }

  return 0;
}
