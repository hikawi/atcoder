#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  using namespace std;
  int n, w;
  cin >> n >> w;
  vector<int> W(n + 1), V(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> W[i] >> V[i];

  // dp[i][j] = from 1->i, does the weight sum add up to j.
  // if > 0, its the sum of goods, else its impossible.
  vector<vector<int>> dp(n + 1, vector<int>(w + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= w; j++) {
      int a = dp[i - 1][j];                              // we don't pick this up, so it stays the same.
      int b = j < W[i] ? a : dp[i - 1][j - W[i]] + V[i]; // we do, so the cost adds up.
      dp[i][j] = max(a, b);
    }
  }

  cout << dp[n][w] << endl;
}
