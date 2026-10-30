#include <iostream>
#include <string>
#include <vector>
using namespace std;
int m = 1000000007;
int main() {
  int h, w;
  cin >> h >> w;
  vector<string> G(h);
  for (int i = 0; i < h; i++)
    cin >> G[i];

  vector<vector<int>> dp(h, vector<int>(w, 0));
  dp[h - 1][w - 1] = 1;
  for (int y = h - 1; y >= 0; y--) {
    for (int x = w - 1; x >= 0; x--) {
      if (G[y][x] == '#')
        continue;
      int a = x >= w - 1 ? 0 : dp[y][x + 1];
      int b = y >= h - 1 ? 0 : dp[y + 1][x];
      dp[y][x] = (dp[y][x] + a + b) % m;
    }
  }

  cout << dp[0][0] << endl;
}
