#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> dp;

int search(int cur) {
  if (dp[cur] >= 0)
    return dp[cur];
  if (adj[cur].empty()) {
    dp[cur] = 0;
    return 0;
  }

  int ans = 0;
  for (auto next : adj[cur])
    ans = max(ans, search(next));
  dp[cur] = ans + 1;
  return ans + 1;
}

int main() {
  int n, m;
  cin >> n >> m;
  adj = vector<vector<int>>(n + 1);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
  }

  dp = vector<int>(n + 1, -1);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans = max(ans, search(i));
  cout << ans << endl;
}
