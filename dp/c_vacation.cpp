#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> A(n + 1), B(n + 1), C(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> A[i] >> B[i] >> C[i];

  // dp[i][j] := day i, pick j (j=1 -> A, j=2 -> B, j=3 -> C)
  vector<vector<int>> dp(n + 1, vector<int>(4));
  dp[1][1] = A[1];
  dp[1][2] = B[1];
  dp[1][3] = C[1];

  for (int i = 2; i <= n; i++) {
    int a = dp[i - 1][1];
    int b = dp[i - 1][2];
    int c = dp[i - 1][3];

    dp[i][1] = max(b, c) + A[i];
    dp[i][2] = max(a, c) + B[i];
    dp[i][3] = max(a, b) + C[i];
  }

  cout << max(dp[n][1], max(dp[n][2], dp[n][3])) << endl;
}
