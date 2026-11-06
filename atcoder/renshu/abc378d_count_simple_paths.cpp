#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int h, w, k;
ll c = 0;
vector<string> M;
vector<int> seen;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int x, int y, int cost = 0) {
  if (x < 0 || y < 0 || x >= w || y >= h || M[y][x] == '#' || seen[y * w + x])
    return;
  if (cost >= k) {
    c++;
    return;
  }

  seen[y * w + x] = 1;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i], ny = y + dy[i];
    dfs(nx, ny, cost + 1);
  }
  seen[y * w + x] = 0;
}

int main() {
  cin >> h >> w >> k;
  M = vector<string>(h);
  seen = vector<int>(h * w);
  for (int i = 0; i < h; i++)
    cin >> M[i];
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (M[i][j] == '.')
        dfs(j, i);
    }
  }
  cout << c << endl;
}
