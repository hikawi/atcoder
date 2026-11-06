#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> H(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> H[i];

  vector<int> dp(n + 1, 1 << 30);
  dp[1] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= i + k && j <= n; j++) {
      dp[j] = min(dp[j], dp[i] + abs(H[j] - H[i]));
    }
  }

  cout << dp[n] << endl;
}
