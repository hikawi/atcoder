#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
ll h, w, t;
ll sx, sy, gx, gy;
vector<char> grid;
unordered_map<int, int> candiesbm; // candy at cell -> candy bitmask

int encode(int x, int y) {
  return y * w + x;
}

void decode(int id, int &x, int &y) {
  x = id % w;
  y = id / w;
}

ll encodevisited(int x, int y, int candies) {
  return ((y * w) + x) * candiesbm.size() + __builtin_popcount(candies);
}

void bfs() {
  queue<tuple<int, int, int>> q; // (cell, candies, cost)
  q.emplace(encode(sx, sy), 0, 0);
  unordered_set<ll> visited;

  int score = -1;
  while (!q.empty()) {
    const auto &[cell, candies, cost] = q.front();
    q.pop();
    int x, y;
    decode(cell, x, y);

    if (cost > t) {
      continue;
    }
    if (x == gx && y == gy) {
      score = max(score, __builtin_popcount(candies));
      continue;
    }

    // cout << x << "," << y << "," << __builtin_popcount(candies) << "\n";
    visited.insert(encodevisited(x, y, candies));

    rep(i, 4) {
      auto nx = x + dx[i], ny = y + dy[i];
      auto id = encode(nx, ny);
      if (nx < 0 || ny < 0 || nx >= w || ny >= h || grid[id] == '#')
        continue;

      int ncandies = candies;
      if (grid[id] == 'o')
        ncandies |= candiesbm[id];
      if (visited.contains(encodevisited(nx, ny, ncandies)))
        continue;
      q.emplace(id, ncandies, cost + 1);
    }
  }

  cout << score << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> h >> w >> t;
  grid = vector<char>(h * w);
  rep(i, h) {
    rep(j, w) {
      int id = encode(j, i);
      cin >> grid[id];
      switch (grid[id]) {
      case 'S':
        sx = j;
        sy = i;
        break;
      case 'G':
        gx = j;
        gy = i;
        break;
      case 'o':
        int c = candiesbm.size();
        candiesbm[id] = 1 << c;
        break;
      }
    }
  }

  bfs();

  return 0;
}
