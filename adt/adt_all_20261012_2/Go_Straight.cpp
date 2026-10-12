#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int h, w;
int sx, sy, gx, gy;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char grid[1000][1000]{};

constexpr inline int encode(int x, int y, int dir) {
  return (y * w + x) * 4 + dir;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> h >> w;
  rep(i, h) rep(j, w) {
    cin >> grid[i][j];
    if (grid[i][j] == 'S') {
      sy = i;
      sx = j;
    }
    if (grid[i][j] == 'G') {
      gy = i;
      gx = j;
    }
  }

  queue<int> open;
  vector<bool> visited(h * w * 4);
  vector<int> parents(h * w * 4, -1);

  rep(i, 4) {
    int id = encode(sx, sy, i);
    open.push(id);
    visited[id] = 1;
  }

  int endid = -1;
  while (!open.empty()) {
    const auto id = open.front();
    open.pop();

    int dir = id % 4;
    int x = (id / 4) % w;
    int y = (id / 4) / w;

    if (x == gx && y == gy) {
      endid = id;
      break;
    }

    rep(nd, 4) {
      int nx = x + dx[nd];
      int ny = y + dy[nd];
      int nid = encode(nx, ny, nd);

      if (grid[y][x] == 'o' && nd != dir)
        continue;
      if (grid[y][x] == 'x' && nd == dir)
        continue;
      if (nx < 0 || nx >= w || ny < 0 || ny >= h || grid[ny][nx] == '#')
        continue;
      if (visited[nid])
        continue;

      visited[nid] = 1;
      parents[nid] = id;
      open.push(nid);
    }
  }

  if (endid < 0) {
    cout << "No\n";
    return 0;
  }

  string s;
  string dir = "RLDU";
  while (parents[endid] != -1) {
    s += dir[endid % 4];
    endid = parents[endid];
  }

  cout << "Yes\n";
  for (const char c : s | views::reverse)
    cout << c;
  cout << "\n";

  return 0;
}
