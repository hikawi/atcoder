#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n;
  cin >> n;
  vector<ll> A(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> A[i];

  vector<ll> dp(n + 1, 1ll << 60);
  dp[1] = 0;
  for (int i = 1; i < n; i++) {
    dp[i + 1] = min(dp[i + 1], dp[i] + abs(A[i + 1] - A[i]));
    if (i + 2 <= n)
      dp[i + 2] = min(dp[i + 2], dp[i] + abs(A[i + 2] - A[i]));
  }

  cout << dp[n] << endl;
}
