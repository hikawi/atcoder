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

  // dp[i][j] from 1->i totaling up to V=j in value, what is the current weight?
  vector<vector<ll>> dp(n + 1, vector<ll>(100009, 1ll << 60));
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= 100000; j++) {
      ll a = dp[i - 1][j];                                      // don't pick up A_i
      ll b = j < V[i] ? 1ll << 60 : dp[i - 1][j - V[i]] + W[i]; // pick up A_i
      dp[i][j] = min(a, b);
    }
  }

  ll maxv = 0;
  for (int i = 0; i <= 100000; i++) {
    if (dp[n][i] <= w)
      maxv = i;
  }
  cout << maxv << endl;
}
