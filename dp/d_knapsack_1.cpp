#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  ll n, w;
  cin >> n >> w;
  vector<ll> W(n + 1), V(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> W[i] >> V[i];

  // dp[i][j] := from 1->i items, to sum to j weight, how much value?
  vector<vector<ll>> dp(n + 1, vector<ll>(100009));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= w; j++) {
      ll a = dp[i - 1][j];
      ll b = j - W[i] >= 0 ? dp[i - 1][j - W[i]] + V[i] : 0;
      dp[i][j] = max(a, b);
    }
  }

  ll ans = 0;
  for (int i = 0; i <= w; i++)
    ans = max(ans, dp[n][i]);
  cout << ans << endl;
}
