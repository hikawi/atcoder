#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (n); i++)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];

  // pick a subsequence of length m from A that has the max sum(i * S_i) where S_i is an element of A
  // call dp[i][j], means that, for the ith element of the subsequence, we choose A_j

  vector<vector<ll>> dp(m + 1);
  vector<ll> premax(n + 1);
  rep(i, m + 1) dp[i].resize(n + 1);

  // we want max of dp[m].
  // dp[i][j] = max(dp[i-1][a < j]) + i * A_j
  for (int i = 1; i <= m; i++) {
    // for (const auto l : premax)
    //   if (l == LONG_LONG_MIN)
    //     cout << "-i,";
    //   else
    //     cout << l << ",";
    // cout << endl;

    for (int j = i; j <= n; j++) {
      dp[i][j] = premax[j - 1] + i * A[j - 1];
    }

    // recalc premax
    fill(premax.begin(), premax.end(), LONG_LONG_MIN);
    for (int j = i; j <= n; j++) {
      premax[j] = max(premax[j - 1], dp[i][j]);
    }
  }

  // cout << "-------------------------\n";

  // for (const auto &v : dp) {
  //   for (const auto &l : v)
  //     cout << l << " ";
  //   cout << endl;
  // }

  cout << *max_element(dp[m].begin() + m, dp[m].end()) << endl;

  return 0;
}
