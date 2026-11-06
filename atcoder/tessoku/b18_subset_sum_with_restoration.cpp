#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  using namespace std;
  int n, s;
  cin >> n >> s;
  vector<int> A(n + 1);
  for (int i = 1; i <= n; i++)
    cin >> A[i];

  vector<vector<int>> dp(n + 1, vector<int>(10009, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= s; j++) {
      int a = dp[i - 1][j];
      int b = j < A[i] ? 0 : dp[i - 1][j - A[i]];
      dp[i][j] = max(a, b);
    }
  }

  if (!dp[n][s]) {
    cout << -1 << endl;
    return 0;
  }

  // 復元
  vector<int> path;
  int curi = n, curs = s;
  while (curs && curi) {
    // can we take A_curi?
    // there is it without needing curi
    if (dp[curi - 1][curs]) {
      curi--;
      continue;
    }

    // we need to take A_curi
    path.push_back(curi);
    curs -= A[curi--];
  }

  cout << path.size() << endl;
  for (auto it = path.rbegin(); it != path.rend(); it++)
    cout << *it << " ";
  cout << endl;
}
