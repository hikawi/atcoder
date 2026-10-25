#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n, w;
  cin >> n >> w;
  vector<int> W(n + 1), V(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> W[i] >> V[i];

  // dp[i][j] := from 1->i items, what is the minimum weight needed to sum to value j?
  vector<vector<int>> dp(n + 1, vector<int>(100009, 1 << 30));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= 100000; j++) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);                                  // don't pick up
      dp[i + 1][j + V[i + 1]] = min(dp[i + 1][j + V[i + 1]], dp[i][j] + W[i + 1]); // pickup
    }
  }

  int ans = 0;
  for (int i = 0; i <= 100000; i++)
    if (dp[n][i] <= w)
      ans = i;
  cout << ans << endl;
}
