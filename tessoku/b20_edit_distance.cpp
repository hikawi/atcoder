#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
int main() {
  using namespace std;
  string s, t;
  cin >> s >> t;

  // 横T縦S
  vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1));
  for (int i = 0; i <= s.size(); i++) {
    for (int j = 0; j <= t.size(); j++) {
      if (i > 0 && j > 0) {
        int a = dp[i - 1][j] + 1;
        int b = dp[i][j - 1] + 1;
        int c = dp[i - 1][j - 1];
        if (s[i - 1] != t[j - 1])
          c++;
        dp[i][j] = min({a, b, c});
      } else if (i > 0) {
        dp[i][j] = dp[i - 1][j] + 1;
      } else if (j > 0) {
        dp[i][j] = dp[i][j - 1] + 1;
      }
    }
  }

  // for (const auto &r : dp) {
  //   for (auto c : r)
  //     cout << c << " ";
  //   cout << endl;
  // }

  cout << dp[s.size()][t.size()] << endl;
}
