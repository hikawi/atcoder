#include <iostream>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

int h, w;
vector<string> G;
vector<vector<ll>> dp;

int main() {
  cin >> h >> w;
  G = vector<string>(h);
  for (int i = 0; i < h; i++)
    cin >> G[i];

  dp = vector<vector<ll>>(h, vector<ll>(w));
  for (int i = h - 1; i >= 0; i--) {
    for (int j = w - 1; j >= 0; j--) {
      if (i == h - 1 && j == w - 1) {
        dp[i][j] = 1;
        continue;
      }
      if (G[i][j] == '#') {
        dp[i][j] = 0;
        continue;
      }

      ll a = i != h - 1 ? dp[i + 1][j] : 0;
      ll b = j != w - 1 ? dp[i][j + 1] : 0;
      dp[i][j] = a + b;
    }
  }

  cout << dp[0][0] << endl;
}
