#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  using namespace std;
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  for (int i = 0; i < n; i++)
    cin >> A[i];

  // dp[i][j] = does selecting A_i here sum to j?
  // so dp[0][0] = 1, but any dp[0][x] = 0
  // dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - A_i])
  vector<vector<int>> dp(n + 1, vector<int>(10009, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= k; j++) {
      int a = dp[i - 1][j]; // its already equal j from last step?
      int b = j - A[i - 1] >= 0 ? dp[i - 1][j - A[i - 1]]
                                : 0; // or its j-Ai from last step, so adding this card would make it j
      dp[i][j] = max(a, b);
    }
  }

  int flag = 0;
  for (int i = 0; i <= n; i++)
    if (dp[i][k])
      flag = 1;
  if (flag)
    cout << "Yes\n";
  else
    cout << "No\n";
}
