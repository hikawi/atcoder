#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  for (int i = 1; i <= n - 1; i++)
    cin >> A[i];
  for (int i = 1; i <= n - 1; i++)
    cin >> B[i];

  vector<int> dp(n + 1, -(1 << 30));
  dp[1] = 0;
  for (int i = 1; i <= n - 1; i++) {
    dp[A[i]] = max(dp[i] + 100, dp[A[i]]);
    dp[B[i]] = max(dp[i] + 150, dp[B[i]]);
  }

  cout << dp[n] << endl;
}
