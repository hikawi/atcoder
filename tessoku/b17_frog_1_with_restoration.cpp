#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
int main() {
  using namespace std;
  int n;
  cin >> n;
  vector<int> P(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> P[i];

  vector<int> dp(n + 1);
  dp[2] = abs(P[2] - P[1]);
  for (int i = 3; i <= n; i++)
    dp[i] = min(dp[i - 1] + abs(P[i] - P[i - 1]), dp[i - 2] + abs(P[i] - P[i - 2]));

  vector<int> path;
  for (int i = n; i >= 1;) {
    path.push_back(i);
    int step = 0;
    if (i <= 2) {
      step = 1;
    } else {
      // check for two ways, one hop or double hop
      int dp1 = abs(P[i] - P[i - 1]) + dp[i - 1];
      if (dp1 == dp[i])
        step = 1;
      else
        step = 2;
    }

    i -= step;
  }

  cout << path.size() << "\n";
  for (auto it = path.rbegin(); it != path.rend(); it++)
    cout << *it << " ";
  cout << endl;
}
