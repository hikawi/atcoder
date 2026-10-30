#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  cout << setprecision(13);
  int n;
  cin >> n;
  vector<double> P(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> P[i];

  // dp[i][j] := from 1->i coins with j tails, what is the probability?
  vector<vector<double>> dp(n + 1, vector<double>(n + 1));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      if (j > 0 && dp[i - 1][j - 1])
        dp[i][j] = (dp[i - 1][j - 1] * (1 - P[i])) + (dp[i - 1][j] * P[i]);
      else
        dp[i][j] = dp[i - 1][j] * P[i];
    }
  }

  double ans = 0;
  for (int i = 0; i <= n / 2; i++)
    ans += dp[n][i];
  cout << ans << endl;
}
