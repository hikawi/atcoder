#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
int main() {
  using namespace std;
  int n;
  cin >> n;
  vector<int> A(n + 1);
  for (int i = 0; i < n; i++)
    cin >> A[i + 1];

  vector<int> dp(n + 1);
  dp[1] = 0;
  dp[2] = abs(A[2] - A[1]);
  for (int i = 3; i <= n; i++) {
    int a = dp[i - 2] + abs(A[i - 2] - A[i]);
    int b = dp[i - 1] + abs(A[i - 1] - A[i]);
    dp[i] = min(a, b);
  }

  cout << dp[n] << endl;
}
