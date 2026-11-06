#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main() {
  using namespace std;
  string s, t;
  cin >> s >> t;

  vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));
  for (int i = 0; i <= s.size(); i++) {
    for (int j = 0; j <= t.size(); j++) {
      int a = 0, b = 0, c = 0;
      if (i > 0)
        a = dp[i - 1][j];
      if (j > 0)
        b = dp[i][j - 1];
      if (i > 0 && j > 0 && s[i - 1] == t[j - 1])
        c = dp[i - 1][j - 1] + 1;
      dp[i][j] = max(a, max(b, c));
    }
  }

  cout << dp[s.size()][t.size()] << endl;
}
