#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++)
    cin >> A[i];

  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  for (int i = 0; i < n; i++)
    dp[n][i + 1] = A[i];

  int taro = n % 2 == 0;
  for (int i = n; i > 1; i--) {
    for (int j = 1; j < i; j++) {
      if (taro)
        dp[i - 1][j] = max(dp[i][j], dp[i][j + 1]);
      else
        dp[i - 1][j] = min(dp[i][j], dp[i][j + 1]);
    }
    taro = !taro;
  }

  cout << dp[1][1] << endl;
}
