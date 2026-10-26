#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
int main() {
  using namespace std;
  int n;
  cin >> n;
  vector<int> A(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> A[i];

  vector<int> dp(n + 1);
  dp[1] = 0;
  dp[2] = abs(A[2] - A[1]);
  for (int i = 3; i <= n; i++) {
    dp[i] = min(dp[i - 1] + abs(A[i] - A[i - 1]), dp[i - 2] + abs(A[i] - A[i - 2]));
  }
  cout << dp[n] << endl;
}
