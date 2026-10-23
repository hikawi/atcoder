#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> coupons(m + 1);
  for (int i = 0; i < m; i++) {
    int a = 0;
    for (int j = 0; j < n; j++) {
      int b;
      cin >> b;
      a = (a << 1) | (b & 1);
    }
    coupons[i + 1] = a;
  }

  // dp[i][j] := from 1->i coupons, how many are needed to use satisfy set of J items?
  vector<vector<int>> dp(m + 1, vector<int>(1 << n, m + 1));
  dp[0][0] = 0;
  for (int i = 1; i <= m; i++)
    dp[i][coupons[i]] = 1;

  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < 1 << n; j++) {
      int t = j | coupons[i];
      int a = dp[i - 1][j] + 1;
      int b = dp[i][t];
      int c = dp[i - 1][t];
      dp[i][j] = min(dp[i - 1][j], dp[i][j]);
      dp[i][t] = min(a, min(b, c));
    }
  }

  int ans = dp[m][(1 << n) - 1];
  cout << (ans <= m ? ans : -1) << endl;
}
