#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> A(n + 1), B(n + 1);
  for (int i = 2; i <= n; i++)
    cin >> A[i];
  for (int i = 3; i <= n; i++)
    cin >> B[i];

  vector<int> dp(n + 1, 1 << 30);
  dp[1] = 0;
  for (int i = 1; i <= n - 1; i++) {
    dp[i + 1] = min(dp[i + 1], dp[i] + A[i + 1]);
    if (i < n - 1)
      dp[i + 2] = min(dp[i + 2], dp[i] + B[i + 2]);
  }
  cout << dp[n] << endl;
}
