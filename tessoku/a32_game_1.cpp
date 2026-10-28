#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;

  vector<int> dp(n + 1, 1);
  for (int i = 0; i < min(a, b); i++)
    dp[i] = -1;
  for (int i = min(a, b); i <= n; i++) {
    int cur = -1;
    if (i - a >= 0 && dp[i - a] == -1)
      cur = 1;
    if (i - b >= 0 && dp[i - b] == -1)
      cur = 1;
    dp[i] = cur;
  }

  if (dp[n] < 0)
    cout << "Second\n";
  else
    cout << "First\n";
}
