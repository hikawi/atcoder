#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using pii = pair<int, int>;
double inf = INFINITY;
int main() {
  cout << setprecision(13);
  int n;
  cin >> n;
  vector<pii> C(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> C[i].first >> C[i].second;

  auto dist = [&](int a, int b) {
    auto [ax, ay] = C[a];
    auto [bx, by] = C[b];
    return sqrt(pow(bx - ax, 2) + pow(by - ay, 2));
  };

  // dp[cities visited][current city]
  vector<vector<double>> dp(1 << n, vector<double>(n + 1, inf));
  dp[0][0] = 0;
  dp[1][1] = 0;

  for (int i = 0; i < 1 << n; i++) {
    for (int j = 1; j <= n; j++) {
      int t = 1 << (j - 1);
      if (!(i & t) || dp[i][j] == inf)
        continue;

      // find next nodes
      // it must be unvisited
      for (int k = 1; k <= n; k++) {
        int kt = 1 << (k - 1);
        if (i & kt) // visited
          continue;
        // not visited
        double a = dp[i][j] + dist(j, k);
        double b = dp[i | kt][k];
        dp[i | kt][k] = min(a, b);
      }
    }
  }

  int mask = (1 << n) - 1;
  double ans = inf;
  for (int j = 1; j <= n; j++) {
    if (dp[mask][j] != inf)
      ans = min(ans, dp[mask][j] + dist(j, 1));
  }

  cout << ans << endl;
}
