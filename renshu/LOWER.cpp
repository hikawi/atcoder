#include <cctype>
#include <iostream>
#include <ranges>
#include <string>
#include <utility>
#include <vector>
using namespace std;
int main() {
  int n, q;
  string s;
  cin >> n >> s >> q;

  string re(n, 0);
  vector<pair<int, char>> queries;
  queries.reserve(q);
  while (q--) {
    int t, x;
    char c;
    cin >> t >> x >> c;
    switch (t) {
    case 1:
      queries.emplace_back(x - 1, c);
      break;
    case 2:
      queries.emplace_back(0, 0);
      break;
    case 3:
      queries.emplace_back(1, 0);
      break;
    }
  }

  int glob = -1;
  for (const auto &[t, c] : queries | std::views::reverse) {
    if (c > 0) {
      if (re[t])
        continue;
      re[t] = glob == -1 ? c : glob == 0 ? tolower(c) : toupper(c);
      continue;
    }

    if (glob < 0)
      glob = t;
  }

  string ans(n, 0);
  for (int i = 0; i < n; i++) {
    if (re[i]) {
      ans[i] = re[i];
      continue;
    }

    switch (glob) {
    case -1:
      // そのまま
      ans[i] = s[i];
      break;
    case 0:
      // 小文字
      ans[i] = tolower(s[i]);
      break;
    default:
      // 大文字
      ans[i] = toupper(s[i]);
      break;
    }
  }
  cout << ans << endl;
}
