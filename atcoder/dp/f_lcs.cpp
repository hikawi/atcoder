#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      // at Si != Tj, we just move?
      dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
      }
    }
  }

  string ans;
  int i = n, j = m;
  while (i > 0 && j > 0) {
    if (dp[i - 1][j] == dp[i][j] - 1 && dp[i][j - 1] == dp[i][j] - 1 && dp[i - 1][j - 1] == dp[i][j] - 1) {
      // last
      i--;
      j--;
      ans += s[i];
      continue;
    }

    if (dp[i - 1][j] == dp[i][j]) {
      i--;
      continue;
    }

    j--;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}
