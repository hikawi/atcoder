#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> P(n), T(n);
  for (int i = 0; i < n; i++)
    cin >> P[i] >> T[i];

  // dp[i][j] := i番目のブロックからj番目のブロックまで最大得点
  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  dp[1][n] = 0;
  for (int l = 1; l <= n; l++) {
    for (int r = n; r >= l; r--) {
      int reml = l <= 1 ? 0 : dp[l - 1][r] + (l <= P[l - 2] && P[l - 2] <= r ? T[l - 2] : 0);
      int remr = r >= n ? 0 : dp[l][r + 1] + (l <= P[r] && P[r] <= r ? T[r] : 0);
      dp[l][r] = max(reml, remr);
    }
  }

  int m = 0;
  for (int i = 1; i <= n; i++)
    m = max(m, dp[i][i]);
  cout << m << endl;
}
